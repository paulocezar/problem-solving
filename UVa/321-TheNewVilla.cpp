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

#define MAXR 11
int R;
bool gr[MAXR][MAXR], swit[MAXR][MAXR];

int parent[MAXR][1<<MAXR];

int solve(){
	int cur, room, lights, end = ((1<<(R-1))<<4) + (R-1);
	queue< int > q;
	q.push( 1<<4 ); q.push( -1 ); parent[0][1] = 0;
	int dist = 0;
	while( !q.empty() ){
		cur = q.front(); q.pop();
		if( cur == end ) return dist;
		if( cur == -1 && !q.empty() ){ dist++; q.push(-1); continue; }
		room = cur & ((1<<4)-1);
		lights = cur >> 4;
		REP( i, R ){
			if( swit[room][i] && i != room ){
				if( parent[room][lights^(1<<i)] == -1 ){
					parent[room][lights^(1<<i)] = cur;
					q.push( ( (lights^(1<<i))<<4 ) + room );
				}
			}
			if( gr[room][i] && (lights&(1<<i)) ){
				if( parent[i][lights] == -1 ){
					parent[i][lights] = cur;
					q.push( (lights<<4) + i );
				}
			}
		}
	}
	return INF;
}

void show( int room, int lights ){
	if( parent[room][lights] == 0 ) return;
	int pr = parent[room][lights] & ( (1<<4)-1 );
	int pl = parent[room][lights] >> 4;
	show( pr, pl );
	if( pr == room ){
		if( ~pl & lights ){
			pr = __builtin_popcount( (~pl & lights)-1 ) + 1;
			cout << "- Switch on light in room " << pr << ".\n";
		} else {
			pr = __builtin_popcount( (~lights & pl)-1 ) + 1;
			cout << "- Switch off light in room " << pr << ".\n";
		}
	} else cout << "- Move to room " << room+1 << ".\n";
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int D, S, u, v, villa = 1;

	while( (cin>>R>>D>>S) && (R+D+S) ){
		
		REP( i, R ){
			REP( j, R ) gr[i][j] = false, swit[i][j] = false;
			REP( j, 1<<R ) parent[i][j] = -1;
		}
		while( D-- ){
			cin >> u >> v; u--, v--;
			gr[u][v] = gr[v][u] = true;
		}
		while( S-- ){
			cin >> u >> v; u--, v--;
			swit[u][v] = true;
		}
		int ans = solve();
		cout << "Villa #" << villa++ << "\n";
		if( ans == INF ) cout << "The problem cannot be solved.\n";
		else{ cout << "The problem can be solved in " << ans << " steps:\n"; show( R-1, 1<<(R-1) ); }
		cout << "\n";
	}
	return 0;
}




















