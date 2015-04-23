#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXM 1005

int dp[MAXM];
int box[2*MAXM];
int sz;

void printans( int val ){

	if( val == 0 ){ cout << sz; return; }
	sz++;
	printans( val - box[ dp[val]-1 ] );
	cout << " " << dp[val];
	
}	
	
int main(){

	ios::sync_with_stdio( false );
	
	int M, N, L, total;
	
	cin >> M >> L;
	while( M+L ){
		
		cin >> N;
		
		memset( dp, 0, (M+1)*sizeof( int ) );
		
		total = 0;
		for( int i = 0; i < N; i++ ){
			cin >> box[i];
			total += box[i];
		}
		
		dp[0] = -1;
		for( int i = 0; i < N; i++ ){
		
			for( int j = M; j >= box[i]; j-- ) if( dp[j] == 0 && dp[j-box[i]] ) dp[j] = i+1;
			
		}
		
		for( int i = 0; i <= M; i++ ) if( dp[i] && ( L >= total-i ) ){
			sz = 0;
			printans( i );
			cout << "\n";
			goto hell;
		}
		
		cout << "Impossible to distribute\n";
	hell:	
		cin >> M >> L;
	}
	
	return 0;
}

