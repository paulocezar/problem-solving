#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIGITS 25  
#define PLUS 1  
#define MINUS -1  

typedef struct {  
        char digits[MAXDIGITS];  
        int signbit;  
        int lastdigit;  
} bignum;  
  
void print_bignum(bignum *);   
void stringToBignum(char *, bignum *);  
void initialize_bignum( bignum * );  
void subtract_bignum(bignum *, bignum *, bignum *);  
void add_bignum(bignum *, bignum *, bignum *);  
int compare_bignum(bignum *, bignum *);  
void zero_justify(bignum *);  
void divide_bignum(bignum *, bignum *, bignum *);  
  
int main(){
    
    bignum valor, aux, total;  
    int n, f, i, bill = 1;  
    char str[MAXDIGITS];  
    
    scanf("%d %d", &n, &f);
    while( n ) {  
           
        scanf("%s", &str );  
        stringToBignum( str, &valor );  

        for( i = 1; i < n; i++ ){
             scanf("%s", &str );  
             stringToBignum( str, &aux );
             
             add_bignum( &valor, &aux, &total );
             
             valor = total; 
        }
        
        printf("Bill #%d costs ", bill++ );
        print_bignum( &valor );  
        sprintf( str, "%d", f );
        stringToBignum( str, &aux );
        divide_bignum( &valor, &aux, &total );
        printf(": each friend should pay ");
        print_bignum(&total);  
        printf("\n\n");
        
        scanf("%d %d", &n, &f);
    }
    
    return 0;  
}  

void print_bignum(bignum *n){
     int i;
     
     if( n->signbit == MINUS ) printf("-");  
         for( i = n->lastdigit; i >= 0; i-- )  
              printf("%c",'0'+ n->digits[i]);  

}  
  
void stringToBignum(char * s, bignum *n){  
     int i;  
     int j = 0; 
     
     n->lastdigit = -1;  

     for(i=0; i<MAXDIGITS; i++)  
              n->digits[i] = (char) 0;  

     if(s[0] == '-') {  
           n->signbit = MINUS;  
           for( i = strlen(s)-1; i >= 1; i-- ){  
               n->lastdigit++;  
               n->digits[j++] = s[i]-'0';  
           }  
           n->lastdigit = strlen(s)-2;  
     }  
     else {  
          n->signbit = PLUS;  
          for( i = strlen(s)-1; i >= 0; i-- ){  
               n->lastdigit++;  
               n->digits[j++] = s[i]-'0';  
          }  
          n->lastdigit = strlen(s)-1;  
     }  
}  
  
void initialize_bignum( bignum *n ){
     stringToBignum("0",n);  
}  
  
void add_bignum(bignum *a, bignum *b, bignum *c){
     
     int carry;  
     int i;  
     
     initialize_bignum(c);  
     if( a->signbit == b->signbit )
         c->signbit = a->signbit;  
     else {  
         if( a->signbit == MINUS ){  
             a->signbit = PLUS;  
             subtract_bignum(b,a,c);  
             a->signbit = MINUS;  
         }  
         else {  
             b->signbit = PLUS;  
             subtract_bignum(a,b,c);  
             b->signbit = MINUS;  
         }  
         return;  
     }
     
     c->lastdigit = ( a->lastdigit > b->lastdigit ) ? a->lastdigit+1 : b->lastdigit+1;  
     carry = 0;  
  
     for(i=0; i<=(c->lastdigit); i++) {  
              c->digits[i] = (char) (carry+a->digits[i]+b->digits[i]) % 10;  
              carry = (carry + a->digits[i] + b->digits[i]) / 10;  
     }  

     zero_justify(c);  
}  
  
void subtract_bignum(bignum *a, bignum *b, bignum *c){
     
     int borrow;  
     int v;  
     int i;
     
     initialize_bignum(c);
     
     if( (a->signbit == MINUS) || (b->signbit == MINUS) ){  
         b->signbit = -1 * b->signbit;  
         add_bignum(a,b,c);  
         b->signbit = -1 * b->signbit;  
         return;  
     }
     
     if( compare_bignum(a,b) == PLUS ){
         
         subtract_bignum(b,a,c);
         c->signbit = MINUS;
         return;
     } 
     
     c->lastdigit = ( a->lastdigit > b->lastdigit ) ? a->lastdigit: b->lastdigit; 
     borrow = 0;  
     
     for( i = 0; i <= (c->lastdigit); i++ ){
           v = (a->digits[i] - borrow - b->digits[i]);
           if( a->digits[i] > 0 )  
               borrow = 0;  
           if( v < 0 ){
               v = v + 10;  
               borrow = 1;  
           }  
           c->digits[i] = (char) v % 10;  
     }
     
     zero_justify(c);  
}  
  
int compare_bignum( bignum *a, bignum *b ){
      
  int i;  
  
  if( (a->signbit == MINUS) && (b->signbit == PLUS) ) return(PLUS);  
  if( (a->signbit == PLUS) && (b->signbit == MINUS) ) return(MINUS);  
  
  if( b->lastdigit > a->lastdigit ) return ( PLUS * a->signbit );  
  if( a->lastdigit > b->lastdigit ) return ( MINUS * a->signbit );  
  
  for( i = a->lastdigit; i >= 0; i-- ){  
       if( a->digits[i] > b->digits[i] ) return( MINUS * a->signbit );  
       if( b->digits[i] > a->digits[i] ) return( PLUS * a->signbit );  
  }
  return 0;  
}  
  
void zero_justify(bignum *n){
     
     while( ( n->lastdigit > 0 ) && ( n->digits[ n->lastdigit ] == 0) )  
            n->lastdigit --;  
  
     if( ( n->lastdigit == 0 ) && ( n->digits[0] == 0 ) )  
         n->signbit = PLUS; 
}  
  
void digit_shift(bignum *n, int d ){  
     int i;  
     if( ( n->lastdigit == 0 ) && ( n->digits[0] == 0 ) ) return;  
     for( i = n->lastdigit; i >= 0; i-- )  
          n->digits[i+d] = n->digits[i];  
     for( i = 0; i < d; i++ ) n->digits[i] = 0;  
     n->lastdigit = n->lastdigit + d;  
}  
  
void divide_bignum( bignum *a, bignum *b, bignum *c ){  
     
     bignum row;  
     bignum tmp;  
     int asign, bsign;  
     int i,j;  
     
     initialize_bignum(c);  
     
     c->signbit = a->signbit * b->signbit;  
     
     asign = a->signbit;  
     bsign = b->signbit;  
     a->signbit = PLUS;  
     b->signbit = PLUS;  
  
     initialize_bignum(&row);  
     initialize_bignum(&tmp);  
     
     c->lastdigit = a->lastdigit;  
     
     for( i = a->lastdigit; i >= 0; i-- ){
          digit_shift(&row,1);  
          row.digits[0] = a->digits[i];  
          c->digits[i] = 0;  
          while( compare_bignum( &row, b ) != PLUS ){
                 c->digits[i] ++;  
                 subtract_bignum( &row, b, &tmp );  
                 row = tmp;  
          }  
     }
     
     zero_justify(c);
     a->signbit = asign;
     b->signbit = bsign;
       
}  
