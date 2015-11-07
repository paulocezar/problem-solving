#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

pair<int,int> a[128];

int bit[1<<14];
int eats[1<<14];
int MX;

void up(int idx) {
	while (idx <= MX) {
		bit[idx]++;
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
    
    int n;
    cin >> n;

    int lo = 1, hi = 2e9;
    MX = -1;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i].second >> a[i].first;
    	a[i].second++, a[i].first++;
    	MX = max(MX, a[i].first);
    	hi = min(hi, a[i].first-a[i].second);
    }

    sort(a, a+n);

    while (lo <= hi) {
    	int mid = (lo+hi)>>1;
    	
    	for (int i = 1; i <= MX; ++i) eats[i] = 0, bit[i] = 0;

    	bool ok = true;

    	for (int i = 0; ok && (i < n); ++i) {
    		int has = a[i].first - a[i].second - get(a[i].first-1) + get(a[i].second-1);
    		
    		if (has >= mid) {
    			int ax = mid;
    			int j = a[i].second;
    			while (ax--) {
    				while (eats[j]) j++;
    				eats[j] = 1;
    				up(j);
    			}
    		} else ok = false;
    	}	

    	if (ok) {
    		lo = mid+1;
    	} else {
    		hi = mid-1;
    	}
    }

    cout << n*(lo-1) << "\n";


	return 0;
}
