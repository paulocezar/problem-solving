#include <map> 
#include <set> 
#include <list>
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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(double a, double b) { return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 30
string quer[MAXN], prefere[MAXN];
char h[MAXN], m[MAXN];
int casa[MAXN], pretendente[MAXN], homem[MAXN], mulher[MAXN];
int n;

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t; string s;
	cin >> t;
	while( t-- ){
		cin >> n;
		
		REP( i, n ){ cin >> h[i]; homem[h[i]-'a'] = i; } 
		REP( i, n ){ cin >> m[i]; mulher[m[i]-'A'] = i; }
		
		REP( i, n ){
			cin >> s;
			quer[ homem[s[0]-'a'] ] = s.substr( 2 );
			REP( j, n ) quer[i][j] = mulher[ quer[i][j]-'A' ];
		}
		
		REP( i, n ){
			cin >> s;
			prefere[ mulher[s[0]-'A'] ] = s.substr( 2 );
			REP( j, n ) prefere[i][j] = homem[prefere[i][j]-'a'];
		}
		
		REP( i, n ) casa[i] = -1, pretendente[i] = 0;
		REP( i, n ){
			int _homem = i;
			while( pretendente[_homem] < n ){
				
				int _mulher = quer[_homem][ pretendente[_homem]++ ];
				
				if( casa[_mulher] != -1 ){
					int outro = casa[_mulher];
					
					REP( j, n ) if( prefere[_mulher][j] == _homem || prefere[_mulher][j] == outro ){
						casa[_mulher] = prefere[_mulher][j];
						break;
					}
					
					if( casa[_mulher] == _homem ) _homem = outro;
				} else{
					casa[ _mulher ] = _homem;
					break;
				}
			}
		}
		
		sort( h, h+n );
		REP( i, n ){
			cout << h[i] << " " << m[ quer[ homem[h[i]-'a'] ][pretendente[ homem[h[i]-'a'] ]-1] ] << "\n";
		}
		if( t ) cout << "\n";
		
	}
	
	return 0;
}




















