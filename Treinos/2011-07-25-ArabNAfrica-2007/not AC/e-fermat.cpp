#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 1000001
#define SQRT 1001

char prime[MAXN];
vector< int > primes;
vector< int > sprimes;

void preprocess(){
	for( int i = 0; i < MAXN; i++ ) prime[i] = ( i & 1 );
	prime[2] = 1;
	primes.clear(); sprimes.clear();

	for( int i = 3; i < SQRT; i+=2 ) if( prime[i] ){
		for( int j = i+i; j < MAXN; j+=i ) prime[j] = 0;
	}
	for( int i = 2; i < MAXN; i++ ) if( prime[i] ){
		primes.push_back( i );
		if( ((i-1) % 4) == 0 ) sprimes.push_back( i );
	}
}

int main(){

	int L, U;
	preprocess();
	cin >> L >> U;
	while( L != -1 || U != -1 ){
		
		int primos = upper_bound( primes.begin(), primes.end(), U ) - lower_bound( primes.begin(), primes.end(), L );
		int sprimos = upper_bound( sprimes.begin(), sprimes.end(), U ) - lower_bound( sprimes.begin(), sprimes.end(), L );

		cout << L << " " << U << " " << primos << " " << sprimos << "\n";
		cin >> L >> U;
	}

	return 0;
}

