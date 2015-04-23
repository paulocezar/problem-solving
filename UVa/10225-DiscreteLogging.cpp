#include <iostream>
#include <cmath>
#include <map>

using namespace std;

typedef long long int64;
int64 MOD;

int64 mod_pow( int64 a, int64 p ){
	int64 ans = 1LL; a %= MOD;
	while( p ){
		if( p & 1 ) ans = ( ans * a ) % MOD;
		a = ( a * a ) % MOD;
		p >>= 1;
	}
	return ans;
}

/*
 Given P prime, B and N find L such that B^L == N (mod P)
	rewrite L as i*m + j, m = ceil( sqrt(P) ), 0 <= j < m
	B^(i*m + j) == N
	B^j == N*(B^(-m))^i
	N*( B^(-m) )^i = B^j
	precompute B^j and trie the values of i
*/
int64 discrete_log( int64 P, int64 B, int64 N ){
	MOD = P;
	map<int64, int64> seen;
	int64 m = (int64) ceil( sqrt( P ) );
	for( int64 i = 0; i < m; i++ ){
		int64 pp = mod_pow( B, i );
		if( seen.find( pp ) == seen.end() ) seen[pp] = i;
	}
	int64 a = mod_pow( B, P-m-1 );
	int64 ans = -1;
	for( int64 i = 0; i < m; i++ ){
		if( seen.find( N ) != seen.end() ){
			ans = i*m + seen[N];
			break;
		} else N = ( N * a ) % P;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio( false );
	int64 P, B, N;
	while( cin >> P >> B >> N ){
		int64 ans = discrete_log(P,B,N);
		if( ans == -1 ) cout << "no solution\n";
		else cout << ans << "\n";
	}
	
	return 0;
}
