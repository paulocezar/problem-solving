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

#define MAXN 1024
int xa[MAXN], xb[MAXN], ya[MAXN], yb[MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> N >> M >> K;
        for (int i = 0; i < N; ++i) cin >> xa[i] >> ya[i];
        for (int i = 0; i < M; ++i) cin >> xb[i] >> yb[i];
        
        map<int, int> got;
        int ttl = 0;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                got[abs(xa[i]-xb[j]) + abs(ya[i]-yb[j])]++;
                ttl++;
                if (ttl > K) {
                    int bg = got.rbegin()->first;
                    got[bg]--;
                    if (!got[bg]) got.erase(bg);
                    ttl--;
                }
            }
        }
        
        int64 res = 0;
        for(map<int,int>::iterator it = got.begin(); it != got.end(); ++it) {
            res += int64(it->first) * int64(it->second);
        }
        cout << res << "\n";
    }

	return 0;
}

















