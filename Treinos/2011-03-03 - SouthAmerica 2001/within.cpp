#include <map> 
#include <set> 
#include <list>
#include <cmath> 
#include <queue>
#include <vector> 
#include <string> 
#include <cstdio>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define poligon vector<point>
const double PI = 2.0*acos(0.0);
const double EPS = 1e-9;

struct point{
       double x, y;
       point(){ x = y = 0; }
       point( double a, double b ) : x(a), y(b) {}
       point operator -( point a ){
             point r;
             r.x = x-a.x; r.y = y-a.y;
             return r;
       }
       point operator +( point a ){
             point r;
             r.x = x+a.x; r.y = y+a.y;
             return r;
       }
       double trap( const point&a, const point& b ){
              return (0.5*(b.x - a.x)*(b.y + a.y));
       }
       double triarea( const point& b, const point& c ){
              return fabs( trap( *this, b ) + trap( b, c ) + trap( c, *this )    );
       }
       bool inseg( const point& p1, const point& p2 ){
            double s = triarea( p1, p2 );
            if( s > EPS ) return false;
            double sg = (x-p1.x)*(x-p2.x);
            if( sg > EPS ) return false;
            sg = (y-p1.y)*(y-p2.y);
            if( sg > EPS ) return false;
            return true;
       }
       void rotate( point p0, point p1, double a, point& r ){
            p1 = p1-p0;
            r.x = cos(a)*p1.x-sin(a)*p1.y;
            r.y = sin(a)*p1.x+cos(a)*p1.y;
            r = r+p0;
       }
       bool inpol( const poligon &p ){
            
            int j, N = SIZE( p )-1;
            REP( i, N ) if( inseg( p[i], p[i+1] ) ) return true;
            
            poligon poly( p );
            REP( i, N ) poly[i] = poly[i]-(*this);
            x = y = 0.0;
            
            double a, yy;
            while( 1 ){
            
                   a = (double)rand()/10000.00;
                   j = 0;
                   REP( i, N ){
                        rotate( *this, poly[i], a, poly[i] );
                        if( fabs(poly[i].x) < EPS ) j = 1;
                   }
            
                   if( j == 0 ){
                       poly[N] = poly[0];
                       j = 0;
                       REP( i, N ) if( poly[i].x*poly[i+1].x < -EPS ){
                            yy = poly[i+1].y-poly[i+1].x*(poly[i].y-poly[i+1].y)/(poly[i].x-poly[i+1].x);
                            if( yy > 0 ) j++;
                       }
                       switch(j%2){
                         case 0: return false;
                         default: return true;
                       }
                   }
            
            }            
            return true;
       }
};


int main(){
    
    ios::sync_with_stdio( false );
    
    int N, M;
	int prob = 1;
	
    cin >> N;
    while( N ){
    	
		cin >> M;
		if( prob != 1 ) cout << "\n";
		cout << "Problem " << prob++ << ":\n";
		
		poligon poly( N+1 );
        REP( i, N ){ 
              cin >> poly[i].x >> poly[i].y;
		}
		poly[N] = poly[0];
    
		point p;
		while( M-- ){
			cin >> p.x >> p.y;
			int ans = p.inpol( poly );
			if( ans ) cout << "Within\n";
			else cout << "Outside\n";
		}
		
    cin >> N;
    }    
    
    return 0;    
}
