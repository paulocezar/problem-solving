#include <string>
#include <iostream>

using namespace std;

int cnt[256];

int main() {
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    for (size_t i = 0, sz = s.size(); i < sz; ++i) cnt[s[i]]++;
    cout << cnt['A'] << " " << cnt['C'] << " " << cnt['G'] << " " << cnt['T'] << "\n";
    
    return 0;
}