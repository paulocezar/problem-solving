#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define MAXN 201000

using namespace std;

struct mdata {
       int val, idx;
       bool operator < ( const mdata &b ) const {
            return val < b.val;
       }
};

bool comp( const mdata &a, const mdata &b ){
     return a.idx < b.idx;
}


mdata a[MAXN];
long long tree[MAXN];

int main(){
    
    int t, n, i, nval;
    long long ans;
           
    scanf("%d", &t );
    while( t-- ){
           
           scanf("%d", &n );
           for( i = 0; i < n; i++ ){
                scanf("%d", &a[i].val );
                a[i].idx = i;
                tree[i] = 0ll;
           }
           tree[n] = 0ll;
           
           sort( a, a+n );
           
           nval = 1;
           for( i = 1; i < n; i++ ){
                while( a[i].val == a[i-1].val ){
                    a[i-1].val = nval;
                    i++;
                }
                a[i-1].val = nval++; 
           }
           a[i-1].val = nval;
           
           sort( a, a+n, comp );
           ans = 0ll;
                      
           for( i = 0; i < n; i++ ){
           
                long long sum = 0ll;
                int idx = a[i].val;
                while( idx > 0 ){
                       sum += tree[idx];
                       idx -= ( idx & -idx );
                }
                
                ans += ( (long long)i - sum );
                idx = a[i].val;
                while( idx <= n ){
                       tree[idx]++;
                       idx += ( idx & -idx );
                }
           
           }
           
           printf("%lld\n", ans );
    }


    return 0;    
}
