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

struct node_t {
	node_t* chld[2];
	char val;
	node_t(char cc) {
		val = cc;
		chld[0] = chld[1] = NULL;
	}
};

string s;
int pos;

node_t* build() {
	if (s[pos] == '(') {
		node_t* res = new node_t(0);
		pos++;
		res->chld[0] = build();
		pos++;
		res->chld[1] = build();
		pos++;
		return res;
	} else {
		return (new node_t(s[pos++]));
	}
}

int main(){
    ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		pos = 0;
		node_t* root = build();
		int m;
		cin >> m;
		string msg;
		while (m--) {
			cin >> msg;
			node_t* cur = root;
			REP(i, int(msg.size())) {
				cur = cur->chld[msg[i]-'0'];
				if (cur->val) {
					cout << cur->val;
					cur = root;
				}
			}
			cout << "\n";
		}

	}
    return 0;
}
