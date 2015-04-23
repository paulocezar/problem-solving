#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 20

int N, cand, side;

int len[MAXN];
char solved[1<<MAXN];

char solve( int mask, int pos, int acum, int done ){
	if( done == 4 ) return 1;	
	if( acum == side ) return solve( mask, 0, 0, done+1 );

	if( solved[mask] == -1 ){
		solved[mask] = 0;
		while( pos < N && !solved[mask] ){
			if( (mask & (1<<pos)) && acum+len[pos] <= side ) 
				solved[mask] = solved[mask] || solve(mask ^ (1<<pos), pos+1, acum+len[pos], done);
			pos++;
		}
	}
	return solved[mask];

}

int main(){
	
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	
	while( t-- ){
		
		cin >> N;
		int sum = 0;
		
		for( int i = 0; i < N; i++ ){
			cin >> len[i];
			sum += len[i];
		}
		sort( len, len+N );

		if( sum%4 == 0 ){
			side = sum/4;

			int lmask = 1<<N;
			memset( solved, -1, sizeof(char)*lmask );
			
			if( solve( lmask-1, 0, 0, 0 ) ) cout << "yes\n";
			else cout << "no\n";

		} else cout << "no\n";
	
	}
	return 0;
}

