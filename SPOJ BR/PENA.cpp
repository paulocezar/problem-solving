#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <list>
#include <string>

using namespace std;

struct task{
       int id;
       int ini;
       int fim;
};

bool comp( task a, task b ){
     if( a.fim < b.fim ) return true;
     if( a.fim == b.fim && a.ini < b.ini ) return true;
     return false;
}

int pontos[10010];
int solucao[1440];

int main(){

    int n;
    
    string dias[5];
    int melhor[5];
    
    int i, j, ponto, inih, inim, fimh, fimm, faz;
    char _dia[5];
    string dia;
    task t;
    
    list< task >::iterator it;
       
    dias[0] = "Seg"; dias[1] = "Ter"; dias[2] = "Qua";
    dias[3] = "Qui"; dias[4] = "Sex";

    while( true ){

           scanf("%d", &n );
           if( n == 0 ) return 0;
           
           map< string, list< task > > tarefas;    
           
           for( i = 0; i < n; i++ ){
                scanf("%d %d %s %2d:%2d %2d:%2d", &t.id, &ponto, &_dia, &inih, &inim, &fimh, &fimm );
                dia = string( _dia );
                t.ini = inih*60 + inim;
                t.fim = fimh*60 + fimm;
                
                tarefas[dia].push_back( t );
                pontos[t.id] = ponto;
           }
           
           for( i = 0; i < 5; i++ ){
                dia = dias[i];
                tarefas[dia].sort( comp );
                solucao[0] = 0;
                it = tarefas[dia].begin();
                for( j = 1; j < 1440; j++ ){
                     solucao[j] = solucao[j-1];
                     while( it != tarefas[dia].end() && it->fim == j ){
                          faz = pontos[it->id] + solucao[it->ini];
                          if( faz > solucao[j] ) solucao[j] = faz;
                          it++;
                     }
                     if( solucao[j-1] > solucao[j] ) solucao[j] = solucao[j-1];
                     
                }
                melhor[i] = solucao[1439];
           }
           
           faz = 0;
           for( i = 0; i < 5; i++ ) faz += melhor[i];
           printf("Total de pontos: %d\n", faz );
           for( i = 0; i < 5; i++ ) printf("%s: %d\n", dias[i].c_str(), melhor[i] );
    
    }


    return 0;
}
