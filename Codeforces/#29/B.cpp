#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	long long l, d, v, g, r;
	long long out;

	cin >> l >> d >> v >> g >> r;
	
	l *= 1000000000ll;
	d *= 1000000000ll;
	v *= 1000000000ll;
	g *= 1000000000ll;
	r *= 1000000000ll;

	out = 1000000000ll * ( (double)d / (double)v );
	
	if( ( out % (g+r) ) >= g ) {  out += (r - ((out%(g+r))-g) );   } 

	out += 1000000000ll * ( (double)(l-d)/(double)v );

	cout << setprecision( 7 ) << (double)out/1000000000ll << endl;

	return 0;
}

