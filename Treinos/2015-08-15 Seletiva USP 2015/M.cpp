#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bool doit(string& s, bool print = false) {
    int last = -1, f = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'D') {
            if (print) {
                for (int j = i; j > last; --j) {
                    if (f) cout << " ";
                    cout << j+1;
                    f++;
                }
            }
            last = i;
            if (i+1 < n) s[i+1] = (s[i+1] == 'B') ? 'D' : 'B';
        }
    }
    if (print) cout << "\n";
    return ((last+1) == n);
}
    
int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t, n;
    string s, s2;
    
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        s2 = s;
        if (doit(s)) {
            cout << "Y\n";
            doit(s2, true);
        } else cout << "N\n";
        
    }
    
	return 0;
}


