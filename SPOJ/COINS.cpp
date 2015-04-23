/*
 *  Problema: 346. Bytelandian gold coins ( Spoj Classical )
 *  Tecnica Utilizada:  DP
 *	
 *		 DP Simples.. seja F( N ) o melhor valor que N pode gerar.
 *		 e claro ver que F( N ) = max( N, (F( N/2 ) + F( N/3 ) + F( N/4 ))  )	
 * 		Como N pode ser 1000000000 a dificuldade e o uso de memoria, o mais simples
 *		 e implementar uma solucao recursiva com memoization, usando um map da stl
 *		 para armazenar os valores ja calculados.
 *      
 *  Dificuldade: Facil
 *	Complexidade:
 *				O( N ) ??
 */

#include <iostream>
#include <map>

using namespace std;

map< int, long long > memo;

long long calc( long long N ){
	if( N <= 0 ) return 0;
	
	long long ret = memo[N];
	if( ret ) return ret;
	return memo[N] = max( N, calc( N/2ll )+calc( N/3ll )+calc( N/4ll ) );
}

int main(){
	
	long long n;
	ios::sync_with_stdio( false );
	
	while( cin >> n ) cout << calc( n ) << "\n";
	
	return 0;
}