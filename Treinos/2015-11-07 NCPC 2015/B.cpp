#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int n;
bool at_end[16];

void gen(deque<int> &cur) {
	int len = cur.size();
	if (len == n) {
		for (int i = 0; i < n; ++i) {
			if (i) cout << " ";
			cout << cur[i];
		}
		cout << "\n";
	} else {
		int nxt = len+1;
			
		if (at_end[nxt]) cur.push_back(nxt);
		else cur.push_front(nxt);

		gen(cur);

		int pos = at_end[nxt] ? len : 0;
		int dir = at_end[nxt] ? -1 : +1;

		for (int i = 0; i < len; ++i) {
			swap(cur[pos], cur[pos+dir]);
			pos += dir;
			gen(cur);
		}

		if (at_end[nxt])cur.pop_front();
		else cur.pop_back();
			
		at_end[nxt] = !at_end[nxt];
	}
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) at_end[i] = true;

    deque<int> empty;
    gen(empty);

	return 0;
}
