#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        // a11 + a22 = N
        // a12*a21 < d1 (a11*a22)
        long long res = 0;
        for (int a11 = 1; a11 < N; ++a11) {
            int a22 = N - a11;
            int d1 = a11*a22;

            for (int a12 = 1; a12*a12 < d1; ++a12) {
                int lo = a12;
                int hi = (d1-1)/a12;
                if (lo <= hi) {
                    int len = hi - lo + 1;
                    res += 2*len - 1;
                }
            }
        }
        cout << res << "\n";
            
    }

	return 0;
}

















