#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>

#define MAXN 310

using namespace std;

int n;
map< string, int > homem;
string nome[MAXN];

int quer[MAXN][MAXN];
int prefere[MAXN][MAXN];

int casa[MAXN], pretendente[MAXN];

  /* Entender porque garante uma solucao otima ? :) 
    http://en.wikipedia.org/wiki/Stable_marriage_problem */
void junta(){
     
     int i, j, _homem, mulher, outro;
     
     /* Inicialmente todo homem e mulher livre.. */
     for( i = 1; i <= n; i++ )
          casa[i] = 0, pretendente[i] = 1;
     
     for( i = 1; i <= n; i++ ){
          /* pega um homem livre */
          _homem = i;
          
          /* enquanto o homem tem alguma mulher pra propor.. */
          while( pretendente[_homem] <= n ){
                 /* pega a mulher que o homem mais quer */
                 mulher = quer[ _homem ][ pretendente[_homem]++ ];
                 
                 /* se a mulher nao esta livre */
                 if( casa[mulher] != 0 ){
                     /* pega o outro com quem ela esta junto */
                     outro = casa[mulher];
                     
                     /* verifica se ela prefere o que esta propondo ou quem ela estava junto */ 
                     for( j = 1; j <= n; j++ )
                          if( prefere[mulher][j] == _homem || prefere[mulher][j] == outro ) break;
                     
                     /* junta ela com o que ela prefere mais.. */     
                     casa[ mulher ] = prefere[mulher][j];
                     /* se o que ela preferia mais era o que estava propondo,
                       libera o outro pra fazer proposta pra nova pretendente */
                     if( casa[mulher] == _homem ) _homem = outro;
                 } else{
                     /* se ela estava livre junta ela com aquele que fez a proposta */
                     casa[ mulher ] = _homem;
                     break;       
                 }
          }
     }
     
}

int main(){
    
    int t;
    int i, j;
    ios::sync_with_stdio( false ); 
       
    cin >> t;
    while( t-- ){
         
         cin >> n;
         for( i = 1; i <= n; i++ ){
              cin >> nome[i];
              homem[ nome[i] ] = i;
              for( j = 1; j <= n; j++ )
                   cin >> quer[i][j];   
         }
         
         for( i = 1; i <= n; i++ ){
              for( j = 1; j <= n; j++ ){
                   cin >> nome[0];
                   prefere[i][j] = homem[ nome[0] ];
              } 
         }         
         
         junta(); 
         
         for( i = 1; i <= n; i++ )
              cout << nome[ casa[i] ] << endl;
         cout << endl;
           
    }

    return 0;    
}
