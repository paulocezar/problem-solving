#include <iostream>

using namespace std;

#define MAXN 100100

int lf[MAXN], rg[MAXN];

int findlf( int u ){
	if( u == lf[u] ) return u;
	lf[u] = findlf( lf[u] );
	return lf[u];
}

int findrg( int u ){
	if( u == rg[u] ) return u;
	rg[u] = findrg( rg[u] );
	return rg[u];
}

int main(){
	ios::sync_with_stdio(false);
	
	int S, B;
	cin >> S >> B;
	while( S+B ){
		
		for( int i = 0; i <= S; i++ ) lf[i] = rg[i] = i;
		lf[S+1] = rg[S+1] = 0;
		
		int from, to;
		while( B-- ){
			
			cin >> from >> to;
			int l = findlf( from-1 );
			int r = findrg( to+1 );
			
			if( l ) cout << l;
			else cout << "*";
			cout << " ";
			if( r ) cout << r;
			else cout << "*";
			cout << "\n";
			
			while( from <= to ){
				lf[from] = l;
				rg[from] = r;
				from++;
			}			
		}
		cout << "-\n";
		
		cin >> S >> B;
	}	
	
	return 0;
}
