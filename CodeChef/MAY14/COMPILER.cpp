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
    
    int T;
    cin >> T;
    while (T--) {
        string xpr;
        cin >> xpr;
        int res = 0;
        int acm = 0;
        
        for (int i = 0; i < int(xpr.size()); ++i) {
            if (xpr[i] == '<') acm++;
            else acm--;
            if (acm == 0) res = i+1;
            else if (acm < 0) break;
        }
        
        cout << res << "\n";
    }

	return 0;
}

















