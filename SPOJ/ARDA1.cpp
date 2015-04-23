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

string pat[301], txt[2001];
int p[301];

int N1, N2, M1, M2;

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio(false);
	cin >> N1 >> N2;
	REP( i, N1 )
		cin >> pat[i];
	cin >> M1 >> M2;
	REP( i, M1 )
		cin >> txt[i];
// build failure	
	p[0] = p[1] = 0;
	FOR( i, 2, N1 ){
		int j = p[i-1];
		while( pat[i-1] != pat[j] ){
			if( j == 0 ){ j = -1; break; }
			j = p[j];
		}
		p[i] = j+1;
	}
// search
	int from = 0, to = N2-1;
	vector< pair<int,int> > occ;
	while( to < M2 ){
		
		int i = 0;
		int j = 0;
		while( i < M1 ){
			if( txt[i].compare( from, N2, pat[j] ) == 0 ){
				i++;
				j++;
				if( j == N1 ){
					//cout << "achou " << i << " " << from << endl;
					occ.PB( MP(i-N1+1, from+1) );
				}
			} 
			else if( j == 0 ) i++;
			else j = p[j];	
		
		}

		from++, to++;
	}
	if( SIZE(occ) ){
	sort( ALL(occ) );
	REP( i, SIZE(occ) ) 
		cout << "(" << occ[i].first << "," << occ[i].second << ")\n";
	} else cout << "NO MATCH FOUND...\n";
	return 0;
}




















