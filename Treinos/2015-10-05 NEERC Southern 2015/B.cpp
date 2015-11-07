#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> vals;
vector<int> others;
vector<pair<int,int>> a;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
 
    a.resize(n);
    others.resize(n);
    vals.resize(2*n);

    for (int i = 0; i < n; ++i) {
    	cin >> a[i].first >> a[i].second;
    	if (a[i].first > a[i].second) swap(a[i].first, a[i].second);

    	vals[2*i] = a[i].first;
    	vals[2*i+1] = a[i].second;
    }

    sort(vals.begin(), vals.end());
    vals.resize(distance(vals.begin(), unique(vals.begin(), vals.end())));
	
	int64 best = 0;
	int w = 0, h = 0;
    for (int &ww : vals) {

    	others.clear();
    	for (auto &cake : a) {
    		if (cake.first >= ww) others.push_back(-cake.second);
    		else if (cake.second >= ww) others.push_back(-cake.first);
    	}
    	sort(others.begin(), others.end());

    	for (int i = 0; i < int(others.size()); ++i) {
    		int hh = -others[i];
    		int64 volume = int64(ww)*int64(hh)*int64(i+1);
    		if (volume > best) {
    			best = volume;
    			h = hh;
    			w = ww;
    		} 
    	}
    }

    cout << best << "\n" << w << ' ' << h << "\n";

	return 0;
}
