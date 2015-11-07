#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int a[512*512];
int seq[512], len;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int m = n*n;

    map<int, int> cnt;
    for (int i = 0; i < m; ++i) {
    	cin >> a[i];
    	cnt[a[i]]++;
    }

 	len = 0;
 	while (len < n) {
	    
	    int found = 0;
	    for (auto &el : cnt) {
 			if (el.second & 1) {
 				seq[len++] = el.first;
 				found++;
 			}
 		}

 		if (!found) {
 			int grt = cnt.rbegin()->first;
 			seq[len++] = grt;
 			seq[len++] = grt;
 			found += 2;
 		}

 		for (int i = len-found; i < len; ++i) {
 			cnt[seq[i]]--;
 			for (int j = i-1; j >= 0; --j) {
 				cnt[__gcd(seq[i], seq[j])] -= 2;
 			}
 		}

 		vector<int> rem;
 		for (auto &el : cnt) if (!el.second) {
 			rem.push_back(el.first);
 		}

 		for (int &val : rem) cnt.erase(val);

 	}


	for (int i = 0; i < n; ++i) {
		if (i) cout << " ";
		cout << seq[i];
	}

	cout << "\n";

	return 0;
}

















