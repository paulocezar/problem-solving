#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    while (T--) {
        
        int N, last, cur, wrng = 0, ans = 0;
        
        cin >> N >> last;
        
        for (int i = 2; i <= N; ++i) {
            cin >> cur;
            if (cur != last) {
                if (wrng != (i-1)) ans++;
                ans++;
                wrng = i;
            }
            last = cur;
        }
        
        cout << ans << "\n";
    }

	return 0;
}

















