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

#define MAXN 1000000

int d[MAXN], t[MAXN], id[MAXN];

bool comp(int a, int b) {
	return t[a] > t[b];
}


int main(){
    ios::sync_with_stdio(false);
	int n;
	while (cin >> n && n) {
		REP(i, n) { cin >> d[i] >> t[i]; id[i] = i; }	
		sort(id,id+n, comp);
		
		int last_free = t[id[0]]-d[id[0]];
		FOR(i, 1,n-1) {
			last_free = min(last_free-d[id[i]], t[id[i]]-d[id[i]]);
		}
		
		cout << last_free << "\n";
	}
    return 0;
}
