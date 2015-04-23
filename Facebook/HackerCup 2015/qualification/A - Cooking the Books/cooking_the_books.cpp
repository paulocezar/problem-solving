#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        string x;
        cin >> x;
        string mx = x, mn = x;
        for (size_t i = 0; i < x.size(); ++i) {
            for (size_t j = i+1; j < x.size(); ++j) {
                swap(x[i], x[j]);
                if (x[0] != '0') mx = max(mx, x), mn = min(mn, x);
                swap(x[i], x[j]);
            }
        }
        cout << "Case #" << tc << ": " << mn << " " << mx << "\n"; 
    }

	return 0;
}

















