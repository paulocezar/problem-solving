#include <map> 
#include <set> 
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

#define TI(X) x::iterator
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

struct mapa_t{
       double xc, yc;
       int id, area;
	   mapa_t(){ xc = yc = 0.0; id = 0; area = 0; }
       mapa_t( double a, double b, int c ) : xc(a), yc(b), id(c) {}
       mapa_t( int a1, int b1, int a2, int b2, int c ){
			   area = ABS(b1-b2) * ABS(a1-a2);
               xc = ((a1+a2)*1.0)/2.0;
               yc = ((b1+b2)*1.0)/2.0;
               id = c;
       }
       bool operator < ( const mapa_t &a ) const{
            if( id != a.id ) return id < a.id;
            return xc < a.xc;
       }
};

double dist( double x1, double y1, double x2, double y2 ){
       return SQR(x2-x1) + SQR(y2-y1);
}

int main(){
    
    ios::sync_with_stdio( false );
    
    int M, R, ct = 0;
    int i, x1, x2, y1, y2;
    int ans;
    int area;
    double dans;
    
    map< int, map< int, map< int, map< int, mapa_t > > > >::iterator x2it;
    map< int, map< int, map< int, mapa_t > > >::iterator x1it;
    map< int, map< int, mapa_t > >::iterator y2it;
    map< int, mapa_t >::iterator y1it;
    
    cin >> M >> R;
    while( M+R != 0 ){
           if( ct ) cout << "\n";
           ct++;
           
           map< int, map< int, map< int, map< int, mapa_t > > > > mapas;
    
           REP( a, M ){
                cin >> i >> x1 >> y1 >> x2 >> y2;
                if( mapas[x2][x1][y2].find( y1 ) == mapas[x2][x1][y2].end() )
                    mapas[x2][x1][y2][y1] = mapa_t( x1, y1, x2, y2, i );
                else if( mapas[x2][x1][y2][y1].id > i )
                     mapas[x2][x1][y2][y1].id = i;
           }
           
           cout << "Teste " << ct << "\n";
           REP( a, R ){
                cin >> x1 >> y1;
                ans = INT_MAX;
                area = INT_MAX;
                dans = INT_MAX;
                
                for( x2it = mapas.lower_bound(x1); x2it != mapas.end(); x2it++ ){
                     for( x1it = x2it->second.begin(); x1it != x2it->second.end() && x1it->first <= x1; x1it++ ){
                          for( y2it = x1it->second.lower_bound(y1); y2it != x1it->second.end(); y2it++ ){
                             for( y1it = y2it->second.begin(); y1it != y2it->second.end() && y1it->first <= y1; y1it++ ){
                                 
                                         if( y1it->second.area == area ){
                                             double ndist = dist( x1, y1, y1it->second.xc,  y1it->second.yc );
                                             if( (ndist < dans) || (ndist==dans &&  y1it->second.id < ans) ){
                                                 ans =  y1it->second.id;
                                                 dans = ndist;
                                             }
                                         }
                                         if(  y1it->second.area < area ){
                                             ans = y1it->second.id;
                                             area = y1it->second.area;
                                             dans =  dist( x1, y1,  y1it->second.xc,  y1it->second.yc );
                                         }
                                
                               }
                          }
                     }
                }
                if( ans == INT_MAX ) ans = 0;
                cout << ans << "\n";
           }
           cin >> M >> R;
    }
    
    return 0;    
}
