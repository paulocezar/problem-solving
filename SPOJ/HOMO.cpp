#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){

    int n, val;
    int elements, repeated;
    elements = repeated = 0;
    char op[20];
    map< int, int > ct;
    
    scanf("%d", &n );
    while( n-- ){
    
           scanf("%s %d", op, &val );
           if( op[0] == 'i' ){
               if( !ct[val] ) elements++;       
               ct[val]++;
               if( ct[val] == 2 ) repeated++;
           } else {
               if( ct[val] ){
                   ct[val]--;
                   if( ct[val] == 1 ) repeated--;
                   if( ct[val] == 0 ) elements--;
               }
           } 
    
           if( elements ){
               
               if( elements == 1 ){
                   if( repeated ) puts("homo");
                   else puts("neither");
               } else if( repeated ) puts("both");
               else puts("hetero");
               
           } else puts("neither");
    
    }

    return 0;    
}
