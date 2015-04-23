#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    while (T--) {
        string S; int n;
        cin >> S;
        cin >> n; n *= 12;
        
        int ds = 0;
        int i = 0;
        while (S[i] != '\0') {
            if (S[i] == 'T') ds+=2;
            else ds++;
            i++;
        }
        
        int ans = 0;
        i = ds;
        while (i < n) {
            ans += n-i;
            i += ds;
        }
        
        cout << ans << "\n";
    }
    
	return 0;
}

















