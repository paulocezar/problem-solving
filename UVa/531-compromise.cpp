/*
 *  Problema: Compromise ( UVa 531 )
 *  Tecnica Utilizada:  DP ( Longest Common Subsequence)
 *	
 *		 O problema quer a maior sequencia comum de palavras em dois textos.
 *		 Podemos pensar no texto como uma palavra, onde as palavras sao os
 *		 caracteres e usar o LCS para calcular a resposta..
 *			Lembrete.. X[1...M], Y[1...N], LCS[0...M][0...N]
 *
 *							0, i || j == 0
 *				LCS[i,j] = 	LCS[i-1][j-1] + 1, x[i-1] == y[j-1]	
 *      					max( LCS[i-1][j], LCS[i][j-1] )
 *
 *  Dificuldade: Facil
 *	Complexidade:
 *				O( M*N )
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#define MAXW 110

using namespace std;

string x[MAXW], y[MAXW], out[MAXW];
int lcs[MAXW][MAXW];

void backtrace( int i, int j, int pos ){
	if( i == 0 || j == 0 ) return;
	if( x[i-1].compare( y[j-1] ) == 0 ){
		backtrace( i-1, j-1, pos-1 );
		out[pos] = x[i-1];
	} else if( lcs[i][j-1] > lcs[i-1][j] )
		backtrace( i, j-1, pos );
	else
		backtrace( i-1, j, pos );
}

int main(){
	
	int cx, cy;
	int i, j;
	ios::sync_with_stdio( false );
	
	while( cin >> x[0] ){
		cx = cy = 0;
		while( x[cx].compare( "#" ) ){
			cx++;
			cin >> x[cx];
		}
		
		cin >> y[cy];
		while( y[cy].compare( "#" ) ){
			cy++;
			cin >> y[cy];
		}

		for( i = 0; i <= cx; i++ ) lcs[i][0] = 0;
		for( i = 0; i <= cy; i++ ) lcs[0][i] = 0;
		
		for( i = 1; i <= cx; i++ ){
			for( j = 1; j <= cy; j++ ){
				if( x[i-1].compare( y[j-1] ) == 0 ){
					lcs[i][j] = lcs[i-1][j-1] + 1;
				} else if( lcs[i-1][j] > lcs[i][j-1] ) lcs[i][j] = lcs[i-1][j];
				else lcs[i][j] = lcs[i][j-1];	
			}
		}
		
		backtrace( cx, cy, lcs[cx][cy]-1 );
		
		cout << out[0];
		for( i = 1; i < lcs[cx][cy]; i++ )
			cout << " " << out[i];
		cout << endl;
		
	}
	
	return 0;
}
