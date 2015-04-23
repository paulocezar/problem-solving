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


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> votes(N+1, 0);
        int needed = M/2;
        while (M--) {
            int x; cin >> x;
            votes[x]++;
        }
        int win = -1;
        for (int i = 1; i <= N; ++i) if (votes[i] > needed) win = i;
        cout << win << "\n";
        
    }

	return 0;
}

















