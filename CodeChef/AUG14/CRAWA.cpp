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
    
    int t, x, y;
    cin >> t;
    while (t--) {
		cin >> x >> y;
		bool ok = false;
		
		ok |=  (((abs(y)%2) == 0) && (y <= 0) && (y <= x) && (x <= -y));
		ok |=  (((abs(x)%2) == 1) && (x > 0) && ((-x+1) <= y) && (y <= x));
		ok |=  (((abs(y)%2) == 0) && (y > 0) && ((-y+1) <= x) && (x <= (y-1)));
		ok |=  (((abs(x)%2) == 0) && (x < 0) && ((x+1) <= y) && (y <= -x));
		
		if (ok) cout << "YES\n";
		else cout << "NO\n";
    }

	return 0;
}






