#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
 
    char c;
    int i;
    vector< char >inter( 1000 );
    vector< char >::iterator it;
    
    while( (c = getchar()) != EOF ){
           multiset< char > a, b;
           
           while( c != '\n' ){
                a.insert( c );
                c = getchar(); 
           }
           
           c = getchar(); 
           while( c != '\n' && c ){
                b.insert( c );
                c = getchar();         
           }
           
           it = set_intersection( a.begin(), a.end(), b.begin(), b.end(), inter.begin() );
           i = it - inter.begin();
           for( it = inter.begin(); i; it++, i-- )
                printf("%c", *it );
           printf("\n");
           
    }
    
    return 0;
    
}
