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

#define MAXN 1000010
int p[MAXN];
int N;
string s;

void doit() {
	p[0] = p[1] = 0;
	FOR(i,2,N) {
		int j = p[i-1];
		while (s[i-1] != s[j]) {
			if (j == 0) { j = -1; break; }
			j = p[j];
		}
		p[i] = ++j;
	}
}


int main(){
    ios::sync_with_stdio(false);
	int kase = 1;
	while (cin >> N && N) {
		cin >> s;
		doit();
		cout << "Test case #" << kase++ << "\n";
		FOR(i, 1, N) {
			if (i % (i-p[i])) continue;
			int opa = i / (i-p[i]);
			if (opa != 1) cout << i << " " << opa << "\n";
		}
		cout << "\n";
	}
    return 0;
}




