#include <iostream>
#include <string>

using namespace std;

string s[1024];

inline bool palin(string s) {
    int i = 0, j = int(s.size()) - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    
    int kases;
    cin >> kases;
    for (int kase = 1; kase <= kases; ++kase) {
        int N; cin >> N;
        int res = 0;
        for (int i = 0; i < N; ++i) {
            cin >> s[i];
            for (int j = 0; j < i; ++j) {
                if (palin(s[i] + s[j])) res++;
                if (palin(s[j] + s[i])) res++;
            }
        }
        cout << "Case #" << kase << ": " << res << "\n"; 
    }
    
    return 0;
}