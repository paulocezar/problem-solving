/*
 *  Problema: Who Said Crisis ? ( UVa 11448 )
 *  Tecnica Utilizada:  BigNum
 *	
 *		 Dados A e B imprimir A - B .. o detalhe e que A e B podem ser bem grandinhos. ;D	
 *      
 *  Dificuldade: Facil
 *	Complexidade:
 *				O( ? )
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#define SIZ 11000

using namespace std;

struct BigNum {
 
   int digit[SIZ];
   int len;

   BigNum();
   BigNum(char *);
       
	  /* metodos de inicializacao */
       BigNum& operator=(const BigNum &n);

      /* operacoes aritmeticas */
       BigNum operator-(BigNum &n);

      /* metodos de comparacao */
       bool operator>(BigNum &n);

       /* metodos auxiliares*/
	   void print();
};

BigNum::BigNum() {
   for (int i=0; i<SIZ; i++) digit[i] = 0;
       len = 1;
}

BigNum::BigNum(char *str) {
   int i, j;
   for (i=0; i<SIZ; i++) digit[i] = 0;

   j = strlen(str) - 1;
   i = 0;
   while (j >= 0) {
       digit[i] = str[j] - '0';
       j--;
       i++;
   }
	
	len = i;
}

BigNum& BigNum::operator=(const BigNum &n) {
       if (this != &n) {
               memcpy(this->digit,n.digit,sizeof(this->digit));
               len = n.len;
       }
       return *this;
}


/* Assumindo que n eh menor que this */
BigNum BigNum::operator-(BigNum &n) {
       BigNum res, n1, n2;

       n1 = *this;
       n2 = n;

       int carry = 0;
	   int maxLen;
	   if( n1.len > n2.len ) maxLen = n1.len;
	   else maxLen = n2.len;
	   int i = 0;

       for (i=0; i<maxLen || carry; i++) {
               carry = n1.digit[i] - n2.digit[i] - carry;
               if(carry >= 0) {
                       res.digit[i] = carry;
                       carry = 0;
               } else {
                       res.digit[i] = carry+10;
                       carry = 1;
               }
       }

       while(!res.digit[i] && i) i--;
       res.len = i+1;

       return res;
}

bool BigNum::operator>(BigNum &n) {
	int i;
	if( len > n.len ) i = len-1;
	else i = n.len-1;
	
   while (n.digit[i] == this->digit[i] && i>0) i--;
       return (this->digit[i]> n.digit[i]);
}


void BigNum::print() {
   int i = len-1;

   while (digit[i] == 0 && i > 0) i--;

   while (i >= 0) {
       putchar('0' + digit[i]);
       i--;
   }
}

char sa[SIZ], sb[SIZ];

int main(){
		
	int n;
	BigNum a, b, saldo;
	
	scanf("%d", &n );
	while( n-- ){
	
		scanf("%s %s", sa, sb );
		a = BigNum( sa );
		b = BigNum( sb );
		
		if( b > a ){
			saldo = ( b - a );
			printf("-"); saldo.print();
		} else {
			saldo = ( a - b );
			saldo.print();
		}
		puts("");
		
	}
   
    return 0;
}

