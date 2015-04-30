#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);

    string s; cin >> s;
    int N = s.size();
    bool ok = false;
    
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            string ss = "";
            for (int x = 0; x < i; ++x) ss += s[x];
            for (int x = j+1; x < N; ++x) ss += s[x];
            if ("CODEFORCES" == ss) {
                ok = true; goto hell;
            }
        }
    }
hell:
    if (ok) cout << "YES\n";
    else cout << "NO\n";


	return 0;
}

















