#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>

#define REP( i, a ) for( int i = 0; i < a; i++ )

using namespace std;

struct component{
	int type, price, qual;
	component( int tp = 0, int pr = 0, int ql = 0 ) : type(tp), price(pr), qual(ql) {}
	bool operator < ( const component& c ) const {
		if( qual != c.qual ) return qual < c.qual;
		if( price != c.price ) return price < c.price;
		return type < c.type;
	}
};

#define MAXN 1001

component comp[MAXN];

#define INF 2000000000

int payd[MAXN];
int qual[MAXN];

int n, b, cctype;

map< string, int > comp_type;

bool ok( int minqual ){

	int i = n-1;
	
	while( i && comp[i].qual >= minqual ) i--;
	if( comp[i].qual < minqual ) i++;
	
	for( int x = 0; x < cctype; x++ ) payd[x] = INF;
	
	while( i < n ){
		payd[ comp[i].type ] = min( payd[ comp[i].type ], comp[i].price );
		i++;
	}
	
	int used = 0;
	int spent = 0;
	for( int x = 0; x < cctype; x++ ) if( payd[x] != INF ){
		spent += payd[x];
		used++;
	}
	
	if( used == cctype && spent <= b ) return true;
	return false;
}

int main(){
	ios::sync_with_stdio( false );
	
	string tp, nm;
	int t, pr, ql;
		
	cin >> t;
	while( t-- ){
		
		cin >> n >> b;
		comp_type.clear();
		cctype = 0;
		
		REP( i, n ){
			cin >> tp >> nm >> pr >> ql;
			if( comp_type.find( tp ) == comp_type.end() ) comp_type[ tp] = cctype++;
			comp[i] = component( comp_type[ tp ], pr, ql );
			qual[i] = ql;
		}
		
		sort( qual, qual+n );
		sort( comp, comp+n );
		
		int ans = qual[0];
		for( int i = n-1; i > 0; i-- ) if( qual[i] != qual[i-1] && ok( qual[i] ) ){
			ans = qual[i];
			break;
		}
		cout << ans << "\n";
		
	}	
	
	return 0;
}
