#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int v[50010];
int inf, sup, a;

int search(){
     if( inf > sup ) return -1;
	 if( inf == sup && v[inf] == a ) return inf;
     int mid = (inf+sup) / 2;
     
      if( v[mid] > a ) {
         sup = mid-1; return search();
     }
     if( v[mid] < a ) {
         inf = mid+1; return search();
     }
     return mid;  
}

int main(){
    
    int n, q, r, i;
    
    scanf("%d", &n );
    for( i = 0; i < n; i++ )
         scanf("%d", &v[i] );
         
    scanf("%d", &q );
    for( i = 0; i < q; i++ ){
         scanf("%d", &a );
         inf = 0; sup = n-1;
         r = search();
         
         if( r != -1 ) {
			 inf = r-1;
			 while( inf >= 0 && v[inf] == a ) inf--;
			 
			 sup = r+1;
			 while( inf < n && v[sup] == a ) sup++;
			 
			 if( inf < 0 ) printf("X ");
             else printf("%d ", v[inf] );
			 
             if( sup < n ) printf("%d\n", v[sup] );
             else printf("X\n" ); 
         }
         else{
              
              if( inf > sup )
                  printf("%d %d\n", v[sup], v[inf] );
              else if( inf == sup ){
                   if( v[inf] > a ){
                       if( inf-1 >= 0 ) printf("%d %d\n", v[inf-1], v[inf] );
                       else printf("X %d\n", v[inf] );
                   }
                   else if( inf+1 < n ) printf("%d %d\n", v[inf], v[inf+1] );
                   else printf("%d X\n", v[inf] );
                   
              }
              else
                  printf("%d %d\n", v[inf], v[sup] );
                   
         }
    }     
    
    return 0;    
}
