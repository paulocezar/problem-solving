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

int grid[4][4];

void read() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> grid[i][j];
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int cases;
    cin >> cases;
    for (int kase = 1; kase <= cases; ++kase) {
        int ans; cin >> ans;
        read();
        set<int> cand;
        for (int i = 0; i < 4; ++i) cand.insert(grid[ans-1][i]);
        set<int> res;
        cin >> ans;
        read();
        for (int i = 0; i < 4; ++i) if (cand.count(grid[ans-1][i])) res.insert(grid[ans-1][i]);
        cout << "Case #" << kase << ": ";
        if (res.size() == 1) cout << *res.begin() << "\n";
        else if (res.size() == 0) cout << "Volunteer cheated!\n";
        else cout << "Bad magician!\n";
    
    }

	return 0;
}

















