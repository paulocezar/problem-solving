#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> gr[10101];

int color[10101];

bool go(int u) {
    color[u] = 1;
    
    for (int i = 0; i < int(gr[u].size()); ++i) {
        int v = gr[u][i];
        if (color[v] == 0) {
            if (!go(v)) return false;
        } else if (color[v] == 1) {
            return false;
        }
    }
    
    return true;
    color[u] = 2;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        
        for (int i = 0; i < N; ++i) gr[i].clear();
        
        for (int i = 0; i < M; ++i) {
            int A, B; cin >> A >> B; A--, B--;
            gr[A].push_back(B);
        }
        
        for (int i = 0; i < N; ++i) {
            color[i] = 0;
            sort(gr[i].begin(), gr[i].end());
        	gr[i].resize(unique(gr[i].begin(), gr[i].end()) - gr[i].begin());
        }
        
        bool ok = true;
        for (int i = 0; ok && i < N; ++i) {
            if (color[i] == 0) ok = go(i);
        }   
        if (ok) cout << "NAO\n";
        else cout << "SIM\n";
    }

	return 0;
}

















