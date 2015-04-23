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
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXM 51
#define MAXN (3*MAXM+2)

int xa[MAXM], ya[MAXM], xb[MAXM], yb[MAXM];
int x[MAXN], y[MAXN];

vector< int > gr[MAXN];
double dist[MAXN][MAXN];

double d[MAXN][MAXM];

/*int det(int x1, int y1, int x2, int y2, int x3, int y3) {
    return x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
}*/

struct pt{
	double x, y;
	
	pt(double x = 0, double y = 0) : x(x), y(y) {}
	
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

int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

double cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
double signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c))/2.0; }

bool in_box(pt a, pt b, pt c){
	return ( cmp(c.x, min(a.x, b.x)) >= 0 && cmp(c.x, max(a.x, b.x)) <= 0
		&&   cmp(c.y, min(a.y, b.y)) >= 0 && cmp(c.y, max(a.y, b.y)) <= 0 );
}


//interseccao entre as retas a->b e c->d e guarda em inter
bool intersect(pt a, pt b, pt c, pt d, pt& inter){
	double det = cross(b-a, d-c);
	if(fabs(det) < EPS){
		if( fabs(signed_area(a, b, c) ) < EPS){
			inter = pt(INF, INF); 
			return true; //retas coincidentes
		}
		return false; //retas paralelas
	}
	//retas concorrentes
	double ua = ( cross(d-c, a-c) )/det; //parametros (pode ser importante)
//  double ub = ( cross(b-a, a-c) )/det;
	inter = a + (b-a)*ua;
	return true;
}

//testa se exsite interseccao entre os dois segmentos
bool intersect_seg(pt a, pt b, pt c, pt d ){
	pt inter;
	if( !intersect(a, b, c, d, inter) ) return false; //segmentos paralelos
	
	if( inter == pt(INF, INF) )
		return in_box(a, b, min(c, d)) || in_box(c, d, min(a, b)); //segmentos sobrepostos
		
	return in_box(a, b, inter) && in_box(c, d, inter); //segmentos concorrentes
}


bool intersect( int i, int j, int k ){
	return intersect_seg( pt(x[i],y[i]), pt(x[j],y[j]), pt(xa[k],ya[k]), pt(xb[k],yb[k]) );
	/*int p1 = det(x[i], y[i], x[j], y[j], xa[k], ya[k]);
    int p2 = det(x[i], y[i], x[j], y[j], xb[k], yb[k]);
    int p3 = det(xa[k], ya[k], xb[k], yb[k], x[i], y[i]);
    int p4 = det(xa[k], ya[k], xb[k], yb[k], x[j], y[j]);
 
    if( p1 == 0 || p2 == 0 || p3 == 0 || p4 == 0 ) return false;
 
    int s1 = p1 / ABS(p1);
    int s2 = p2 / ABS(p2);
    int s3 = p3 / ABS(p3);
    int s4 = p4 / ABS(p4);
    return (s1 != s2) && (s3 != s4); */
}

struct state{
	int u, t;
	double dd;
	state( int uu = 0, int tt = 0, double ddd = 0.0 ) : u(uu), t(tt), dd(ddd) {}
	bool operator < (const state& s ) const {
		if( fabs(dd-s.dd) > EPS ) return (CMP(s.dd,dd) == -1);
		if( t != s.t ) return t > s.t;
		return u < s.u;
	}
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int T, M, C, v;
		
	while( cin >> T >> M >> C ){
		
		v = 2;
		REP( i, M ){
			cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
			x[v] = xa[i]; y[v] = ya[i]; v++;
			x[v] = xb[i]; y[v] = yb[i]; v++;
		}
		
		REP( i, C ) cin >> x[v+i] >> y[v+i];
		cin >> x[0] >> y[0] >> x[1] >> y[1];
		REP( i, v+C ) gr[i].clear();
		
		REP( i, v+C ) FOR( j, i+1, v+C-1 ){
			bool ok = true;
			REP( k, M ) if( intersect( i, j, k ) ){
				if( x[i] == xa[k] && y[i] == ya[k] ) continue;
				if( x[i] == xb[k] && y[i] == yb[k] ) continue;
				
				if( x[j] == xa[k] && y[j] == ya[k] ) continue;
				if( x[j] == xb[k] && y[j] == yb[k] ) continue;
				ok = false; break;
			}
			if( ok ){
				gr[i].PB( j );
				gr[j].PB( i );
				//cout << "cria " << i << " " << j << endl;
				dist[i][j] = dist[j][i] = sqrt( SQR(x[i]-x[j]) + SQR(y[i]-y[j]) );
			}
		}
		
		REP( i, v+C ) REP( j, T+1 ) d[i][j] = 2e9;
		d[0][0] = 0.0;
		
		priority_queue< state > q; q.push( state(0,0,0) );
		while( !q.empty() ){
			int u = q.top().u;
			int t = q.top().t;
			double dis = q.top().dd; q.pop();
			//cout << u << " " << t << " " << dis << endl;
			if( fabs(dis - d[u][t]) > EPS ) continue;
			if( u == 1 ){ cout << fixed << setprecision(1) << dis << "\n"; break; }
			REP( i, SIZE(gr[u]) ){
				int w = gr[u][i];
				if( dis+dist[u][w] < d[w][t] ){
					d[w][t] = dis+dist[u][w];
					q.push( state(w,t,d[w][t]) );
				}
				if( (u >= v) && (w >= v) && t+1 <= T ){
					if( dis < d[w][t+1] ){
						d[w][t+1] = dis;
						q.push( state(w,t+1,d[w][t+1]) );
					}
				}
			}
		}
		
	}
	
	return 0;
}













