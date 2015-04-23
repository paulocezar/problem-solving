#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

int main(){
	
	int N, D;
	while( (cin>>N>>D) && (N+D) ){
		string s;
		cin >> s;
		int p = 0, sz = int(s.size());	
		char stk[sz];
		int ap = 0, ps = 0;
		while( ap < D && (p<sz) ){

			while( ps && ap<D && stk[ps-1] < s[p] ){
				--ps;
				ap++;
			}
			stk[ps++] = s[p];
			p++;
		}
		while( p < sz ) stk[ps++] = s[p++];
		for( int i = 0; i < N-D; i++ ) cout << stk[ i ];
		cout << "\n";
	}

	return 0;
}

