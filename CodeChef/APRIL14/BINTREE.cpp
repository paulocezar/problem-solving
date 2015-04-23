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

int stk1[64], stk2[64], s1, s2;
                
int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    while (N--) {
        int i, j;
        cin >> i >> j;
        s1 = 0, s2 = 0;
        while (i) { stk1[s1++] = i&1; i >>= 1; }
        while (j) { stk2[s2++] = j&1; j >>= 1; }
        
        while (s1 && s2) {
            if (stk1[s1-1] == stk2[s2-1]) s1--, s2--;
            else break;
        }
        cout << s1+s2 << "\n";
    }

	return 0;
}

















