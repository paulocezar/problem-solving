#include <iostream>
#include <string>

using namespace std;

int main(){

    int tam;
	char in[100];
    char numm[100];
	string num;
    
    do{
       gets(in);
       sscanf(in, "%d %s", &tam, &numm);
       num = numm;
       
       if( tam == 0 && num == "0")
             break;
             
       for( int c = 1; c <= 5; c++ ){
            switch( c ){
                   case 1: for( int i = 0; i < num.size(); i++ ){
                      if( i != 0 ) printf(" ");
                      switch( num[i] ){
                         case '2':
                         case '3':
                         case '5':
                         case '6':
                         case '7':
                         case '8':
                         case '9':
                         case '0': printf(" ");
                              for( int j = 0; j < tam; j++ )
                               printf("-");
                              printf(" ");
                            break;
                         case '1': printf(" ");
                              for( int k = 0; k < tam; k++ )
                               printf(" ");
                              printf(" ");
                              break;
                         case '4': printf(" ");
                            for( int j = 0; j < tam; j++ )
                               printf(" ");
                            printf(" ");
                            break;
                      }
                   }
                   printf("\n");
                   break;
                   
                   case 2: for( int i = 0; i < tam; i++ ){
                                for( int j = 0; j < num.size(); j++ ){
                                     if( j != 0 ) printf(" ");
                                     switch( num[j] ){
                                             case '1': printf(" ");
                                                  for( int k = 0; k < tam; k++ )
                                                       printf(" ");
                                                  printf("|");
                                                  break;
                                             case '2':
                                             case '3':
                                             case '7': printf(" ");
                                                  for( int k = 0; k < tam; k++ )
                                                       printf(" ");
                                                  printf("|");
                                                  break;
                                             case '4':
                                             case '8':
                                             case '9':
                                             case '0': printf("|");
                                                  for( int k = 0; k < tam; k++ )
                                                       printf(" ");
                                                  printf("|");
                                                  break;
                                             case '6':
                                             case '5': printf("|");
                                                  for( int k = 0; k < tam; k++ )
                                                       printf(" ");
                                                  printf(" ");
                                                  break;
                                     }
                                } printf("\n");
                           }
                           break;

                   case 3: for( int i = 0; i < num.size(); i++ ){
                                if( i != 0 ) printf(" ");
                                switch( num[i] ){
                                        case '2':
                                        case '3':
                                        case '4':
                                        case '5':
                                        case '6':
                                        case '8':
                                        case '9': printf(" ");
                                                  for( int j = 0; j < tam; j++ )
                                                       printf("-");
                                                  printf(" ");
                                                  break;
                                        case '1': printf(" ");
                                                  for( int k = 0; k < tam; k++ )
                                                       printf(" ");
                                                  printf(" ");
                                                  break;
                                        case '0': printf(" ");
                                                  for( int j = 0; j < tam; j++ )
                                                       printf(" ");
                                                  printf(" ");
                                                  break;
                                        case '7': printf(" ");
                                                  for( int j = 0; j < tam; j++ )
                                                       printf(" ");
                                                  printf(" ");
                                                  break;
                                }
                           } printf("\n");
                           break;

                   case 4: for( int i = 0; i < tam; i++ ){
                                for( int j = 0; j < num.size(); j++ ){
                                     if( j != 0 ) printf(" ");
                                     switch( num[j] ){
                                             case '1': printf(" ");
                                                       for( int k = 0; k < tam; k++ )
                                                            printf(" ");
                                                       printf("|");
                                                       break;
                                             case '2': printf("|");
                                                       for( int k = 0; k < tam; k++ )
                                                            printf(" ");
                                                       printf(" ");
                                                       break;
                                             case '3':
                                             case '4':
                                             case '5':
                                             case '7':
                                             case '9': printf(" ");
                                                       for( int k = 0; k < tam; k++ )
                                                            printf(" ");
                                                       printf("|");
                                                       break;
                                             case '6':
                                             case '8':
                                             case '0': printf("|");
                                                       for( int k = 0; k < tam; k++ )
                                                            printf(" ");
                                                       printf("|");
                                                       break;
                                     }
                                } printf("\n");
                           }
                           break;

                   case 5: for( int i = 0; i < num.size(); i++ ){
                                if( i != 0 ) printf(" ");
                                switch( num[i] ){
                                        case '1': printf(" ");
                                                  for( int k = 0; k < tam; k++ )
                                                       printf(" ");
                                                  printf(" ");
                                                  break;
                                        case '2':
                                        case '3':
                                        case '5':
                                        case '6':
                                        case '8':
                                        case '0':
                                        case '9': printf(" ");
                                                  for( int j = 0; j < tam; j++ )
                                                       printf("-");
                                                  printf(" ");
                                                  break;
                                        case '4':
                                        case '7': printf(" ");
                                                  for( int j = 0; j < tam; j++ )
                                                       printf(" ");
                                                  printf(" ");
                                                  break;
                                }
                           } printf("\n");
                           break;

            }
       }   
       printf("\n");

    } while ( true );

    return 0;
}
