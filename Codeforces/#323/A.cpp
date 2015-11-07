#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int m = n*n;

    bool f = false;
    set<int> xx, yy;

    for (int i = 1; i <= m; ++i) {
    	int x, y;
    	cin >> x >> y;
    	if (!xx.count(x) && !yy.count(y)) {
    		xx.insert(x);
    		yy.insert(y);
    		if (f) cout << " ";
    		cout << i;
    		f = true;
    	}
    }



	return 0;
}

















