#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k, ev = 0;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            int v; cin >> v;
            if (!(v&1)) ev++;
        }
        if (k == 0) {
            if (ev != n) cout << "YES\n";
            else cout << "NO\n";
        } else if (ev >= k) cout << "YES\n";
        else cout << "NO\n";
    }

	return 0;
}

















