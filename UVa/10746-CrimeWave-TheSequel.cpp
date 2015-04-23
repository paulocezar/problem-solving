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
#define RREP(i, N) for(int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

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

#define MAXN 22

int N, M;
double cost[MAXN][MAXN], dt[MAXN][MAXN];
int fs[MAXN][MAXN], cc[MAXN], mc[MAXN], cccnt;

bool augCycle(){
	REP( i, M ) REP( j, M ){
		if( (cost[i][mc[i]] != INF) && (cost[i][mc[j]] != INF) ) 
			dt[i][j] = cost[i][mc[i]]-cost[i][mc[j]];
		else dt[i][j] = 0;
		fs[i][j] = j;
	}
	REP( k, M )
		REP( i, M )
		REP( j, M )
			if( dt[i][k]+dt[k][j] > dt[i][j] ){
				dt[i][j] = dt[i][k] + dt[k][j];
				fs[i][j] = fs[i][k];
				if( i == j ){
					cccnt = 0;
					do {
						cc[ cccnt++ ] = i;
						i = fs[i][j];
					} while( i != j );
					return true;
				}
			}
	return false;
}

double bestMatch(){
	REP( i, M ) mc[i] = i;
	int j;
	while( augCycle() ){
		j = mc[cc[0]];
		REP( i, cccnt-1 ) mc[ cc[i] ] = mc[ cc[i+1] ];
		mc[cc[cccnt-1]] = j;
	}
	double ret = 0;
	REP( i, M ) if( cost[i][mc[i]] != INF ) ret += cost[i][ mc[i] ];
	return ret/N;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	while( (cin >> N >> M ) && (N+M) ){
		REP( i, N ) REP( j, M ) cin >> cost[i][j];
		FOR( i, N, M-1 ) REP( j, M ) cost[i][j] = INF;
		cout << fixed << setprecision(2) << bestMatch() << "\n";
	}
	return 0;
}




















