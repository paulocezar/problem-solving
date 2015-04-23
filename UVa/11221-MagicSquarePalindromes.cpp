#include <iostream>
#include <cmath>

using namespace std;

bool check(string &txt, int len) {
    
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            int a = i*len + j;
            int b = len*len - a - 1;
            int c = j*len + i;
            int d = len*len - c - 1;

            if (txt[a] != txt[b] || txt[a] != txt[c] || txt[a] != txt[d]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    
    int kases;
    cin >> kases; cin.ignore();

    for (int kase = 1; kase <= kases; ++kase) {
        string line;
        getline(cin, line);
        
        string msg = "";
        for (int i = 0; i < int(line.size()); ++i) {
            if ('a' <= line[i] && line[i] <= 'z') {
                msg += line[i];
            }
        }
        
        int len = sqrt(msg.size());
        cout << "Case #" << kase << ":\n";
        if ((len*len == int(msg.size())) && check(msg, len)) cout << len << "\n";
        else cout << "No magic :(\n";
                
    }
    
    return 0;
}