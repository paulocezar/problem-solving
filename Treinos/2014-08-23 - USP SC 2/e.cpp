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

int x[50505];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int n, c, m;
        cin >> n >> c >> m;
        for (int i = 0; i < m; ++i) cin >> x[i];
        sort(x, x+m, greater<int>());
        
        int res = 0;
        int i = 0;
        while (i < m) {
            res += 2*x[i];
            i += c;
        }
        cout << res << "\n";
    }

	return 0;
}

















