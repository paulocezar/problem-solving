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

int l[512], r[512], a[512], b[512], n;

inline bool contained(int s, int e, int lo, int hi) {
    if (lo <= hi) return (s <= e) && (lo <= s) && (e <= hi);
    
    if (s <= e) return (((s >= lo) && (e >= lo)) || ((s <= hi) && (e <= hi)));
    return ((lo <= s) && (e <= hi));
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        int k, p;
        cin >> n >> k >> p;
        for (int i = 0; i < k; ++i) cin >> l[i] >> r[i];
        for (int i = 0; i < p; ++i) cin >> a[i] >> b[i];
        
        bool ok = true;
        
        for (int i = 0; (i < k) && ok; ++i) {
            ok = false;
            for (int j = 0; !ok && (j < p); ++j) {
                if (contained(l[i],r[i],a[j],b[j])) ok = true; 
            }
        } 
    
        if (ok) cout << "Yes\n";
        else cout << "No\n";
        
    }

	return 0;
}

















