#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int t[1<<18];

vector<int64> acm[1<<20];
vector<int> segt[1<<20];

void build(int node, int lo, int hi) {
	if (lo == hi) {
		segt[node].push_back(t[lo]);
		acm[node].push_back(int64(t[lo]));
	} else {
		
		int ls = (node<<1)+1;
		int rs = ls+1;
		int mid = (lo+hi)>>1;
		
		build(ls, lo, mid);
		build(rs, mid+1, hi);
		
		int64 ax = 0LL;
		int i1 = lo, i2 = mid+1;
		int j1 = 0, j2 = 0;
		
		while ((i1 <= mid) && (i2 <= hi)) {
			if (segt[ls][j1] <= segt[rs][j2]) {
				ax += int64(segt[ls][j1]);
				segt[node].push_back(segt[ls][j1]);
				acm[node].push_back(ax);
				j1++, i1++;
			} else {
				ax += int64(segt[rs][j2]);
				segt[node].push_back(segt[rs][j2]);
				acm[node].push_back(ax);
				j2++, i2++;
			}
		}
		while (i1 <= mid) {
			ax += int64(segt[ls][j1]);
			segt[node].push_back(segt[ls][j1]);
			acm[node].push_back(ax);
			j1++, i1++;
		}
		while (i2 <= hi) {
			ax += int64(segt[rs][j2]);
			segt[node].push_back(segt[rs][j2]);
			acm[node].push_back(ax);
			j2++, i2++;
		}
	}
}

vector<int> idx;
int last_day;
int n, m;

void findidx(int node, int lo, int hi) {
	if (lo > last_day) return;
	if (hi <= last_day) {
		idx.push_back(node); 
		return;
	}
	int ls = (node<<1) + 1;
	int rs = ls + 1;
	int mid = (lo+hi)>>1;
	findidx(ls,lo,mid);
	findidx(rs,mid+1,hi);
}

int param;
int64 worked_time() {
	idx.clear();
	findidx(0, 0, m-1);

	int64 works = 0LL;

	for (int &check : idx) {
		
		int pos = upper_bound(segt[check].begin(), segt[check].end(), param) - segt[check].begin();
		int len = segt[check].size();
		if (pos < len) {
			int discount = len - pos;
			works += acm[check][len-1];
			if (pos) works -= acm[check][pos-1];
			works -= (int64(discount)*int64(param));
		}

	}

	return works;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
    	cin >> t[i];
    }

    build(0, 0, m-1);

    for (int i = 0; i < n; ++i) {
    	if (i) cout << ' ';
    	
    	int64 needs;
    	cin >> param >> needs;

    	int lo = 1, hi = m;
    	int ans = 0;
    	while (lo <= hi) {
    		int mid = (lo+hi)>>1;
    		last_day = mid-1;
    		
    		if (worked_time() >= needs) {
    			ans = mid;
    			hi = mid-1;
    		} else {
    			lo = mid+1;
    		}
    	}
    	cout << ans;
    }
    cout << "\n";

	return 0;
}
