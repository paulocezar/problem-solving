#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int P[32], C[32], F[32];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; ++tc) {
        int Gp, Gc, Gf;
        cin >> Gp >> Gc >> Gf;
        int N; cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> P[i] >> C[i] >> F[i];
        }
        bool found = false;
        for (int mask = (1<<N)-1; mask >= 0; --mask) {
            int Cp = 0, Cc = 0, Cf = 0;
            for (int i = 0, cmask = mask; i < N; ++i, (cmask>>=1)) {
                if (cmask & 1) Cp += P[i], Cc += C[i], Cf += F[i];
            }
            found = (Cp == Gp) && (Cc == Gc) && (Cf == Gf);
            if (found) break;        
        }
        cout << "Case #" << tc << ": " << (found ? "yes\n" : "no\n");
    }

	return 0;
}

















