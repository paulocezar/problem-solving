#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

int main(){

	map< long long, bool > fib;
	map< long long, bool >::iterator it;

	long long x = 1ll, y = 2ll, cnt, out;
	fib[1] = fib[2] = true;
	int t, n, tst = 1;
	
	ios::sync_with_stdio( false );

	while( y < 2000000000ll ) {
		x += y;
		fib[x] = true;
		x ^= y; y ^= x; x ^= y;
	}
	
	cin >> t;
	while( t-- ){
		cin >> n;
		out = 1ll;
		while( n-- ){
			cnt = 1;
			cin >> x;
			it = fib.upper_bound( x ); it--;
			while( it->first != x ){
				cnt++;
				x -= it->first;
				it = fib.upper_bound( x ); it--;
			}
			out *= cnt;
		}
		cout << "Case " << tst++ << ": " << out << "\n";
	}
	
	return 0;
}

