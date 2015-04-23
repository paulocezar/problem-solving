#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

#define MAXK 11
#define MAXN 111

typedef long long int64;

long double dp[MAXK][MAXN];
bool seen[MAXK][MAXN];
int K, N;
	
long double solve( int last, int pos ){
	
	if( pos == N-1 ) return 1.0;
	
	if( !seen[last][pos] ){
		seen[last][pos] = true;
		
		dp[last][pos] = solve( last, pos+1 );
		if( last ) dp[last][pos] += solve( last-1, pos+1 );
		if( last < K ) dp[last][pos] += solve( last+1, pos+1 );
	}
	return dp[last][pos];
} 

int main(){
	
	ios::sync_with_stdio( false );

	while( cin >> K >> N ){
		
		for( int i = 0; i <= K; i++ )
			for( int j = 0; j < N; j++ )
				seen[i][j] = false;
		
		long double estr = 0.0;
		for( int i = 0; i <= K; i++ )
			estr += solve( i, 0 );
		
		cout << fixed << setprecision(5) << 100.0*estr/pow( (long double)(K+1),N) << "\n";
		
	}

	
	return 0;
}
