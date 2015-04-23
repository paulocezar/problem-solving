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
    
    int N;
    while (cin >> N  && N) {
        
        int mx = -1, mxi = 0, smx = 0, smxi;
        
        for (int i = 1; i <= N; ++i) {
            int v; cin >> v;
            if (v > mx) {
                smx = mx, smxi = mxi;
                mx = v, mxi = i;
            } else if (v > smx) {
                smx = v, smxi = i;
            }
        }
        cout << smxi << "\n";
    }

	return 0;
}

















