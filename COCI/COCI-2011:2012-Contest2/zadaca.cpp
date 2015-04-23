#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long int64;

int64 gcd( int64 a, int64 b ){
	while( b ){
		a %= b;
		swap(a,b);
	}
	return a;
}

#define MAXN 1001
int64 a[MAXN], b[MAXN];

const int64 mod = 1000000000LL;

int main(){
	int N, M;	
	
	scanf("%d", &N );
	for( int i = 0; i < N; i++ ) scanf("%lld", a+i );
	scanf("%d", &M );
	for( int i = 0; i < M; i++ ) scanf("%lld", b+i );
	
	int64 gg = 1;
	bool flag = false;
	for( int i = 0; i < N; i++ )
		for( int j = 0; j < M; j++ ){
			int64 now = gcd( a[i], b[j] );
			gg *= now;
			a[i] /= now;
			b[j] /= now;
			if( gg >= mod ) flag = true;
			gg %= mod;
		}
	
		if( flag ) printf("%09lld\n", gg );
		else printf("%lld\n", gg );
	
	return 0;
}

