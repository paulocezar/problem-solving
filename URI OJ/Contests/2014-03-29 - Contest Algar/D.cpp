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
    
    int t;
    cin >> t;
    while (t--) {
        string L; uint64 N;
        cin >> L >> N;
        
        uint64 alph = L.size();
        
        string res = "";
        
        while (N > 0ULL) {
            N -= 1ULL;
            res += L[N % alph];
            N /= alph;
        }
        
        int i = 0, j = res.size()-1;
        while (i < j) {
            swap(res[i], res[j]);
            i++, j--;
        }       
        
        cout << res << "\n";
        
    }

	return 0;
}

















