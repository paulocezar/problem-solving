#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int deg[1<<14], u[1<<17], v[1<<17]; 

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    ifstream fin("matrix.in");
    ofstream fout("matrix.out");
    
    int N, M;
    fin >> N >> M;
    for (int i = 0; i < M; ++i) {
        fin >> u[i] >> v[i];
        deg[u[i]]++;
        deg[v[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        ans += deg[u[i]] + deg[v[i]];
    }
    fout << ans << "\n";
    
    

	return 0;
}

















