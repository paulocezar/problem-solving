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
    
    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;
        int res = 0;
        for (int i = 0; i < int(a.size()); ++i) {
            res += (26+int(b[i]-a[i]))%26;
        }
        cout << res << "\n";
        
    }
    

	return 0;
}

















