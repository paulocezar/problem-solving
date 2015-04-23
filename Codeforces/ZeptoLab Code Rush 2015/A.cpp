#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n; cin >> n;
    string s; cin >> s;
    bool ok = false;
    
    for (int len = 1; 4*len < n; ++len) {
        for (int i = 1; (i+4*len) <= n; ++i) {
            int j = 0;
            while (j < 5) {
                if (s[i+j*len-1] == '.') break;
                j++;
            }
            if (j == 5) { ok = true; break; }
        }
        if (ok) break;
    }
    
    if (ok) cout << "yes\n";
    else cout << "no\n";

	return 0;
}

















