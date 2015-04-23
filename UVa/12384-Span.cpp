#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define MAXN 1300000
#define SQMN 1143
bitset< MAXN+1 > bs;
int primes[100000];

void sieve(){
	for( int i = 0; i <= MAXN; i++ )
		bs[i] = (i&1);
	bs[1] = false;
	bs[2] = true;

	for( int i = 3; i <= SQMN; i+=2 ) if( bs[i] ){
		for( int j = i*i; j <= MAXN; j+=i ) bs[j] = false;
	}
	int pos = 0;
	for( int i = 0; i <= MAXN && pos < 100000; i++ )
		if( bs[i] ) primes[pos++] = i;
}

int n, m;
int s[100000], x[100000];

int main(){
	ios::sync_with_stdio(false);
	int t;
	sieve();
	cin >> t;
	while( t-- ){
		cin >> n >> m;
		int ans = 0;
		
		for( int i = 0; i < n; i++ ){
			x[i] = primes[i]%m;
			s[i] = 1;
			int j = i-1;
			while( j >= 0 && (x[j] <= x[i]) ){
				s[i] += s[j];
				j -= s[j];
			}
			ans += s[i];
			ans %= m;
		}

		cout << ans << "\n";
	}
	return 0;
}

