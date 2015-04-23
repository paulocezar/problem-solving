#include <iostream>

using namespace std;

int a[2][22];
int n, cur, old;

bool allzeroes() {
    for (int i = 0; i < n; ++i) if (a[old][i] != 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    
    int t;
    
    old = 0;
    cur = 1;
    
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[old][i];
        
        int P = 0;
        while (!allzeroes() && n > 1) {
         
            for (int i = 0; i < n-1; ++i) {
                a[cur][i] = a[old][i+1] - a[old][i];
            }
            P++;
            cur = !cur;
            old = !old;
            n--;
        }
        
        if (allzeroes()) {
            for (int i = 0; i < P; ++i) cout << "z";
            cout << "ap!\n";
        } else {
            if (a[old][0] < 0) cout << "*bunny*\n";
            else cout << "*fizzle*\n";
        }
        
        
    }
    
    return 0;
}