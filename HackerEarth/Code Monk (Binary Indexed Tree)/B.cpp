#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int mod = 1e9 + 7;

int bit[3][100001];
int MAXVAL;

void updt(int id, int idx, int val) {
	while (idx <= MAXVAL) {
		bit[id][idx] += val;
		bit[id][idx] %= mod;
		idx += (idx & -idx);
	}
}

int get(int id, int idx) {
	int res = 0;
	while (idx > 0) {
		res += bit[id][idx];
		res %= mod;
		idx -= (idx & -idx);
	}
	return res;
}

int a[100001];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    MAXVAL = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		MAXVAL = max(MAXVAL, a[i]);
	}

	// 0 - cnt
	// 1 - a < b > c < d
	// 2 - a > b < c > d

	updt(0, a[0], 1);
	
	for (int i = 1; i < N; ++i) {
		int smalr_before = get(0, a[i]-1);
		int gretr_before = i - get(0, a[i]);

		// append to type 1 if ended in smaller, creates type 2
		int type2 = get(1, a[i]-1);
		
		// append to type 2 if ended in greater, creates type 1
		int type1 = (((get(2, MAXVAL) - get(2, a[i]))%mod) + mod) % mod;
		
		// append to smaller, creates type 2
		updt(2, a[i], type2);
		updt(2, a[i], smalr_before);

		// append to greater, creates type 1
		updt(1, a[i], type1);
		updt(1, a[i], gretr_before);

		updt(0, a[i], 1);
	}

	cout << (get(1, MAXVAL) + get(2, MAXVAL))%mod << "\n";


	return 0;
}
