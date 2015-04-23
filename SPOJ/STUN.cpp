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

int t[6][1001];
int XP, won, cur_round, p[6], xp[6];
int team[6];

bool comp( int i, int j ){
	if( t[i][cur_round] != t[j][cur_round] ) return (t[i][cur_round] < t[j][cur_round]);
	return (i < j);
}

bool play(){
	
	if( cur_round != -1 ){
		REP( i, 6 ) p[i] = i, team[i] = -1;
		sort( p, p+6, comp );
	
		int t1 = -1, t2 = -1;

		REP( i, 6 ) {
			int op = (p[i]&1)?(p[i]-1):(p[i]+1);
			if( team[op] == -1 ){
				team[p[i]] = 1;
				t1 = max( t1, t[p[i]][cur_round] );
			} else{
				team[p[i]] = 2;
				t2 = max( t2, t[p[i]][cur_round] );
			}
		}
		
		int now = 1;
		while( now <= 240 ){
			if( now>t1 && ((now-t1)%7) == 0 ){
				REP( i, 6 ) if( team[i] == 1 ) xp[i] += 300;
			}
			if( now>t2 && ((now-t2)%7) == 0 ){
				REP( i, 6 ) if( team[i] == 2 ) xp[i] += 300;
			}
			REP( i, 6 ) if( xp[i] >= XP ){
				won = i+1;
				return false;
			}
			now++;
		}
	
		bool poison_t1 = ((240-t1)%7)>1;
		bool poison_t2 = ((240-t2)%7)>1;
	
		REP( i, 6 ) if( (team[i]==1&&poison_t1) || (team[i]==2&&poison_t2) )
			xp[i] += 1800;
	}
		
	REP( i, 6 ) if( xp[i] >= XP ){
		won = i+1;
		return false;
	}
	
	return true;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int R;
	while( (cin >> XP >> R) && (XP+R) ){
		
		REP( i, 6 ) cin >> xp[i];
		 
		REP( j, R ) REP( i, 6 )
			cin >> t[i][j];
		
		cur_round = -1;
		if( play() ){
			
			cur_round = 0;
			while( cur_round < R ){
				if( play() ) cur_round++;
				else { cout << won << " " << cur_round+1; goto hell; }
			}
			cout << "-1";
			REP( i, 6 ) cout << " " << xp[i];
			hell:
				cout << "\n";
				
		} else cout << won << " 0\n";
		
		
	}
		
	return 0;
}

























