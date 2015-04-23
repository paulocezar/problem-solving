#include <iostream>
#include <algorithm>

#define MAXN 4100

using namespace std;

int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int sums[MAXN*MAXN];
    
int main(){
    
    ios::sync_with_stdio( false );
    
    int n, i, j, k;
    long long ans;
    pair<int*, int*> rng;

    cin >> n;
    
    for( i = 0; i < n; i++ )
         cin >> a[i] >> b[i] >> c[i] >> d[i];
    
    k = 0;
    for( i = 0; i < n; i++ )
         for( j = 0; j < n; j++ )
              sums[k++] = a[i]+b[j];
    sort( sums, sums+k );
    
    ans = 0ll;
    for( i = 0; i < n; i++ )
         for( j = 0; j < n; j++ ){
              rng = equal_range( sums, sums+k, -(c[i]+d[j]) );
              ans += rng.second - rng.first;
         }
    
    cout << ans << "\n";   
    
    return 0;    
}
