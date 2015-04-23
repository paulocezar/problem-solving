/*
 *  Problema: 
 *  Tecnica Utilizada: 
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

#include <iostream>
#include <cstdio>

using namespace std;

int graph[10][10];
int gr[10];
bool visited[10];
bool pzr[10];
long long a[10];
long long S;
int D;
bool printed;

void play( int at, int pos, int dig, long long val, long long sum ){
	
	sum += val;
	
	if( sum > S ) return;
	
	if( sum == S ){
		a[pos++] = val;
		
		if( pzr[0] && a[0] != 0ll ) printf("0");
		printf("%lld", a[0] );
		
		for( int i = 1; i < pos; i++ ){
			if( pzr[i] && a[i] != 0ll ) printf(" 0%lld", a[i] );
			else printf(" %lld", a[i] );
		}
		
		printf("\n");
		printed = true;
		pos--;
	}
	
	sum -= val;
	
	visited[at] = true;
	if( at == 0 && dig == 1 ) pzr[pos] = true;
	
	long long nval;
	int npos;
	
	if( dig == D ) { 
		dig = 0; 
		nval = 0;
		a[pos] = val;
		npos = pos+1;
		sum += val;
	} 
	else {
		nval = val;
		npos = pos;
	}
	
	for( int w = 0; w < gr[at]; w++ ){
		
		if( !visited[ graph[at][w] ] ){
			val = 10ll*nval + graph[at][w];
			play( graph[at][w], npos, dig+1, val, sum );
		}
		
	}
	
	visited[at] = false;
	if( at == 0 && pzr[pos] ) pzr[pos] = false;
	
}

void makeGraph();

int main(){
	
	int i, tst = 1;
	makeGraph();
	
	while( true ){
	
		scanf("%lld %d", &S, &D );
		if( S == (long long)D && D == -1 ) return 0;

		printf("#%d\n", tst++ );
		printed = false;
		
		for( i = 0; i < 10; i++ )
			play( i, 0, 1, i, 0 );
		
		if( !printed ) puts("impossivel");
	}

	return 0;
}

void makeGraph() {
	
	for( int j = 0; j < 10; j++ ) pzr[j] = false;
	
	graph[0][0] = 7;
	graph[0][1] = 8;
	graph[0][2] = 9;
	gr[0] = 3;
	visited[0] = false;
	
	graph[1][0] = 2;
	graph[1][1] = 4;
	graph[1][2] = 5;
	gr[1] = 3;
	visited[1] = false;
	
	graph[2][0] = 1;
	graph[2][1] = 3;
	graph[2][2] = 4;
	graph[2][3] = 5;
	graph[2][4] = 6;
	gr[2] = 5;
	visited[2] = false;
	
	graph[3][0] = 2;
	graph[3][1] = 5;
	graph[3][2] = 6;
	gr[3] = 3;
	visited[3] = false;
	
	graph[4][0] = 1;
	graph[4][1] = 2;
	graph[4][2] = 5;
	graph[4][3] = 7;
	graph[4][4] = 8;
	gr[4] = 5;
	visited[4] = false;
	
	graph[5][0] = 1;
	graph[5][1] = 2;
	graph[5][2] = 3;
	graph[5][3] = 4;
	graph[5][4] = 6;
	graph[5][5] = 7;
	graph[5][6] = 8;
	graph[5][7] = 9;
	gr[5] = 8;
	visited[5] = false;
		
	graph[6][0] = 2;
	graph[6][1] = 3;
	graph[6][2] = 5;
	graph[6][3] = 8;
	graph[6][4] = 9;
	gr[6] = 5;
	visited[6] = false;
	
	graph[7][0] = 0;
	graph[7][1] = 4;
	graph[7][2] = 5;
	graph[7][3] = 8;
	gr[7] = 4;
	visited[7] = false;
	
	graph[8][0] = 0;
	graph[8][1] = 4;
	graph[8][2] = 5;
	graph[8][3] = 6;
	graph[8][4] = 7;
	graph[8][5] = 9;
	gr[8] = 6;
	visited[8] = false;
	
	graph[9][0] = 0;
	graph[9][1] = 5;
	graph[9][2] = 6;
	graph[9][3] = 8;
	gr[9] = 4;
	visited[9] = false;
	
}