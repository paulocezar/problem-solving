#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){

	int n, x, d;
	map< int, int > spit;
	bool ans = false;

	cin >> n;
	while( n-- ){
		cin >> x >> d;
		spit[x] = x+d;
		if( spit.find( x+d ) != spit.end() && spit[x+d] == x ) { ans = true; break; } 
	}

	if( !ans ) cout <<  "NO\n";
	else cout << "YES\n";

	return 0;
}

