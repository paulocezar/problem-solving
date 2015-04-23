/*
ID: knightp2
PROG: crypt1
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int ok;

int cool(int x) {
    int len = 0;
    while (x) {
        if (ok & (1<<(x%10))) ++len;
        else return 0;
        x /= 10;
    }
    return len;
}
int main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    
    int n;
    fin >> n;
    
    ok = 0;
    for (int i = 0; i < n; ++i) {
        int dig; fin >> dig;
        ok |= (1<<dig);
    }
    
    int res = 0;
    for (int a = 1; a < 10; ++a) if (ok & (1<<a)) {
        for (int b = 0; b < 10; ++b) if (ok & (1<<b)) {
            for (int c = 0; c < 10; ++c) if (ok & (1<<c)) {
                for (int d = 1; d < 10; ++d) if (ok & (1<<d)) {
                    for (int e = 1; e < 10; ++e) if (ok & (1<<e)) {
                        int x1 = 100*a + 10*b + c;
                        int x2 = 10*d + e;
                        if ((cool(x1*d)==3) && (cool(x1*e)==3) && (cool(x1*x2)==4))
                            ++res;
                    }
                }
            }
        }
    }
    fout << res << "\n";
    
    return 0;
}
