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
    cout << fixed << setprecision(13);
    
    int cases;
    cin >> cases;
    
    for (int kase = 1; kase <= cases; ++kase) {
        double C, F, X, res, rate = 2.0;
        cin >> C >> F >> X;
        
        double farming = 0.0;
        res = X/rate;
        
        for (int farms = 0; farms <= 100000; ++farms) {
            res = min(res, farming + (X/rate));
            farming += (C / rate);
            rate += F;
        }
              
        cout << "Case #" << kase << ": " << res << "\n";
    }

	return 0;
}

















