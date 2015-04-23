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

//funcao de comparacao
int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

//estrutura que representa um ponto
// ou um vetor dependendo da necessidade
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

////////////////////
// Funcoes basicas
double dist(pt a, pt b){ return (a - b).length(); }
double dist2(pt a, pt b){ return (a - b).length2(); }
double dot(pt a, pt b){ return a.x*b.x + a.y*b.y; }
double cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
double signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c))/2.0; }

//testa se c esta na caixa limitada por a e b
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
bool intersect_seg(pt a, pt b, pt c, pt d, pt& inter){
	if( !intersect(a, b, c, d, inter) ) return false; //segmentos paralelos
	
	if( inter == pt(INF, INF) )
		return in_box(a, b, min(c, d)) || in_box(c, d, min(a, b)); //segmentos sobrepostos
		
	return in_box(a, b, inter) && in_box(c, d, inter); //segmentos concorrentes
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    int t;
    cin >> t;
    while (t--) {
        int s, r, w, p;
        cin >> s >> r >> w >> p;
        
        map<int, vector<int> > points;
        REP(i,s) {
            int x, y; cin >> x >> y;
            points[x].PB(y);
        }
        FORIT(xx,points) sort(ALL(xx->second));
        
        vector< pair<pt, pt> > walls(w);
        REP(i,w) {
            cin >> walls[i].first.x >> walls[i].first.y >> walls[i].second.x >> walls[i].second.y;
        }
        
        REP(i,p) {
            pt product;
            cin >> product.x >> product.y;
            vector< pair<int, int> > ans;
            
            TI(points) lo = points.lower_bound(product.x-r);
            TI(points) hi = points.upper_bound(product.x+r);
            while (lo != hi) {
                pt sensor;
                sensor.x = lo->first;
                
                vector<int>::iterator lb, ub;
                lb = lower_bound(ALL(lo->second), product.y - r);
                ub = upper_bound(ALL(lo->second), product.y + r);
                while (lb != ub) {
                    sensor.y = *lb;
                    
                    double dst = dist2(product,sensor);
                    int nr = r;
                    if (dst > r*r) goto hell;
                    REP(k,w) {
                        pt tmp;
                        if (intersect_seg(product, sensor, walls[k].first, walls[k].second, tmp)) {
                            --nr;
                        }
                    }
                    if(dst <= nr*nr){
                        ans.PB(MP(sensor.x, sensor.y));
                    }
        hell:
                    ++lb;   
                }
                ++lo;
            }
            cout << SIZE(ans);
            REP(x,SIZE(ans)) cout << " (" << ans[x].first << "," << ans[x].second << ")";
            cout << "\n";
        }     
        
        
    }    
    
    return 0;
}
















