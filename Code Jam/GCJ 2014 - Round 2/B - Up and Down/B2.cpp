#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int a[1024];
bool increasing;

int merge(int l, int m, int r){
     int x = m-l+1;
     int y = r-m;
     int res = 0;
     
     int b[x+1], c[y+1];
     for (int i = 0; i < x; i++) b[i] = a[l+i];
     b[x] = increasing ? ((int)2e9) : 0;
     for ( int i = 0; i < y; i++ ) c[i] = a[m+1+i];
     c[y] = increasing ? ((int)2e9) : 0;
     
     int i = 0;
     int j = 0;
     for (int k = l; k <= r; k++) {
         if (increasing) {
             if (b[i] > c[j]) {
                  a[k] = c[j++];
                  res += x-i;
             }
             else a[k] = b[i++];   
         } else {
             if (b[i] < c[j]) {
                  a[k] = c[j++];
                  res += x-i;
             }
             else a[k] = b[i++];
         }
     }
     return res;                
}
 
int mergesort(int l, int r){
     int res = 0;
     if (r > l) {
          int m = l+r;
          m >>= 1;
          res += mergesort(l, m);
          res += mergesort(m+1, r);
          res += merge(l, m, r );
     }
     return res;
}



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        int N;
        cin >> N;
        int AA[N];
        for (int i = 0; i < N; ++i) cin >> AA[i];
        
        int res = 2e9;
        for (int len = 0; len <= N; ++len) {
            
            for (int i = 0; i < N; ++i) a[i] = AA[i];

            increasing = true;
            int cur = mergesort(0, len-1);
            
            increasing = false;
            cur += mergesort(len, N-1);
            
            res = min(res, cur);
            
        }
        cout << "Case #" << kase << ": " << res << "\n";
    }

	return 0;
}

















