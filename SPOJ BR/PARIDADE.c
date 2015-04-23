#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
     
     int num = 0, count = 0, i, sum = 0;
     
     scanf("%d", &num );
     
     while( num != 0 ){
            char buffer[33];
            sprintf( buffer, "%X", num );
            
            count = strlen( buffer );
            
            printf("The parity of ");
            for( i = 0; i<count; i++ ){
                 switch( buffer[i] ){
                         case '0':
                                  if( i == 0 )
                                      printf("0");
                                  else
                                      printf("0000");
                                  break;
                         case '1':
                                  if( i == 0 )
                                      printf("1");
                                  else
                                      printf("0001");
                                  sum++;
                                  break;
                        case '2':
                                  if( i == 0 )
                                      printf("10");
                                  else
                                      printf("0010");
                                  sum++;
                                  break;
                        case '3':
                                  if( i == 0 )
                                      printf("11");
                                  else
                                      printf("0011");
                                  sum += 2;
                                  break;
                        case '4':
                                  if( i == 0 )
                                      printf("100");
                                  else
                                      printf("0100");
                                  sum++;
                                  break;
                        case '5':
                                  if( i == 0 )
                                      printf("101");
                                  else
                                      printf("0101");
                                  sum+=2;
                                  break;
                        case '6':
                                  if( i == 0 )
                                      printf("110");
                                  else
                                      printf("0110");
                                  sum+=2;
                                  break;
                        case '7':
                                  if( i == 0 )
                                      printf("111");
                                  else
                                      printf("0111");
                                  sum+=3;
                                  break;
                        case '8':
                                      printf("1000");
                                  sum++;
                                  break;
                        case '9':
                                      printf("1001");
                                  sum+=2;
                                  break;
                        case 'A':
                                      printf("1010");
                                  sum+=2;
                                  break;
                        case 'B':
                                      printf("1011");
                                  sum+=3;
                                  break;
                        case 'C':
                                 printf("1100");
                                 sum+=2;
                                  break;
                        case 'D':
                                 printf("1101");
                                 sum+=3;
                                  break;
                        case 'E':
                                 printf("1110");
                                 sum+=3;
                                  break;
                        case 'F':
                                 printf("1111");
                                 sum+=4;
                                  break;
                         }
                 }
                 printf(" is %d (mod 2).\n", sum );
                 
           sum = 0;
           scanf("%d", &num );
     }
    
    return 0;
}
