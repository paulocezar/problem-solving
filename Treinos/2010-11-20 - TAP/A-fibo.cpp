#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

#define MAX(A,B) (A)>(B)?(A):(B)
#define SIZ 1010

using namespace std;

struct BigInt {

   int digit[SIZ];
   int len;

   BigInt(){
       for( int i=0; i<SIZ; i++ ) digit[i] = 0;
       len = 1;
   }

   BigInt( char* str ){
      int i, j;
      for( i=0; i < SIZ; i++ ) digit[i] = 0;

      j = strlen(str) - 1;
      i = 0;
      while( j >= 0 ){
         digit[i] = str[j] - '0';
         j--;
         i++;
      }
      len = i;
   }
   
   BigInt& operator=(const BigInt &n){
       if( this != &n ){
           memcpy(this->digit,n.digit,sizeof(this->digit));
           len = n.len;
       }
       return *this;
   }
   BigInt& operator=(int n){
       char str[15];
       BigInt res;

       sprintf(str, "%d", n);
       res = BigInt(str);

       *this = res;

       return *this;
   }
   
   BigInt operator+(BigInt &n) {
       BigInt res;

       int i,carry = 0;
       int maxLen = MAX(this->len, n.len);

       for (i=0; i<maxLen || carry; i++) {
               carry += this->digit[i] + n.digit[i];
               res.digit[i] = carry % 10;
               carry /= 10;
       }
       res.len = MAX(this->len,i);

       return res;
  }
   
   void print( ){
        int i = len-1;

        while( digit[i] == 0 && i > 0 ) i--;

        while( i >= 0 ){
           putchar('0' + digit[i]);
           i--;
       }
    }

};

int main(){
    
    vector< BigInt > f;
    
    f.push_back( BigInt( "1" ) ); 
    f.push_back( BigInt( "1" ) );    
    f.push_back( BigInt( "1" ) );
    
    for( int i = 3; f[i-1].len <= 1000; i++ )
         f.push_back( f[i-1]+f[i-2] );

    int n;
    while( true ){
    
           scanf("%d", &n );
           if( n == 0 ) return 0;
           
           f[n].print();
           puts("");    
           
    }

    return 0;    
}
