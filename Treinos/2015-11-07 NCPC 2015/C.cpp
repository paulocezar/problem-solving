#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    string per = "PER";
    string s;
    cin >> s;

    int ans = 0;
    int idx = 0;
    for (char c : s) {
    	if (c != per[idx]) ans++;
    	idx++;
    	if (idx == 3) idx = 0;
    }
    cout << ans << "\n";

	return 0;
}
