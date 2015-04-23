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
        string x;
        int t11, t21, t22, t12;
        
        int p1 = 0, p2 = 0;
        
        cin >> t11 >> x >> t21;
        if (t11 != t21) {
            if (t11 > t21) p1 += 3;
            else p2 += 3;
        } else p1++, p2++;
        
        cin >> t22 >> x >> t12;
        if (t12 != t22) {
            if (t12 > t22) p1 += 3;
            else p2 += 3;
        } else p1++, p2++;
                
        bool won1 = false;
        bool pen = false;
        
        if (p1 != p2) {
            if (p1 > p2) won1 = true;
        } else {
            if ((t11+t12) != (t21+t22)) {
                if ((t11+t12) > (t21+t22)) won1 = true;
            } else {
                if (t12 != t21) {
                    if (t12 > t21) won1 = true;
                } else pen = true;
            }
        }
        
        if (won1) cout << "Time 1\n";
        else if (pen) cout << "Penaltis\n";
        else cout << "Time 2\n";
        
    }

	return 0;
}

















