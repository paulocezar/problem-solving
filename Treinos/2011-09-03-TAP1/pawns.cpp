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

int x[65], y[65];
int px[8], py[8];
bool got[8], now[8];

int at[8][8];
int ds[][2] = { {2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2} };

inline bool ok( int i, int j ){ return ((i>=0)&&(i<8)&&(j>=0)&&(j<8)&&(i==0||(at[i-1][j]==-1))); }

int ans;
void play( int hx, int hy, int prof, int P ){
	//cout << hx << " " << hy << " " << prof << " " << P << endl;
	if( P == 0 ){ ans = MIN(ans,prof); return; }
	if( prof >= ans ) return;
	
	if( prof ){
		REP( i, 8 ) if( now[i] && !got[i] && ( px[i] == 7 || (px[i]+1 == hx && py[i] == hy) ) ) return;
		REP( i, 8 ) if( now[i] && !got[i] ){
			at[px[i]][py[i]] = -1;
			px[i]++;
			at[px[i]][py[i]] = i;
		}
	}
	
	REP( dr, 8 ){
		int nx = hx+ds[dr][0];
		int ny = hy+ds[dr][1];
		if( ok(nx,ny) ){
			if( at[nx][ny] != -1 ){
				int who = at[nx][ny];
				got[who] = true;
				at[nx][ny] = -1;
				play(nx,ny,prof+1,P-1);
				got[who] = false;
				at[nx][ny] = who;
			} else play(nx,ny,prof+1,P);
		}
	}
	
	if( prof ){
		REP( i, 8 ) if( now[i] && !got[i] ){
			at[px[i]][py[i]] = -1;
			px[i]--;
			at[px[i]][py[i]] = i;
		}
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int pos = 1;
	FOR( i, 0, 7 ) FOR( j, 0, 7 ){
		x[pos] = i, y[pos] = j; pos++;
	}
	int P;
	
	while( cin >> P && P ){
		FILL( at, -1 );
		FILL( got, false );
		FILL( now, false );
		REP( i, P ){
			cin >> pos; now[i] = true;
			px[i] = x[pos];
			py[i] = y[pos];
			at[px[i]][py[i]] = i;
		}
		cin >> pos;
		ans = 10;
		play( x[pos], y[pos], 0, P );
		if( ans == 10 ) cout << "impossible\n";
		else cout << ans << "\n";
	}
	
	return 0;
}




















