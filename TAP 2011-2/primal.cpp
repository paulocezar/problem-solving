#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

#define MAXP 90000
bitset< MAXP > bs;
vector< int > primes;

void sieve(){
	bs.reset();
	for( int i = 0; i < MAXP; i++ ) 
			bs[i] = (i&1);
	primes.clear(); primes.push_back( 2 );
	int sq = sqrt(MAXP) + 2; 
	for( int i = 3; i < MAXP; i+=2 ) if( bs[i] ) {
		primes.push_back( i );
		if( i > sq ) continue;
		for( int j = i*i; j < MAXP; j+=i ){
				bs[j] = false;
		}
	}
}


int main(){
	ios::sync_with_stdio( false );
	sieve();
	int t, n;
	cin >> t;
	while( t-- ){
		cin >> n;
		cout << primes[primes[n-1]-1] << "\n";
	}
	return 0;
}

