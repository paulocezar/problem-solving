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

int rdr[512];
int nxt[512];
int cur[512];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            cin >> rdr[i];
            cur[rdr[i]] = 2e9;
        }
        for (int i = m-1; i >= 0; --i) {
            nxt[i] = cur[rdr[i]];
            cur[rdr[i]] = i;
        }
        
        memset(cur,0,sizeof(cur));
        
        int res = 0;
        set< pair<int,int> > q;
        for (int i = 0; i < m; ++i) {
            if (cur[rdr[i]]) {
                q.erase(make_pair(-nxt[cur[rdr[i]]-1], rdr[i]));
            } else {
                res++;
                if (q.size() == n) {
                    cur[q.begin()->second] = 0;
                    q.erase(q.begin());
                }
            }

            q.insert(make_pair(-nxt[i], rdr[i]));
            cur[rdr[i]] = i+1;
        }
        cout << res << "\n";
    }

	return 0;
}

















