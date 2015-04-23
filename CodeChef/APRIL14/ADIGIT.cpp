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

int cnt[10][100001];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m, x;
    string a;
    
    cin >> n >> m;
    cin >> a;
    
    for (int i = 0; i < 10; ++i) cnt[i][0] = 0;
    
    for (int i = 0; i < int(a.size()); ++i) {
        for (int j = 0; j < 10; ++j) cnt[j][i+1] = cnt[j][i];
        cnt[a[i]-'0'][i+1]++;
    }

    while (m--) {
        cin >> x; x--;
        int res = 0;
        for (int i = 0; i < 10; ++i) res += cnt[i][x]*abs(a[x]-'0'-i);
        cout << res << "\n";
    }
	
    return 0;
}

















