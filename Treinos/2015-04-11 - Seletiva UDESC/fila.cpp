#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int x[1<<20];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int E, F;
    while (cin >> E && E) {
        cin >> F;
        for (int i = 0; i < F; ++i) cin >> x[i];
        sort(x, x+F);
        x[F] = E + 1337; F = 0;
        int ret = 0;
        for (int i = 1; i <= E; ++i) {
            while (x[F] < i) { ret++; F++; }
            if (i > 1) cout << " ";
            cout << ret;
        }
        cout << "\n";
        
    }
    

	return 0;
}

















