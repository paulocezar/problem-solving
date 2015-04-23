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


int has[128];
char calc[128][1<<10], last_calc;
int dp[128][1<<10];
int n, mod = 1000000007;;

int solve(int pos, int mask) {
    if (!mask) return 1;
    if (pos == 101) return 0;
    int &ret = dp[pos][mask];
    if (calc[pos][mask] != last_calc) {
        calc[pos][mask] = last_calc;
        int cand = mask & has[pos];
        ret = solve(pos+1,mask);
        while (cand) {            
            int cur = cand & -cand;
            ret += solve(pos+1,mask ^ cur);
            if (ret >= mod) ret -= mod;
            cand -= cur;
        }
    }
    return ret;    
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t, val;
    
    cin >> t;
    while (t--) {
        cin >> n; cin.ignore();
        for (int i = 1; i <= 100; ++i) has[i] = 0;
        for (int i = 0; i < n; ++i) {
            string line; getline(cin, line);
            istringstream in(line);
            while (in >> val) has[val] |= (1<<i);
        }
        last_calc++;
        cout << solve(1, (1<<n) -1) << "\n";
        
    }
    

	return 0;
}

















