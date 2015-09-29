#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<string> name = {"RICHARD", "GABRIEL"};

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T, X, R, C;
    
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> X >> R >> C;
        
        int res = 0;
        if (X < 7) {
            if (((R*C) % X) == 0) res = 1;
            for (int L = 1; L < X; ++L) {
                int M = X-L+1;
                if (((L > R) || (M > C)) && ((M > R) || (L > C))) res = 0; 
            }
        }
        cout << "Case #" << tc << ": " << name[res] << "\n";
    }

	return 0;
}

















