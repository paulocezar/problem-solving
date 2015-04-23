#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

typedef struct{
        int xing,ovo;
} result;

int comp( const void *a, const void *b ){
    
    result *ra = (result*)a;
    result *rb = (result*)b;

    if( ra->xing == rb->xing ) return rb->ovo - ra->ovo;
    else return ra->xing - rb->xing;
}

int main(){
    
    int n;
    int vit_xing, vit_ovo;
    int i, total;
    int countx, counto, a, b;
    result placares[8];
    
    scanf("%d", &n );
    while( n-- ){
    
           scanf("%d %d", &vit_xing, &vit_ovo );
           
           total = vit_xing+vit_ovo;
           countx = counto = 0;
           for( i = 0; i <  total; i++ ){
                scanf("%d %d", &placares[i].xing, &placares[i].ovo );
                a = placares[i].xing;
                b = placares[i].ovo;
                if( a != -1 && b != -1 ){
                    if( a > b ) countx++;
                    else counto ++;
                }
           }
           
           qsort( placares, total, sizeof( result ), comp );

           a = b = 0;
           for( i = 0; i < total; i++ ){
                
                /* Precisa definir a partida */
                if( placares[i].xing == -1 || placares[i].ovo == -1 ){
                    
                    
                    if( placares[i].xing == -1 ){
                        /* Xing nao tem placar */
                        
                        if( vit_xing - countx ){
                            /* Xing precisa vencer */
                            
                            if( placares[i].ovo == -1 ){
                                countx++;                            
                                /* como Xing e Ovo nao tem placar, fica o maior
                                  placar que Xing ganha */
                                  placares[i].xing = 20;
                                  placares[i].ovo = 18;
                            }
                            else{
                                 /* Ovo tem placar, entao xing ganha com o maximo
                                 possivel */
                                 if( placares[i].ovo+2 > 20 ){
                                     /* nao e possivel Xing ganhar, ovo ganha com o minimo possivel
                                        e xing marca o maximo possivel */
                                     counto++;
                                     if( placares[i].ovo == 11 ){
                                         placares[i].xing = 9;
                                     }
                                     else{
                                          placares[i].xing = placares[i].ovo - 2;
                                     }
                                 }
                                 else{
                                      countx++;
                                      if( placares[i].ovo < 9 ) placares[i].xing = 11;
                                      else placares[i].xing = placares[i].ovo + 2;
                                 }
                            }
                        
                        
                        } else {
                          /* Ovo precisa vencer */
                          counto++;
                          if( placares[i].ovo == -1 ){
                              /* Ovo nao tem placar */
                              /* como nenhum tem placar, ovo vence com o minimo necessario
                                 e xing marca o maximo possivel */
                              placares[i].ovo = 11;
                              placares[i].xing = 9;
                          } else {
                            /* Ovo tem placar e xing nao, entao ovo vence com o placar atual,
                            e xing marca o maximo possivel */
                            placares[i].xing = placares[i].ovo -2;
                          }
                        }
                    
                    }
                    else{
                    /* Ovo não tem placar */
                       
                       if( vit_ovo - counto ){
                           /* Ovo precisa ganhar e nao tem placar 
                              entao ele ganha com o minimo */
                              counto++;
                              if( placares[i].xing < 10 ) placares[i].ovo = 11;
                              else placares[i].ovo = placares[i].xing + 2;
                       }
                       else{
                           /* Xing precisa ganhar e tem placar, entao ganha com
                             ovo marcando o minimo possivel */
                             countx++;
                             if( placares[i].xing == 11 ) placares[i].ovo = 0;
                             else if( placares[i].xing > 11 ) placares[i].ovo = placares[i].xing - 2;
                             
                       }
                       
                    }
                
                }
                
                a += placares[i].xing;
                b += placares[i].ovo;
                
           }
                     
           printf("%d %d\n", a, b );
    
    }
    
    return 0;    
}
