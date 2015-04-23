#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int cnt[26];

bool comp(int a, int b) {
    if (cnt[a] != cnt[b]) return (cnt[a] > cnt[b]);
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T; cin.ignore();
    while (T--) {
        
        for (int i = 0; i < 26; ++i) cnt[i] = 0;
        
        string alph; getline(cin, alph);
        string txt;  getline(cin, txt);
        char map[26];
        
        for (int i = 0; i < int(txt.size()); ++i) {
            if (isalpha(txt[i])) cnt[tolower(txt[i])-'a']++;
        }
        
        vector<int> sn;
        for (int i = 0; i < 26; ++i) if (cnt[i]) sn.push_back(i);
        
        sort(sn.begin(), sn.end(), comp);
        
        for (int i = 0; i < int(sn.size()); ++i) {
            map[sn[i]] = alph[25-i];
        }
        
        for (int i = 0; i < int(txt.size()); ++i) if (isalpha(txt[i])) {
            if (isupper(txt[i])) {
                txt[i] = map[tolower(txt[i])-'a']-'a'+'A';
            } else {
                txt[i] = map[tolower(txt[i])-'a'];
            }
        }
        cout << txt << "\n";
        
    }
    
    return 0;
}
