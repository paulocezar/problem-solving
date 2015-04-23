#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int a[1<<12];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int nn = 1<<(n+1);
    
    for (int i = 2; i < nn; ++i) cin >> a[i];
    
    int mx = 0;
    for (int i = (1<<n); i < nn; ++i) {
        int lit = 0;
        int at = i;
        while (at > 1) {
            lit += a[at];
            at >>= 1;
        }
        a[i] = lit;
        mx = max(mx, lit);
    }
    
    for (int i = (1<<n); i < nn; ++i) {
        a[i] = mx-a[i];
    }
    
    int ans = 0;
    
    for (int lvl = n; lvl; --lvl) {
        int pairs = 1<<(lvl-1);
        int i = 1<<lvl;
        while (pairs) {
            ans += abs(a[i] - a[i+1]);
            a[i/2] = min(a[i], a[i+1]);
            pairs--;
            i+=2;
        }
    }
    
    cout << ans << "\n";
    
	return 0;
}

















