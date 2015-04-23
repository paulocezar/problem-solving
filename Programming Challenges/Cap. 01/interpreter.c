#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int registers[10];
    char ram[1000][3];
    int cases, instructions;
    int ramPointer;
    int aux, newRegVal;
    char newRamVal[3];
    char halt;
    
    scanf("%d", &cases ); getchar();getchar();
    while( cases-- ){
           instructions = 0;
           ramPointer = 0;
           memset( ram, '0', sizeof( ram ) );
           memset( registers, 0, sizeof( registers ) );
           
           while( gets( ram[ramPointer] ) ){
                  if( ram[ramPointer][0] == 0 ){
                       ram[ramPointer][0] = '0';
                       break;
                  } 
                  ramPointer++;
           }
           
           ramPointer = halt = 0;
           while( !halt ){
                  instructions++;
                  switch( ram[ramPointer][0] ){
                          case '1':
                                   halt = 1;
                                   break;
                          case '2':
                                   registers[ram[ramPointer][1]-'0'] = ram[ramPointer][2]-'0'; 
                                   break;
                          case '3':
                                   registers[ram[ramPointer][1]-'0'] += ram[ramPointer][2]-'0';
                                   registers[ram[ramPointer][1]-'0'] %= 1000;
                                   break;
                          case '4':
                                   registers[ram[ramPointer][1]-'0'] *= ram[ramPointer][2]-'0';
                                   registers[ram[ramPointer][1]-'0'] %= 1000;
                                   break;
                          case '5':
                                   registers[ram[ramPointer][1]-'0'] = registers[ram[ramPointer][2]-'0'];
                                   break;
                          case '6':
                                   registers[ram[ramPointer][1]-'0'] += registers[ram[ramPointer][2]-'0'];
                                   registers[ram[ramPointer][1]-'0'] %= 1000;
                                   break;
                          case '7':
                                   registers[ram[ramPointer][1]-'0'] *= registers[ram[ramPointer][2]-'0'];
                                   registers[ram[ramPointer][1]-'0'] %= 1000;
                                   break;
                          case '8':
                                   newRegVal = ram[registers[ram[ramPointer][2]-'0']][2]-'0';
                                   newRegVal += 10*(ram[registers[ram[ramPointer][2]-'0']][1]-'0');
                                   newRegVal += 100*(ram[registers[ram[ramPointer][2]-'0']][0]-'0');
                                   registers[ram[ramPointer][1]-'0'] = newRegVal;
                                   break;
                          case '9':
                                   aux = registers[ram[ramPointer][1]-'0'];
                                   newRamVal[0] = ( aux / 100 ) + '0';
                                   aux %= 100;
                                   newRamVal[1] = ( aux / 10 ) + '0';
                                   aux %= 10;
                                   newRamVal[2] = aux+ '0';
                                   ram[registers[ram[ramPointer][2]-'0']][0] = newRamVal[0];
                                   ram[registers[ram[ramPointer][2]-'0']][1] = newRamVal[1]; 
                                   ram[registers[ram[ramPointer][2]-'0']][2] = newRamVal[2];
                                   break;
                          case '0':
                                   if( registers[ram[ramPointer][2]-'0'] )
                                       ramPointer = registers[ram[ramPointer][1]-'0']-1;
                                   break;
                          default:
                                   break;
                  }
                  ramPointer++;
           }
           
           printf("%d\n", instructions );
           if( cases ) printf("\n");
    }       
    
    return 0;
}
