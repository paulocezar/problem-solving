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
    
    int N, V;
    while (cin >> N >> V && (N || V)) { 
    
        bool ok = false;
                
        while (!ok && V) {
            int cV = V--;
            int pos = 0;
            
            while (cV && !ok) {
                int cnt = cV;
                while (cnt--) {
                    pos += cV;
                    if (pos == N) {
                        ok = true;
                        break;
                    }
                }
                cV--;
            }
        }
        
        
        
        if (ok) cout << "possivel\n";
        else cout << "impossivel\n";
    }

	return 0;
}

















