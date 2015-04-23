#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define MAXN 1010
int x[MAXN];

int main(){
	ios::sync_with_stdio(false);
	
	int t, N, K;
	cin >> t;
	
	while( t-- ){
		cin >> N >> K;
		x[0] = 0;
		
		for( int i = 1; i <= N; i++ ) cin >> x[i];
		
		int ans = 0;
		while( x[N] != N ){
			
			int pos = N-1;
			while( pos && x[pos+1] == (x[pos]+1) ) pos--;
		
			int cons = N-pos;
			int move = x[pos+1]-x[pos]-1;
		
			ans += (int(ceil(double(cons)/K)))*move;
			
			int cur = x[pos]+1;
			while( ++pos <= N ) x[pos] = cur++;
			
		}
		cout << ans << "\n";
		
	}
	
	return 0;
}
