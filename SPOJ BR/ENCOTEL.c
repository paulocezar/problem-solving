#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char input[32];
    char output[32];
    int i;
    
    while( scanf("%s", input) != EOF ){
          
           i = 0; 
           while( input[i] != '\0' ){
                  switch( input[i] ){
                          case 'A':
                          case 'B':
                          case 'C':
                                   output[i] = '2';
                                   break;                          
                          case 'D':
                          case 'E':
                          case 'F':
                                   output[i] = '3';
                                   break;                          
                          case 'G':
                          case 'H':
                          case 'I':
                                   output[i] = '4';
                                   break;                          
                          case 'J':
                          case 'K':
                          case 'L':
                                   output[i] = '5';
                                   break;                          
                          case 'M':
                          case 'N':
                          case 'O':
                                   output[i] = '6';
                                   break;                          
                          case 'P':
                          case 'Q':
                          case 'R':
                          case 'S':
                                   output[i] = '7';
                                   break;                          
                          case 'T':
                          case 'U':
                          case 'V':
                                   output[i] = '8';
                                   break;                          
                          case 'W':
                          case 'X':
                          case 'Y':
                          case 'Z':
                                   output[i] = '9';
                                   break;
                          default:
                                  output[i] = input[i];
                                  break;
                  }
                  i++;
           }
           output[i] = '\0';
           printf("%s\n", output );
    }    
    
    return 0;
}
