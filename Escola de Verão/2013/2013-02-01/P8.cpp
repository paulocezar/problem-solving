#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <cfloat>
#include <sstream>
#include <utility>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <bitset>

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)

#define PB push_back
#define MP make_pair

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3fffffffffll

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

#define MAXN 10000

int pa[MAXN];
int dg[MAXN];
int bx[MAXN];

int main(){
    ios::sync_with_stdio(false);
    
	int n;
	while (cin >> n && n) {
		REP(i, n) pa[i] = i;
		
		queue<int> q;
		REP(i,n) {
			int id; cin >> id; id--;
			
			cin >> bx[id];
			cin >> dg[id];
			REP(j, dg[id]) {
				int x; cin >> x; x--;
				pa[x] = id;
			}
			if (!dg[id]) q.push(id);
		}
		
		int res = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();			
			if (bx[u] != 1) {
				if (bx[u] < 1) {
					bx[pa[u]] -= 1-bx[u];
					res += 1-bx[u];
				} else {
					bx[pa[u]] += bx[u]-1;
					res += bx[u]-1;
				}
			}
			dg[ pa[u] ]--;
			if (!dg[pa[u]] && (pa[u] != u)) q.push(pa[u]);
		}
		cout << res << "\n";

	}

    return 0;
}
