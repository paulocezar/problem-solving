#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef struct {
	string nomeCategoria;
	set< string > chaves;
	int precisa;
} categoria;

int main(){

	ios::sync_with_stdio(false);
	
	int t, i, j, p, min, tCategorias;
	bool imp;
	string linha, a;
	
	cin >> t;
	while( t-- ){
		cin >> tCategorias;
		categoria categ[tCategorias];
		min = 0;

		for( i = 0; i < tCategorias; i++ ){
			cin >> categ[i].nomeCategoria >> p >> categ[i].precisa;
			if( p > min ) min = p;
			for( j = 0; j < p; j++ ){
				cin >> a;
				categ[i].chaves.insert( a );
			}
		}

		cin.ignore();
		set< string > prob;
		while( getline( cin, linha ) && linha[0] ){
			j = linha.size();
			a = "";
			for( i = 0; i < j; i++ ){
				if( (linha[i] >= 'a' && linha[i] <= 'z') || ( linha[i] >= 'A' && linha[i] <= 'Z' ) )
					a += linha[i];
				else{
					prob.insert( a );
					a = "";
				}
			}
			if( a != " " );
			prob.insert( a );
		}

		vector< string >inter(min);
		vector< string >::iterator res;
		imp = false;
		for( i = 0; i < tCategorias; i++ ){
			res = set_intersection( prob.begin(), prob.end(), categ[i].chaves.begin(),
							categ[i].chaves.end(), inter.begin()  );

			if( res - inter.begin() >= categ[i].precisa )
				if( imp ) cout << "," << categ[i].nomeCategoria;
				else{ cout << categ[i].nomeCategoria; imp = true; }
		}

		if( imp ) cout << "\n";
		else cout << "SQF Problem.\n";

	}

	return 0;
}

