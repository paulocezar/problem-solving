#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct pt
{
	int x, y, z;
} vet[60];

long long linha[51*51];
long long tirou;

bool v[51*51];
int m[51*51], m1[51];
int qtd, nlinhas;

int dfs( int a ){
	if( a < 0 ) return 1;
	if( v[a] ) return 0;
	v[a] = 1;
	for( int i = 0; i < qtd; i++ ) if( linha[a] & (1LL << i ) ){
		if( dfs( m1[i] ) ){
			m[a] = i; m1[i] = a;
			return 1;
		} 
	}
	return 0;
}

int dfsExp( int a ){
	for( int i = 0; i < nlinhas; i++ ) v[i] = 0;
	return dfs( a );
}

int bipMatch( ){
	int i = 0;
	int ans = 0;
	for( i = 0; i < nlinhas; i++ ) m[i] = -1;
	for( i = 0; i < qtd; i++ ) m1[i] = -1;
	int augment;
	do{
		int first = 1;
		augment = 0;
		for( i = 0; i < nlinhas; i++ ) if( m[i] < 0 ){
			if( first++ == 1 ) augment += dfsExp( i );
			else augment += dfs( i );
		}
		ans += augment;
	} while( augment );
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	
	cin >> qtd;
	
	int tc = 1;
	while (qtd) {
		
		for (int i = 0; i < qtd; ++i) {
			cin >> vet[i].x >> vet[i].y >> vet[i].z;
		}
		
		if (qtd == 1) {
			cout << "Target set " << tc++ << " can be cleared using only "<< 1 <<" shots.\n";
			cin >> qtd;
			continue;
		}
		
		memset(linha, 0, sizeof(linha));
		
		nlinhas = 0;
		long long det;
		for (int i = 0; i < qtd; ++i) {
			for (int j = i + 1; j < qtd; ++j) {
				linha[nlinhas] |= (1ll << i) | (1ll << j);
				
				for (int k = j + 1; k < qtd; ++k) {
					det = ((vet[i].x * vet[j].y * vet[k].z) + (vet[j].x * vet[k].y * vet[i].z) +
						(vet[k].x * vet[i].y * vet[j].z)) -
						((vet[i].z * vet[j].y * vet[k].x) + (vet[j].z * vet[k].y * vet[i].x) + (vet[k].z * vet[i].y * vet[j].x));
						
					if (det == 0) {
						linha[nlinhas] |= (1ll << k);
					}
				}
				nlinhas++;
			}
		}
		
		
		cout << "Target set " << tc++ << " can be cleared using only "<< bipMatch() <<" shots.\n";
		
		cin >> qtd;
	}
	
	return 0;
}