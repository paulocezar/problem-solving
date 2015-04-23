#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    string key;
    while (cin >> key && key != "0") {
        string text;
        cin >> text;
        int j = 0;
        for (size_t i = 0, sz = text.size(); i < sz; ++i) {
            int ds = key[j]-'A'+1;
            int was = text[i]-'A';
            was += ds;
            was %= 26;
            text[i] = char(was+'A');
            
            j++; if (j == int(key.size())) j = 0;
        }
        
        cout << text << "\n";
    }
        
    return 0;
}

