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
int seq[40004];
int send[40004];

int main(){
    ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		REP(i,n) cin >> seq[i];
		send[1] = 0;
		int sz = 1;
		FOR(i,1,n-1) {
			int lo = 0, hi = sz;
			while (lo < hi) {
				int mid = (lo+hi+1)/2;
				if (seq[send[mid]] <= seq[i]) lo = mid;
				else hi = mid-1;
			}
			if (lo == sz) send[++sz] = i;
			else if (seq[i] < seq[send[lo+1]]) send[lo+1] = i;
		}
		cout << sz << "\n";
	}
    return 0;
}
