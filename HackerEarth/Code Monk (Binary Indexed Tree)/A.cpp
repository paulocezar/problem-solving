#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int bit[26][100001];
int N;

void updt(int ltr, int idx, int val) {
	while (idx <= N) {
		bit[ltr][idx] += val;
		idx += (idx & -idx);
	}
}

int get(int ltr, int idx) {
	int res = 0;
	while (idx > 0) {
		res += bit[ltr][idx];
		idx -= (idx & -idx);
	}
	return res;
}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
	int Q;
	cin >> N >> Q;

	string s;
	cin >> s;
	for (int i = 0; i < N; ++i) {
		updt(s[i]-'a', i+1, +1);
	}    

	int cmd, L, R;
	char c;
	while (Q--) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> L >> c;
			updt(s[L-1]-'a', L, -1);
			updt(c-'a', L, +1);
			s[L-1] = c;
		} else {
			cin >> L >> R;
			int odd = 0;
			for (int i = 0; i < 26; ++i) {
				int has = get(i,R) - get(i, L-1);
				if (has & 1) odd++;
			}
			if (odd > 1) cout << "no\n";
			else cout << "yes\n";
		}
	}
    

	return 0;
}
