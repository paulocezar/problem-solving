#include <iostream>
#include <string>
#include <map>

using namespace std;

string pt[350];
int son[350];
char first[350];

int main(){

	int ct, t, u, v, etapas, i, dif;
	string a, b;
	ios::sync_with_stdio( false );

	cin >> t;
	for( ct = 1; ct <= t; ct++ ){
		
		map< string, int > id;

		cin >> etapas;
		dif = 0;
		for( i = 0; i < etapas; i++ ) { son[i] = -1; first[i] = 1; }

		for( i = 1; i < etapas; i++ ){
			cin >> a >> b;
			if( id.find( a ) != id.end() ) u = id[a];
			else { u = dif; pt[dif] = a; id[a] = dif++; }

			if( id.find( b ) != id.end() ) v = id[b];
			else{ v = dif; pt[dif] = b; id[b] = dif++; }
			son[u] = v;
			first[v] = 0;
		}
		
		for( i = 0; i < etapas; i++ ) if( first[i] ) break;

		cout << "Cenario #" << ct << ":\n";
		do{
			cout << pt[i] << "\n";
			i = son[i];
		} while( son[i] != -1 );		
		cout << pt[i] << "\n\n";

	}

	return 0;
}

