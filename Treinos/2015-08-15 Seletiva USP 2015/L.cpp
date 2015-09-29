#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    uint64 pw1[32], pw2[32];
    
    pw1[0] = pw2[0] = 1ULL;
    for (int i = 1; i <= 26; ++i) {
        pw1[i] = 26ULL * pw1[i-1];
        pw2[i] = 10ULL * pw2[i-1];
    }
    
    int t, c, d;
    cin >> t;
    while (t--) {
        cin >> c >> d;
        cout << ((c+d) ? (pw1[c] * pw2[d]) : 0) << "\n";
    }

	return 0;
}


