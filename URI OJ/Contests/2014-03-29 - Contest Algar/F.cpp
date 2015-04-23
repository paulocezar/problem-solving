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

const int64 mod = 1000000009LL;

int64 fat[100001];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    fat[0] = 1;
    for (int i = 1; i <= 100000; ++i) {
        fat[i] = (int64(i) * fat[i-1]) % mod;
    }

    int N;
    while (cin >> N && N) {
        
        cout << ((fat[N] * 833333341LL) % mod) << "\n";
        
    }

	return 0;
}

















