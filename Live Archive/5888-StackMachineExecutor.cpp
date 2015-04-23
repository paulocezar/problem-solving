#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

typedef long long int64;
using namespace std;

#define MAXINSTR 100100
int op[MAXINSTR];
int param[MAXINSTR];

int getid(string &s) {
    switch (s[0]) {
        case 'N': return 0;
        case 'P': return 1;
        case 'I': return 2;
        case 'D': return ((s[1]=='U') ? 3 : 8);
        case 'S': return ((s[1]=='W') ? 4 : 6);
        case 'A': return 5;
        case 'M': return ((s[1]=='U') ? 7 : 9);
    }
    return 10;
}

int len;
bool incorrect_stk;

int64 mem[1024];
int msz;

int execute(int arg) {
    if (incorrect_stk) return 2e9;
    
    msz = 0;
    mem[msz++] = arg;
    
    int inst = 0;
    while (inst < len) {
        
        switch (op[inst]) {
            case 0: mem[msz++] = param[inst];
                    break;
            case 1: if (!msz) goto hell;
                    msz--;
                    break;
            case 2: if (!msz) goto hell;
                    mem[msz-1] = -mem[msz-1];
                    break;
            case 3: if (!msz) goto hell;
                    mem[msz] = mem[msz-1];
                    msz++;
                    break;    
            case 4: if (msz < 2) { msz = 0; goto hell; }
                    swap(mem[msz-1],mem[msz-2]);
                    break;
            case 5: if (msz < 2) { msz = 0; goto hell; }
                    mem[msz-2] += mem[msz-1]; msz--;
                    if (abs(mem[msz-1]) > 1e9) return 2e9;
                    break;
            case 6: if (msz < 2) { msz = 0; goto hell; }
                    mem[msz-2] -= mem[msz-1]; msz--;
                    if (abs(mem[msz-1]) > 1e9) return 2e9;
                    break;
            case 7: if (msz < 2) { msz = 0; goto hell; }
                    mem[msz-2] *= mem[msz-1]; msz--;
                    if (abs(mem[msz-1]) > 1e9) return 2e9;
                    break;
            case 8: if (msz < 2) { msz = 0; goto hell; }
                    if (mem[msz-1] == 0) return 2e9;
                    mem[msz-2] /= mem[msz-1]; msz--;
                    break;
            case 9: if (msz < 2) { msz = 0; goto hell; }
                    if (mem[msz-1] == 0) return 2e9;
                    mem[msz-2] %= mem[msz-1]; msz--;
                    break;
                    default: return 2e9;            
        }
        
        inst++;
    }
hell:    
    if (msz != 1) { incorrect_stk = true; return 2e9; }
    return mem[0];
}

int main() {
    ios::sync_with_stdio(false);
    
    string sop;
    while (cin >> sop && sop != "QUIT") {
        
        len = 0;
        op[len] = getid(sop);
        while (op[len] != 10) {
            if (!op[len]) cin >> param[len];
            len++;
            cin >> sop;
            op[len] = getid(sop);
        }
        
        incorrect_stk = false;
        
        int N;
        cin >> N;
        while (N--) {
            int arg; cin >> arg;
            int val = execute(arg);
            if (val == 2e9) cout << "ERROR\n";
            else cout << val << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}
