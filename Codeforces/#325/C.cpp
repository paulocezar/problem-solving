#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int v[4096], d[4096], p[4096];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> v[i] >> d[i] >> p[i];
    }

    vector<int> res;
    for (int i = 1; i <= n; ++i) {
    	if (p[i] < 0) continue;
    	res.push_back(i);
    	int redux = v[i];
    	int j = i+1;

    	queue<int> cries;
    	while (redux && j <= n) {
    		if (p[j] >= 0) {
    			p[j] -= redux;
    			if (p[j] < 0) cries.push(j);
    			redux--;
    		}
    		j++;
    	}

    	while (!cries.empty()) {
    		int cryin = cries.front(); cries.pop();
    		for (int j = cryin + 1; j <= n; ++j) {
    			if (p[j] >= 0) {
    				p[j] -= d[cryin];
    				if (p[j] < 0) cries.push(j);
    			}
    		}
    	}
    }

    cout << res.size();
    char sep = '\n';
    for (int &chld : res) {
    	cout << sep << chld;
    	sep = ' ';
    }
    cout << "\n";
    

	return 0;
}
