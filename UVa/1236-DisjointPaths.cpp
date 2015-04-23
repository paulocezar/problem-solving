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

typedef pair<int,int> edge;

#define MAXN 66
vector< edge > gr[MAXN];
int parent[MAXN];

void dfs(int u){
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ )
		if( parent[gr[u][i].first] == -1 ){
			parent[gr[u][i].first] = u;
			dfs(gr[u][i].first);
		}
}

int calc[2][MAXN][MAXN], calc_now;
int dp[2][MAXN][MAXN];

int solve( int onpath, int at, int K ){
	if( K == 0 && onpath == 0 ) return 0;
	
	int &res = dp[onpath][at][K];
	int &last_calc = calc[onpath][at][K];
	
	if( last_calc == calc_now ) return res;
	last_calc = calc_now;
	res = 0;
	
	if( onpath ){
		// path continue to a child..
		for( size_t i = 0, sz = gr[at].size(); i < sz; i++ ){
			
			if( gr[at][i].first == parent[at] ) continue;
			int continue_to = gr[at][i].first;
			
			int val = gr[at][i].second;
			
			int dp2[K]; // dp2[i][j] = best solution considering the i first child and j paths distributed 
			
			// base case, using the child 
			for( int nk = 0; nk <= K; nk++ ) dp2[nk] = val+solve(1,continue_to,nk);
			
			for( size_t j = 0, sz = gr[at].size(); j < sz; j++ ){
				if( gr[at][j].first == parent[at] ) continue;
				if( gr[at][j].first == continue_to ) continue;
				
				for( int curk = K; curk >= 0; curk-- ){ // can distribute this..
					for( int nk = 0; nk <= curk; nk++ ){
						dp2[curk] = max( dp2[curk], dp2[curk-nk] + solve(0,gr[at][j].first,nk) );
					}
				}	
			}
			
			res = max( res, dp2[K] );	
		}
		
		// or end here..
		int dp2[K];
		for( int nk = 0; nk <= K; nk++ ) dp2[nk] = 0;
		
		for( size_t j = 0, sz = gr[at].size(); j < sz; j++ ){
			if( gr[at][j].first == parent[at] ) continue;
			
			for( int curk = K; curk >= 0; curk-- ){ // can distribute this..
				for( int nk = 0; nk <= curk; nk++ ){
					dp2[curk] = max( dp2[curk], dp2[curk-nk] + solve(0,gr[at][j].first,nk) );
				}
			}	
		}
		res = max( res, dp2[K] );
		
		
	} else {
		// ignore this vertex.. (not in a path)
		int dp2[K];
		for( int nk = 0; nk <= K; nk++ ) dp2[nk] = 0;
		
		for( size_t j = 0, sz = gr[at].size(); j < sz; j++ ){
			if( gr[at][j].first == parent[at] ) continue;
			
			for( int curk = K; curk >= 0; curk-- ){
				for( int nk = 0; nk <= curk; nk++ ){
					dp2[curk] = max( dp2[curk], dp2[curk-nk] + solve(0,gr[at][j].first,nk) );
				}
			}	
		}
		res = max( res, dp2[K] );
		
		// or begin a new path here
		for( size_t i = 0, sz = gr[at].size(); i < sz; i++ ){ // going just to one child or two
			
			if( gr[at][i].first == parent[at] ) continue;
			int goes_to = gr[at][i].first;
			
			for( size_t i2 = i, sz = gr[at].size(); i2 < sz; i2++ ){
				if( gr[at][i2].first == parent[at] ) continue;
				int also_goes = gr[at][i2].first;
				
				if( also_goes == goes_to ){
					int val = gr[at][i].second;
					for( int nk = 0; nk < K; nk++ ) dp2[nk] = val+solve(1,goes_to,nk);
				} else {
					int val = gr[at][i].second + gr[at][i2].second;
					for( int nk = 0; nk < K; nk++ ){
						dp2[nk] = 0;
						for( int nk1 = 0; nk1 <= nk; nk1++ ) dp2[nk] = max( dp2[nk], val+solve(1,goes_to,nk1)+solve(1,also_goes,nk-nk1) );
					}
				}
				
				for( size_t j = 0, sz = gr[at].size(); j < sz; j++ ){
					if( gr[at][j].first == parent[at] ) continue;
					if( gr[at][j].first == goes_to ) continue;
					if( gr[at][j].first == also_goes ) continue;
					
					for( int curk = K-1; curk >= 0; curk-- ){ // can distribute this..
						for( int nk = 0; nk <= curk; nk++ ){
							dp2[curk] = max( dp2[curk], dp2[curk-nk] + solve(0,gr[at][j].first,nk) );
						}
					}		
				}
				
				res = max( res, dp2[K-1] );	
			}
		}
		
	}
	
	return res;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	while( t-- ){
		int N, K;
		cin >> N >> K;
		for( int i = 0; i < N; i++ ){ gr[i].clear(); parent[i] = -1; }
		
		for( int i = 0; i < N-1; i++ ){
			int u, v, d;
			cin >> u >> v >> d;
			gr[u-1].PB( edge(v-1,d) );
			gr[v-1].PB( edge(u-1,d) );
		}
		int root = 0;
		for( int i = 0; i < N; i++ ) if( SIZE(gr[i]) > SIZE(gr[root]) )
			root = i;
		parent[root] = root;
		dfs(root);
		calc_now++;
		cout << solve(0,root,min(K,30)) << "\n";
	}
	
	return 0;
}

























