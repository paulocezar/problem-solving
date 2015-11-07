#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
    	int a;
    	cin >> a;
    	cnt[a]++;
    }

    int must = n/k;
    int res = 0;
    for (auto &entry : cnt) {
    	if (entry.second > must) res += entry.second - must;
    }
    cout << res << "\n";

	return 0;
}
