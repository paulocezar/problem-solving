#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cnt[27];

int main() {
    ios::sync_with_stdio(false);
    
    for (int i = 0; i < 4; ++i) {
        string line;
        getline(cin, line);
        for (int j = 0; j < int(line.size()); ++j)
            if ('A' <= line[j] && line[j] <= 'Z') cnt[line[j]-'A']++;
    }
    int mx = 0;
    for (int i = 0; i < 26; ++i) mx = max(mx, cnt[i]);
    for (int i = 0; i < 26; ++i) cnt[i] = mx - cnt[i];
    
    while (mx) {
        for (int i = 0; i < 26; ++i) {
            if (i) cout << " ";
            if (cnt[i]) { cout << " "; cnt[i]--; }
            else cout << "*";
        }
        cout << "\n";
        mx--;
    }
    for (int i = 0; i < 26; ++i) {
        if (i) cout << " ";
        cout << char('A'+i);
    }
    cout << "\n";
    
    
    
    
    
    return 0;
}