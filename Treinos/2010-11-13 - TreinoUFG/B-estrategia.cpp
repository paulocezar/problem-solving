#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define MAXP 30

using namespace std;

int dif[MAXP];

string name[3];
int pont[3];
int solv[3];

bool func( int a, int b ){
	if( solv[a] != solv[b] ) return solv[a] > solv[b];
	if( pont[a] != pont[b] ) return pont[a] < pont[b];
	if( a == 1 ) return true;
	return false;	
}

bool compare1( int a, int b ) { return a < b; }
bool compare( int a, int b ){ return a > b; }

int main(){

	ios::sync_with_stdio( false );
	
	int sc, scenarios;
	int dur, prob, tm;
	int i;

	name[0] = "Joao";
	name[1] = "Jose";
	name[2] = "Joaquim";

	cin >> scenarios;
	for( sc = 1; sc <= scenarios; sc++ ){

		cin >> dur >> prob;
		for( i = 0; i < prob; i++ )
			cin >> dif[i];
		
		pont[0] = solv[0] = 0;
		tm=0;
		while( tm <= dur && solv[0] < prob ){
			tm += dif[solv[0]];
			if( tm > dur ) break;
			solv[0]++;
			pont[0] += tm;
		}
	
		sort( dif, dif+prob, compare1 );	
		pont[1] = solv[1] = 0;
		tm=0;
		while( tm <= dur && solv[1] < prob ){
			tm += dif[solv[1]];
			if( tm > dur ) break;
			solv[1]++;
			pont[1] += tm;
		}

		sort( dif, dif+prob, compare );

		pont[2] = solv[2] = 0;
		tm=0;
		while( tm <= dur && solv[2] < prob ){
			tm += dif[solv[2]];
			if( tm > dur ) break;
			solv[2]++;
			pont[2] += tm;
		}
		
		int comp[3] = { 0, 1, 2 };
		sort( comp, comp+3, func );
		
		cout << "Cenario #" << sc << ":\n" << name[comp[0]] << " ganha, com " << solv[comp[0]] << " problemas resolvidos e pontuacao de " << pont[comp[0]] << ".\n\n"; 
	
	}

	return 0;
}


