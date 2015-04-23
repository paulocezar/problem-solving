/*
ID: knightp2
PROG: milk
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

ofstream fout("milk.out");

#define MAXM 5001 
int P[MAXM], A[MAXM], id[MAXM];

bool comp(int a, int b) {
    if (P[a] != P[b]) return P[a] < P[b];
    return A[a] > A[b];
}

int main() {
    ifstream fin("milk.in");
	
    int N, M;
    fin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        fin >> P[i] >> A[i];
        id[i] = i;
    }
    sort(id,id+M,comp);
    
    int res = 0;
    int has = 0;
    int cur = 0;
    while (has < N) {
        int buy = min(N-has,A[id[cur]]);
        has += buy;
        res += buy*P[id[cur]];
        ++cur;
    }
    fout << res << "\n";
    
    
    return 0;
}
