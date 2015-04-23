#include <iostream>
#include <string>
#define MAX_A 21

using namespace std;

unsigned int amigos[MAX_A];
unsigned int mask[22];
unsigned int comissao;
int n, maior;

int numBitsLigados( unsigned int v ){
    int c = 0;
    unsigned s = 1;
    for( int i = 0; i < n; i++ ){
         if( ( v & s ) ^ 0 )
             c++;
         s <<= 1;
    }
    return c;      
}

void insereComissao( int a, int naComissao ){

	 if( naComissao > maior )
		maior = naComissao;
	 if( a > n )
	 	return;

	 bool pode = true;
	 for( int i = 1; i <= n; i++ ){
		if( mask[i] & comissao ){
			if( (mask[a] &  amigos[i]) == 0 || ( mask[i] & amigos[a] ) == 0  ){
				pode = false;
				break;
			}
		}
	}

	if( pode ){
		comissao |= mask[a];
		insereComissao( a+1, naComissao+1 );
		comissao ^= mask[a];
	}

	insereComissao( a+1, naComissao );
}

int main(){

       mask[0] = 0;
       mask[1] = 1;
       mask[2] = 2;
       mask[3] = 4;
       mask[4] = 8;
       mask[5] = 16;
       mask[6] = 32;
       mask[7] = 64;
       mask[8] = 128;
       mask[9] = 256;
       mask[10] = 512;
       mask[11] = 1024;
       mask[12] = 2048;
       mask[13] = 0x1000;
       mask[14] = 0x2000;
       mask[15] = 0x4000;
       mask[16] = 0x8000;
       mask[17] = 0x10000;
       mask[18] = 0x20000;
       mask[19] = 0x40000;
       mask[20] = 0x80000;
       mask[21] = 0xFFFFF; // A mascara de alguem que e amigo de todos..
    
    int teste = 1;
    
    while( 1 ){
     scanf("%d", &n );
     if( n == 0 ) break;        
         
         // inicia todo mundo sendo amigo de todos
         for( int i = 1; i <= n; i++ )
              amigos[i] = mask[21];

         for( int i = 1; i <= n; i++ ){
              while( 1 ){
                     int nao;
                     scanf("%d", &nao );
                     if( nao == 0 ) break;
                     
                     amigos[i] ^= mask[nao];
              }
         }

	// Faz comissao vazia..
	comissao = 0;
      	maior = 0;
	insereComissao( 1, 0 );
         
         printf("Teste %d\n%d\n\n", teste++, maior );        
           
           
    }    
    
    return 0;
}
