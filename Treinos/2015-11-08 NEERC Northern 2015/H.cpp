#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    ifstream in("hash.in");
    ofstream out("hash.out");

    vector<string> has = {"edHs", "fEHs", "edIT"};
    int n = 3;

    int k;
    in >> k;

    while (n < k) {
    	vector<string> expand(n*n);
    	int nn = 0;
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			expand[nn++] = has[i]+has[j];
    		}
    	}
    	n = nn;
    	has = expand;
    }

    for (int i = 0; i < k; ++i) out << has[i] << "\n";


	return 0;
}
