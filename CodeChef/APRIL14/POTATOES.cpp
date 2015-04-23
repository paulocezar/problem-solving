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

#define MAXN 3000

bitset< MAXN+10 > bs;
vector< int > primes;

void sieve(){
	primes.clear();
	for (int i = 0; i <= MAXN; ++i) bs[i] = i&1;
	primes.push_back(2);
	for (int i = 3; i < MAXN; i+=2) if (bs[i]) {
		primes.push_back(i);
        for (int j = i*i; j <= MAXN; j+=i) bs[j] = false;
	}
}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    sieve();
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        cout << *upper_bound(primes.begin(), primes.end(), x+y) - (x+y) << "\n";
    }

	return 0;
}

















