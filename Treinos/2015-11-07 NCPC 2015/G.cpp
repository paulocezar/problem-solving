#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

multiset<int> goblins_at[1<<14];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int g, ax, ay, r;

    cin >> g;
    for (int i = 0; i < g; ++i) {
    	cin >> ax >> ay;
    	goblins_at[ax].insert(ay);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
    	cin >> ax >> ay >> r;
    	int lo = max(ax-r, 0), hi = min(ax+r,10000);
    	for (int x = lo; x <= hi; ++x) {
    		int dx = x-ax;
    		int dy = sqrt(r*r - dx*dx);		
    		int l = ay-dy, r = ay+dy;
    		goblins_at[x].erase(goblins_at[x].lower_bound(l), goblins_at[x].upper_bound(r));
    	}
    }

    int ans = 0;
    for (int x = 0; x <= 10000; ++x) ans += goblins_at[x].size();
    cout << ans << "\n";

	return 0;
}
