#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int smax; string cnt;
        cin >> smax >> cnt;
        int standing = cnt[0] - '0';
        int invited = 0;
        for (int i = 1; i <= smax; ++i) {
            if (cnt[i] == '0') continue;
            if (standing < i) { invited += i-standing; standing = i; }
            standing +=  cnt[i]-'0';
        }
        cout << "Case #" << tc << ": " << invited << "\n";
    }
    

	return 0;
}

















