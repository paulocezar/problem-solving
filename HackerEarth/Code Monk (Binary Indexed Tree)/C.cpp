#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXVAL 200000

int bit[MAXVAL+1];
int64 a[MAXVAL+1];

bool is_round(int64 val) {
	if (val < 0LL) return false;
	int last = val % 10LL;
	int first = 0;
	while (val) {
		first = val % 10LL;
		val /= 10LL;
	}
	return first == last; 
}

void updt(int idx, int val) {
	while (idx <= MAXVAL) {
		bit[idx]+=val;
		idx += (idx & -idx);
	}
}

int get(int idx) {
	int res = 0;
	while (idx > 0) {
		res += bit[idx];
		idx -= (idx & -idx);
	}
	return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
    	cin >> a[i];
    	if (is_round(a[i])) {
    		updt(i, +1);
    	}
    }

    int cmd, L, R;
    int64 val;
    while (Q--) {
    	cin >> cmd;
    	if (cmd == 1) {
    		cin >> L >> R;
    		cout << get(R) - get(L-1) << "\n";
    	} else {
    		cin >> L >> val;
    		if (is_round(a[L])) {
    			updt(L, -1);
    		}
    		a[L] = val;
    		if (is_round(val)) {
    			updt(L, +1);
    		}
    	}
    }

	return 0;
}
