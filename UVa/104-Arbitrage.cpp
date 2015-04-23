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
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 22

double gr[MAXN][MAXN][MAXN];
int N, p[MAXN][MAXN][MAXN];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	while( (cin>>N) && N ){
		REP( i, N )
			REP( j, N ){
				if( i == j ) gr[1][i][j] = 1.;
				else cin >> gr[1][i][j];
				p[1][i][j] = j;
			}
		
		FOR( steps, 2, N ){
			REP( i, N )
			REP( j, N ){
				gr[steps][i][j] = 0.; p[steps][i][j] = -1;
				REP( k, N )
					if( gr[1][i][k]*gr[steps-1][k][j] > gr[steps][i][j] ){
						gr[steps][i][j] = gr[1][i][k]*gr[steps-1][k][j];
						p[steps][i][j] = k;
					}
			}
		}
		
		bool print = false;		
		FOR( steps, 1, N ){
			REP( i, N ) if( gr[steps][i][i] > 1.01 ){
				print = true;
				int a = i;
				while( steps ){
					cout << a+1 << " ";
					a = p[steps][a][i];
					steps--;
				}
				cout << i+1 << "\n";
				goto hell;
			}
		}
	hell:
		if( !print ) cout << "no arbitrage sequence exists\n";

 	}
	
	return 0;
}




















