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

int a[1<<17];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, K, x, cur = 1;
    while (cin >> K >> N) {
        bool p = false;
        for (int i = 0; i < K; ++i) {
            cin >> x;
            if (a[x] != cur) {
                a[x] = cur;
                if (p) cout << " ";
                else p = true;
                cout << x;
            }
        }
        cur++;
        cout << "\n";
    }

	return 0;
}

















