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

int R, C, grid[16];


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	while( (cin >> R >> C) && (R||C) ){
		
		string sgrid[R];
		REP( i, R ) cin >> sgrid[i];
		
		REP( i, R ){
			grid[i] = 0;
			REP( j, C ) if( sgrid[i][j] == 'X' ) grid[i] |= (1<<j);
		}
		
		int ans = 666;
		
		for( int first_press = 0; first_press < (1<<C); first_press++ ){
			int pressed_buttons = __builtin_popcount(first_press);
			
			int press_now = grid[0];
			int nxt_row = grid[min(1,R-1)];
			
			REP( i, C ) if( first_press & (1<<i) ){
				
				if( i ) press_now ^= (1<<(i-1));
				press_now ^= (1<<i);
				if( i+1 < C ) press_now ^= (1<<(i+1));
				
				nxt_row ^= (1<<i);
			} 
			
			FOR( row, 1, R-1 ){
				pressed_buttons += __builtin_popcount(press_now);
				
				int nxtpress = nxt_row;
				nxt_row = grid[min(row+1,R-1)];
				
				REP( i, C ) if( press_now & (1<<i) ){
					
					if( i ) nxtpress ^= (1<<(i-1));
					nxtpress ^= (1<<i);
					if( i+1 < C ) nxtpress ^= (1<<(i+1));
					
					nxt_row ^= (1<<i);
					
				}
				press_now = nxtpress;
				
			}
			if( press_now == 0 ) ans = min( ans, pressed_buttons );
		}
		
		if( ans == 666 ) cout << "Damaged billboard.\n";
		else cout << "You have to tap " << ans << " tiles.\n";
		
	}
	
	return 0;
}

























