#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long int64;

#define MAXL 100001

int64 bit[ MAXL ];
int64 pot[ MAXL ];
int64 inv[ MAXL ];

int64 B, P;

void up( int x, int64 val ){
	while( x < MAXL ){
		bit[x] += val;
		bit[x] %= P;
		while( bit[x] < 0 ) bit[x] += P;
		x += (x & -x);
	}
}

int64 get( int x ){
	int64 acum = 0;
	while( x > 0 ){
		acum += bit[x];
		if( acum >= P ) acum -= P;
		x -= (x & -x);
	}
	return acum;
}

int64 gcd_ext( int64 a, int64 b, int64 &x, int64 &y ){
	x = 1; y = 0;
	int64 nx = 0, ny = 1, q;
	while( b ){
		q = a/b;
		x -= q*nx; swap( x, nx );
		y -= q*ny; swap( y, ny );
		a -= q*b; swap( a, b );
	}
	return a;
}

int main(){
	ios::sync_with_stdio(false);
	
	char wut;
	int L, N, from, to;
	int64 ax, val;
	
	cin >> B >> P >> L >> N;
	while( B || P || L || N ){
	
		memset( bit, 0, sizeof(bit) );
		pot[L] = 1;
		inv[L] = 1;
		for( int i = L-1; i > 0; i-- ){
			pot[i] = B * pot[ i+1 ];
			pot[ i ] %= P;
			gcd_ext( pot[i], P, inv[i], ax );
			inv[i] %= P;
			while( inv[i] < 0 ) inv[i] += P;			
		}
		
		for( int i = 0; i < N; i++ ){
			cin >> wut;
			if( wut == 'E' ){
				cin >> from >> val;
				int64 rem = get( from ) - get( from-1 );
				rem %= P;
				while( rem < 0 ) rem += P;
				
				up( from, -rem );
				int64 nval = ( val % P ) * pot[from]; nval %= P;
				
				up( from, nval );
			} else {
				cin >> from >> to;
				int64 ans = get( to ) - get( from-1 );
				ans %= P;
				while( ans < 0 ) ans += P;
				ans *= inv[ to ];
				ans %= P;
				cout << ans << "\n";
			}
		}
		cout << "-\n";
		cin >> B >> P >> L >> N;	
	}
			
	return 0;
}


