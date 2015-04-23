#include <map>
#include <set>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof( (X).begin() )
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for( int i = a; i <= b; ++i)
#define RFOR(i, b, a) for( int i = b; i >= a; --i)
#define REP(i, N) for( int i = 0; i < N; ++i)
#define RREP(i, N) for( int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair
template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int N;

struct st
{
	int produz, anula, sai;
	
	st() : produz(0), anula(0), sai(0) {}
} vet[51];

list<int> g[51];
bool visited[51];

void dfs(int v, int chegou)
{
	visited[v] = true;
	
	for (list<int>::iterator it = g[v].begin(); it != g[v].end(); ++it) {
		if (!visited[*it]) {
			vet[*it].sai |= (chegou | vet[*it].produz) & vet[*it].anula;
			dfs(*it, vet[*it].sai);
		}
	}
	
	visited[v] = false;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	
	string prod, anula;
	int x, y;
	int sz;
	while (t--) {
		cin >> N;
		
		for (int i = 0; i < N; ++i) {
			g[i].clear();
			vet[i].produz = vet[i].sai = 0;
			
			vet[i].anula = (1 << 31) - 1;
			
			cin >> prod >> anula;
			sz = prod.size();
			
			if (prod != ".") for (int j = 0; j < sz; ++j) {
				vet[i].produz |= (1 << (prod[j] - 'A'));
			}
			
			sz = anula.size();
			if (anula != ".") for (int j = 0; j < sz; ++j) {
				vet[i].anula ^= (1 << (anula[j] - 'A'));
			}
		}
		
		cin >> x >> y;
		
		while (x != 0 || y != 0) {
			g[x-1].push_back(y-1);
			
			cin >> x >> y;
		}
		
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; ++i) {
			vet[i].sai |= vet[i].produz;
			dfs(i, vet[i].sai);
		}
		
		for (int i = 0; i < N; ++i) {
			cout << ":";
			for (int j = 0; j < 32; ++j) if ((1 << j) & vet[i].sai) cout << char(j + 'A');
			cout << ":\n";
		}
		
		if (t) cout << "\n";
	}
	
	return 0;
}



















