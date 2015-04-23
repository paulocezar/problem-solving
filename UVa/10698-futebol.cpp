#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <map>

#define MAXT 30
#define MAXC 20

using namespace std;

typedef struct timee {
	string nome;
	char cnome[MAXC];
    int pontos, golsM, golsS, jogou;
};

int comp( const void *a, const void *b ){
	
    timee *t1 = (timee*)a;
	timee *t2 = (timee*)b;
    
    int r = t2->pontos - t1->pontos;
    if( r ) return r;
	
	r = ( t2->golsM - t2->golsS ) - ( t1->golsM - t1->golsS );
    if( r ) return r;
    
    r = t2->golsM - t1->golsM;
    if( r ) return r;
    
    return strcmp( t1->cnome, t2->cnome );
}


int main(){
    
	timee times[MAXT];
	int ntimes, jogos;
	int i, j, g1, g2, t1, t2, saldo;
	int rank, pontosAnt, saldoAnt, golsAnt;
	double aproveitamento;
	string _t1, _t2, trav;
	bool flag = true;
	
	while( 1 ){
           
        scanf("%d %d", &ntimes, &jogos );
        if( ntimes+jogos == 0 ) return 0;

		map<string, int> hash;

		for( i = 0; i < ntimes; i++){
			cin >> times[i].nome;

			times[i].pontos = 0;
			times[i].jogou = 0;
			times[i].golsM = 0;
			times[i].golsS = 0;
			
			j = 0;
			while( times[i].nome[j] ){
                   if( times[i].nome[j] >= 'A' && times[i].nome[j] <= 'Z' )
                        times[i].cnome[j] = times[i].nome[j] - 'A' + 'a';
                   else times[i].cnome[j] = times[i].nome[j];
                   j++;
            }
            times[i].cnome[j] = 0;

			hash[times[i].nome] = i;
		}

		for( i = 0; i < jogos; i++ ){

			cin >> _t1 >> g1 >> trav >> g2 >> _t2;

			t1 = hash[_t1];
			t2 = hash[_t2];

			if( g1 > g2 )
				times[t1].pontos += 3;
			else if( g2 > g1 )
				times[t2].pontos += 3;
			else{
				times[t1].pontos += 1;
				times[t2].pontos += 1;
			}

			times[t1].golsM += g1;
			times[t1].golsS += g2;

			times[t2].golsM += g2;
			times[t2].golsS += g1;

			times[t1].jogou++;
			times[t2].jogou++;
		}
		
		qsort( times, ntimes, sizeof( timee ), comp );

		rank = 0;
		pontosAnt = -1;
		saldoAnt = -1;
		golsAnt = -1;

		if( flag ) flag = false;
		else puts("");
		
		for( i = 0; i < ntimes; i++){
			
            saldo = times[i].golsM - times[i].golsS;

		    if( saldoAnt != saldo || pontosAnt != times[i].pontos || golsAnt != times[i].golsM ){
                rank = i+1;
                printf("%2d. ", rank );
                
				saldoAnt = saldo;
                pontosAnt = times[i].pontos;
				golsAnt = times[i].golsM;
			}
			else printf("    ");
			
            printf("%15s %3d %3d %3d %3d %3d ", times[i].nome.c_str(), times[i].pontos, times[i].jogou,
                                         times[i].golsM, times[i].golsS, saldo );

			if( times[i].jogou == 0) printf("%6s\n", "N/A" );
			else{
				aproveitamento = (100 * times[i].pontos) / (times[i].jogou * 3.0);
                printf("%6.2lf\n", aproveitamento );
			}
			
		}
	}
	
	return 0;
}
