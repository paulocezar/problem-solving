#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int qt, v1, v2;
    string nome1, par1, nome2, par2, outcome = "PI";
    char win;
    
    cin >> qt;
	while (qt--) {
    	cin >> nome1 >> par1 >> nome2 >> par2;
    	cin >> v1 >> v2;
    	v1 += v2;
    	win = outcome[v1&1];
    	if (par1[0] == win) cout << nome1 << "\n";
    	else cout << nome2 << "\n";
    }

	return 0;
}

















