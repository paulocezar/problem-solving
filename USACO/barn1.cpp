/*
ID: knightp2
PROG: barn1
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

#define MAXC 201
int occ[MAXC];
bool gap[MAXC];

int main() {
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    
    int M, S, C;
    fin >> M >> S >> C;
    for (int i = 0; i < C; ++i) fin >> occ[i];
    sort(occ,occ+C);
    gap[C-1] = true;
    M = min(M,C);
    for (int rem = 0; rem < M-1; ++rem) {
        
        int bst = -1, ibst = -1;
        for (int i = 0; i < C; ++i) {
            if (gap[i]) continue;
            if (occ[i+1]-occ[i] > bst) {
                bst = occ[i+1]-occ[i];
                ibst = i;
            }
        }
        if (ibst == -1) return 1;
        gap[ibst] = true;        
    }
    int last = occ[0];
    int pos = 0;
    int res = 0;
    while (pos < C) {
        if (gap[pos]) {
            res += (occ[pos]-last+1);
            last = occ[pos+1];
        }
        ++pos;
    }
    fout << res << "\n";
    
    return 0;
}
