#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 INF = 1e9;
const int64 INF2 = 2e9;

string nm = "LMW";

int n;
int chng[32][3];
int tr[] = {3, 5, 6};

int64 cache[32][8];
char solved[32][8];

int64 solve(int at, int mask) {
	if (at == n) {
		cout << "acabou com " << mask << " " << (mask ? (-INF2) : 0) << endl;
		return (mask ? (-2e17) : 0);
	}

	int64 &res = cache[at][mask];
	if (solved[at][mask]) return res;
	res = -INF;
	solved[at][mask] = 1;
	for (int go = 0; go < 3; ++go) {
		int nmask = mask;
		int incr = 0;
		for (int bit = 0; bit < 3; ++bit) {
			if (tr[go] & (1<<bit)) {
				cout << bit << endl;
				if (abs(chng[at][bit]) & 1) nmask ^= (1<<bit);
				incr += chng[at][bit];
			}
		}
		cout << mask << " " << nmask;
		cout << endl;
		res = max(res, incr + solve(at+1, nmask));
	}
	cout << "return " << res << endl;
	return res;

}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < 3; ++j) {
    		cin >> chng[i][j];
    	}
    }
    
    int64 res = solve(0, 0);
    if (res != -INF) {
    	cout << res << endl;
    } else {
    	cout << "Impossible\n";
    }
	return 0;
}
