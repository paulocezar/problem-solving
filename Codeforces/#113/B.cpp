#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const double pi = acos(-1.0);

struct pt;
typedef pair<pt, pt> line;
typedef vector<pt> polygon;

int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

struct pt{
	double x, y;
	
	pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	
	double length() { return sqrt(x*x + y*y); }
	double length2() { return x*x + y*y; }
	
	pt normalize(){
		return (*this)/length();
	}
	
	pt operator - (pt p){ return pt(x - p.x, y - p.y); }
	pt operator + (pt p){ return pt(x + p.x, y + p.y); }
	pt operator * (double k){ return pt(x * k, y * k); }
	pt operator / (double k){ return pt(x / k, y / k); }
	bool operator < (const pt& p) const{
		if(fabs( x - p.x ) >= EPS) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p){
		return ( fabs(x - p.x) < EPS && fabs(y - p.y) < EPS );
	}
};

double dist(pt a, pt b){ return (a - b).length(); }
double dot(pt a, pt b){ return a.x*b.x + a.y*b.y; }
double cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
double signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c))/2.0; }

int side_sign(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)); }
bool cw(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)) > 0; }
bool ccw(pt a, pt b, pt c){	return cmp(signed_area(a, b, c)) < 0; }
bool colinear(pt a, pt b, pt c){ return !cmp(signed_area(a, b, c)); }

bool in_box(pt a, pt b, pt c){
	return ( cmp(c.x, min(a.x, b.x)) >= 0 && cmp(c.x, max(a.x, b.x)) <= 0
		&&   cmp(c.y, min(a.y, b.y)) >= 0 && cmp(c.y, max(a.y, b.y)) <= 0 );
}

double trap(pt& a, pt& b){ return 0.5*(b.x - a.x)*(b.y + a.y); }

double area(polygon& poly){
	double ret = 0.0;
	for(int i = 0; i < SIZE(poly); i++){
		ret += trap(poly[i], poly[(i+1)%SIZE(poly)]);
	}
	return fabs(ret);
}

bool point_and_seg(pt a, pt b, pt c){
	if( !colinear(a, b, c) ) return false;
	return in_box(a, b, c); 
}


bool inside_convex_poly(pt p, polygon& poly){
	int left = 0, right = 0, side;
	
	poly.push_back(poly[0]);
	
	for(int i = 0; i < SIZE(poly)-1; i++)
		if(point_and_seg(poly[i], poly[i+1], p)) return false;
		
	poly.pop_back();
	
	for(int i = 0; i < SIZE(poly); i++){
		if( p == poly[i] ) return false;
		side = side_sign(p, poly[i], poly[(i+1)%SIZE(poly)]);
		if(side < 0) right++;
		if(side > 0) left++;
	}
	return !(left && right);
}

pt refer;
bool cmp_angle(pt p1, pt p2){
	double det = signed_area(refer, p1, p2); 
	if(fabs(det) < EPS){
		return (dist(refer, p1) >= dist(refer, p2));
	}
	return (det > EPS);
}

void convex_hull(polygon in, polygon& hull){
	hull.clear();
	
	if(in.size() < 3){ hull = in; return; }
	
	int pos = 0;
	for(int i = 1; i < SIZE(in); i++) if(in[i] < in[pos]) pos = i;
	swap(in[0], in[pos]);
	refer = in[0];
	
	sort(in.begin() + 1, in.end(), cmp_angle);
	in.resize(unique(in.begin(), in.end()) - in.begin());
	
	hull.push_back(in[0]); hull.push_back(in[1]);
	
	in.push_back(in[0]);
	for(int i = 2; i < SIZE(in); ){
		if(hull.size() > 2 && side_sign(hull[SIZE(hull) - 2], hull[SIZE(hull) - 1], in[i]) <= 0){
			hull.pop_back();
		}
		else hull.push_back(in[i++]);
	}
	
	hull.pop_back();
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n, m, x, y;
	
	polygon A, BB;
	cin >> n;
	REP( i, n ){
		cin >> x >> y;
		A.PB( pt(x,y) );
	}
	cin >> m;
	REP( i, m ){
		cin >> x >> y;
		BB.PB( pt(x, y) );
	}
	//convex_hull(BB,B);
	
	REP( i, SIZE(BB) ){
		if( !inside_convex_poly(BB[i],A) ){
			cout << "NO\n";
			goto hell;
		}
	}
	cout << "YES\n";
hell:
		
	return 0;
}











































