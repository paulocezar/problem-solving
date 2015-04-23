#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#define SIZE(x) int((x).size())

using namespace std;


int dp[2][1510];

int main() {
    ios::sync_with_stdio(false);
    
    string s1, s2;
    while (cin >> s1 >> s2) {
        
        
        int n1 = SIZE(s1);
        int n2 = SIZE(s2);
        
        if (n1 > n2) {
            swap(s1,s2);
            swap(n1,n2);
        }
        
        int best = 0;
        
        for (int dir = 0; dir < 2; ++dir) {
            
            int a = 0, b = n1-1;
            while (a < b) {
                swap(s1[a], s1[b]);
                a++; b--;
            }
            
            for (int ds = 0; ds < n1; ++ds) {
            
                int old = 0;
                int cur = 1;
                
                for (int j = 0; j <= n2; ++j) dp[old][j] = 0;
                
                int ii  = ds;            
                for (int i = n1-1; i >= 0; --i) {
                    dp[cur][n2] = 0;
                    
                    for( int j = n2-1; j >= 0; --j) {
                        dp[cur][j] = max(dp[old][j], dp[cur][j+1]);
                        if (s1[ii] == s2[j]) dp[cur][j] = max(dp[cur][j], 1 + dp[old][j+1]);
                    }
                    old = !old;
                    cur = !cur;
                    ++ii;
                    if (ii == n1) ii = 0;
                }
                
                best = max(best,dp[old][0]);
                
            }         
        }
        
        
        cout << 2*best << "\n";
    }

    
    return 0;
}