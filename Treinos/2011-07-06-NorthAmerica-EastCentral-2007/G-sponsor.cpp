#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

long long p[4], r[4], b[4], y[4], yy[4];
long long block[51];
long long partes[201];

typedef pair< long long, long long > bezout;
bezout find_bezout( long long x, long long y ){
	if( y == 0 ) return bezout( 1, 0 );
	bezout u = find_bezout( y, x%y );
	return bezout( u.second, u.first - (x/y)* u.second );
}
long long mod( long long x, long long m ){ return x % m + ((x<0)?m:0); }

long long solve_mod( long long a, long long b, long long m ){
	if( m < 0 ) return solve_mod( a, b, -m );
	if( a < 0 || a >= m || b < 0 || b >= m ) return solve_mod( mod(a,m), mod(b,m), m );
	bezout t = find_bezout( a, m );
	long long d = t.first * a + t.second * m;
	if( b%d ) return -1;
	return mod( t.first*(b/d), m );
}

int main()
{
	ios::sync_with_stdio(false);
	
	long long t;
	cin >> t;
	while( t-- ){
		
		long long N;
		cin >> N;
		
		long long m = 1;
		for( long long i = 0; i < 4; i++ ) { cin >> p[i]; m *= p[i]; }
		for( long long i = 0; i < N; i++ ) cin >> block[i];
		
		for( long long i = 0; i < N; i++ ){
			long long j = 3;
			
			long long ans = 0;
			while( j >= 0 ){
				r[j] = block[i] % 100;
			//cout << r[j] << endl;
				b[j] = solve_mod( 1, r[j], p[j] );
			//cout << b[j] << endl;
				y[j] = m/p[j];
			//cout << y[j] << endl;
				yy[j] = solve_mod( y[j], 1, p[j] );
			//cout << yy[j] << endl;
				ans += b[j]*y[j]*yy[j];
				block[i] /= 100;
				j--;
			}
			ans %= m;
			if( i == N-1 ){
				string pr = "";
				while( ans ){
					long long cur = ans % 100;
					if( cur == 27 ){ if( pr != "") pr += ' '; }
					else pr += char('A'+cur-1);
					ans /= 100;
				}
				reverse( pr.begin(), pr.end() );
				cout << pr << "\n";
			} else {
				string pr = "";
				while( ans ){
					long long cur = ans % 100;
					if( cur == 27 ) pr += ' ';
					else pr += char('A'+cur-1);
					ans /= 100;
				}
				reverse( pr.begin(), pr.end() );
				cout << pr;
			}
		}
		
	}

	return 0;
}
