#include <iostream>
#include <tr1/unordered_map>

using namespace std;

typedef long long int64;

tr1::unordered_map< int64, int > conftopos;
int at, pos, cur[6], postoconf[15504][6];
int64 val;

void gen(int rem) {
    if (at == 5) {
        cur[at] = rem;
        val = 0LL;
        for (int i = 0; i < 6; ++i) {
            val = 16LL*val + cur[i];
            postoconf[pos][i] = cur[i];
        }
        conftopos[val] = pos;
        pos++; 
    } else {
        at++;
        for (int i = 0; i <= rem; ++i) {
            cur[at-1] = i;
            gen(rem-i); 
        }
        at--;
    }
}


int main() {
    ios::sync_with_stdio(false);
    
    at = 0, pos = 0; gen(15);
    
    int tc = 1;
    char op;
    while (cin >> op && op != 'e') {
        switch (op) {
            case 'm':
                val = 0LL;
                for (int i = 0; i < 6; ++i) {
                    cin >> at; val = 16LL*val + at;
                }
                cout << "Case " << tc++ << ": " << conftopos[val] << "\n";
                break;
            case 'u':
                cin >> pos;
                cout << "Case " << tc++ << ":";
                for (int i = 0; i < 6; ++i) cout << " " << postoconf[pos][i];
                cout << "\n";
                break;
        }
    }
    
    return 0;
}