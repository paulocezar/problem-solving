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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 10001
#define MAXM 101

int N, M;
string dict[MAXN];
string L[MAXM];

int worst[MAXM];
int idw[MAXM];

void brute( int cur ){
	REP( ll, M ){
		
		list<string> cand;
		vector<bool> reveal( 50, false );
		
		REP( i, N ) if( SIZE(dict[i]) == SIZE(dict[cur]) ) cand.pb( dict[i] );
		
		int loss = 0;
		REP( guess, SIZE(L[ll]) ){
			
			bool ok = false;
			FORIT( wrd, cand ){
				REP( i, SIZE((*wrd)) ) if( (*wrd)[i] == L[ll][guess] ){ ok = true; break; }
				if( ok ) break;
			}
			if( !ok ) continue;
			
			ok = false;
			REP( i, SIZE(dict[cur]) ) if( dict[cur][i] == L[ll][guess] ){ ok = true; break; }
			if( !ok ){ 
				loss++;
				
				TI(cand) wrd = cand.begin();
				
				while( wrd != cand.end() ){
					ok = true;
					REP( i, SIZE(dict[cur]) ) if( (*wrd)[i] == L[ll][guess] ){
						wrd = cand.erase( wrd );
						ok = false;
						break;
					}
					if( ok ) wrd++;
				}
				
				wrd = cand.begin();
				
				while( wrd != cand.end() ){
					ok = true;
					REP( i, SIZE(dict[cur]) ) if( reveal[ dict[cur][i]-'a' ] && (*wrd)[i] != dict[cur][i] ){
						wrd = cand.erase( wrd );
						ok = false;
						break;
					}
					if( ok ) wrd++;
				}
				
			} else {
				reveal[ L[ll][guess]-'a' ] = true;
			
				TI(cand) wrd = cand.begin();
				
				while( wrd != cand.end() ){
					ok = true;
					REP( i, SIZE(dict[cur]) ) if( reveal[ dict[cur][i]-'a' ] && (*wrd)[i] != dict[cur][i] ){
						wrd = cand.erase( wrd );
						ok = false;
						break;
					}
					if( ok ) wrd++;
				}
			}
			
			int cnt = 0;
			REP( i, SIZE(dict[cur]) ) if( reveal[ dict[cur][i]-'a' ] ) cnt++;
			if( cnt == SIZE(dict[cur]) ) break;
		}
		
		if( loss > worst[ll] ){
			worst[ll] = loss;
			idw[ll] = cur;
		}
		
	}
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int T;
	cin >> T;
	FOR( tc, 1, T+1 ){
		
		cin >> N >> M;
		
		REP( i, N ) cin >> dict[i];
		REP( i, M ){ cin >> L[i]; worst[i] = -1; }
		
		REP( i, N ) brute( i );
		
		cout << "Case #" << tc << ":";
		REP( i, M ) cout << " " << dict[idw[i]];
		cout << "\n";
	}
	
	return 0;
}


































