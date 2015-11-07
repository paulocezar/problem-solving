#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];


    map<int, vector<pair<int,int>> > ways;

	for (int i = 0; i < N; ++i) {
		int sum = 0;
		for (int j = i; j < N; ++j) {
			sum += a[j];
			ways[sum].push_back(make_pair(j,i));
		}
	}

	int happen = 0;
	vector<int> res;

	for (auto &num_ways : ways) {
		int val  = num_ways.first;
		auto ntrvl = num_ways.second;
		sort(ntrvl.begin(), ntrvl.end());
		int len = ntrvl.size();
		int last = ntrvl[0].first;
		int cnt = 1;
		for (int i = 1; i < len; ++i) {
			if (ntrvl[i].second > last) {
				last = ntrvl[i].first; cnt++;
			}
		}
		if (cnt > happen) {
			res.clear();
			happen = cnt;
		}
		if (cnt == happen) res.push_back(val);
	}

	cout << happen;
	char sep = '\n';
	for (int &val : res) {
		cout << sep << val;
		sep = ' ';
	}
	cout << "\n";

	return 0;
}
