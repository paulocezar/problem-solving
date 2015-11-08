#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    ifstream in("black.in");
    ofstream out("black.out");

    int b, w;
    in >> b >> w;
    
    char min_c, max_c;

    if (b <= w) {
    	min_c = '@', max_c = '.';
    } else {
    	min_c = '.', max_c = '@';
    	swap(b,w);
    }

    int rem = w-b;
    int r = 6*b, c = 3;
    if (rem > b) {
    	int xtr = rem - b;
    	int nc = (xtr+b-1) / b;
    	c = 3*(nc+1); 
    }

    out << r << " " << c << endl;
    string grid[r];
    char now = max_c, nxt = min_c;
    for (int i = 0; i < r; ++i) {
    	if ((i % 3) == 0) swap(now, nxt);
    	grid[i] = string(c, now);
    }
    
    int i = 1, j = 1;
    while (rem) {
    	grid[i][j] = max_c;
    	j += 3;
    	if (j >= c) {
    		j = 1;
    		i += 6;
    	}
    	rem--;
    }

    for (int i = 0; i < r; ++i) {
    	out << grid[i] << "\n";
    }

	return 0;
}
