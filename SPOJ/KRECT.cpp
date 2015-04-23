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

#define PB push_back
#define MP make_pair

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int M, N, K;
	cin >> M >> N >> K;
	
	int pop[1<<13];
	for( int i = 0; i < (1<<13); i++ ){
		pop[i] = pop[i>>1] + (i&1);
	}
	
	int grid[M][N];
	char c;
	
	int mask[M][N][N];
	
	for( int i = 0; i < M; i++ ) for( int j = 0; j < N; j++ ){
		cin >> c;
		grid[i][j] = 1<<(c-'A');
	}
	
	for( int i1 = 0; i1 < M; i1++ )
		for( int j1 = 0; j1 < N; j1++ )
			for( int j2 = j1; j2 < N; j2++ )
				mask[i1][j1][j2] = ((j2>j1)?mask[i1][j1][j2-1]:0) | grid[i1][j2];

	
	int ans = 0;
	for( int j1 = 0; j1 < N; j1++ ) for( int j2 = j1; j2 < N; j2++ ){
		
		for( int i1 = 0; i1 < M; i1++ ){
			int cur_mask = 0;
			for( int i2 = i1; i2 < M; i2++ ){
				cur_mask |= mask[i2][j1][j2];
				int xxx = pop[cur_mask&((1<<13)-1)] + pop[cur_mask>>13];
				if( xxx == K ) ans++;
				if( xxx > K ) break;
			}	
		}
		
	}
	
	cout << ans << "\n";
	
		
	
	
	return 0;
}

























