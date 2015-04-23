#include <iostream>

using namespace std;

typedef long long int64;

int amnt[1<<10];

int main(){
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	int64 x;
	while( N-- ){
		cin >> x;
		int cur = 0;
		while( x ){
			int dig = x%10;
			cur |= (1<<dig);
			x/=10;
		}
		for( int i = 0; i < 10; i++ )
			if( cur&(1<<i) ) cout << i << endl;
			 
		amnt[cur]++;
	}
	
	int64 ans = 0;
	
	for( int i = 0; i < (1<<10); i++ ) if( amnt[i] ){
		ans += (amnt[i]*(amnt[i]-1))/2;
		
		for( int x = 0; x < 10; x++ )
			if( i&(1<<x) ) cout << x << endl;
			
		for( int j = i; j > 0; j = (j - 1) & i ){
			if( j != i ){
				ans += amnt[i]*amnt[j];
			
			for( int x = 0; x < 10; x++ )
				if( j&(1<<x) ) cout << "\t" << x << endl;
			cout << endl;
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}