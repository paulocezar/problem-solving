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

int p[128];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int D, I, B;
        cin >> D >> I >> B;
        for (int i = 0; i < I; ++i) cin >> p[i];
        int res = 0;
        for (int i = 0; i < B; ++i) {
            int qi; 
            cin >> qi;
            int cost = 0;
            while (qi--) {
                int idx, qtd; cin >> idx >> qtd;
                cost += p[idx]*qtd;
            }
            res = max(res, D/cost);
        }
        cout << res << "\n";
    }
    

	return 0;
}

















