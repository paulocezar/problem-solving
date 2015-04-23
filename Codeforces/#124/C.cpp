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

int u[1500], v[1500];
int px[1500], py[1500];
int ans[1500];
int n;

struct pt;
typedef pair<pt, pt> line;
typedef vector<pt> polygon;

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
double dot(pt a, pt b){ return a.x*b.x + a.y*b.y; }
double cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
double signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c))/2.0; }


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

bool ok(){	
	pt intr;
	REP( i, n-1 ) FOR( j, i+1, n-2 ){
		pt a = pt( px[ ans[ u[i] ] ], py[ ans[ u[i] ] ] );
		pt b = pt( px[ ans[ v[i] ] ], py[ ans[ v[i] ] ] );
		pt c = pt( px[ ans[ u[j] ] ], py[ ans[ u[j] ] ] );
		pt d = pt( px[ ans[ v[j] ] ], py[ ans[ v[j] ] ] );
		
		if( intersect_seg( a, b, c, d,intr) ){
			if( inter != a && inter != b && inter != c && inter != d )
			return false;
		}
	return true;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	cin >> n;
	
	REP( i, n-1 ){ cin >> u[i] >> v[i]; u[i]--; v[i]--; }
	REP( i, n ) cin >> px[i] >> py[i];
	REP( i, n ) ans[i] = i;
	random_shuffle(ans,ans+n);
	
	REP( i, n ){
		if( i ) cout << " ";
		cout << ans[i]+1;
	}
	cout << "\n";
	
	return 0;
}

























