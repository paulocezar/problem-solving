#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> gr[1<<19];

int cache[1<<19][2];
int assign[1<<19];

int doit(int u, int assigned = 0) {
    
    int &res = cache[u][assigned];
    if (res >= 0) return res;
   
    int sum = 0;
    for (auto v : gr[u]) {
        sum += doit(v);
    }
    
    if (assigned) {
        return res = (sum + 1);
    }     
    
    assign[u] = -1;
    res = sum;
    
    for (auto v : gr[u]) {
        int nw = sum - doit(v) + doit(v,1);
        if (nw > res) {
            res = nw;
            assign[u] = v;
        }
    }
    return res;
}

vector<int> ans;

void build(int u, int assigned = 0) {
    
    if (assigned) {
        ans.push_back(u);
        for (auto v : gr[u]) build(v);
        return;
    }
    
    if (assign[u] > 0) build(assign[u], 1);
    
    for (auto v : gr[u]) {
        if (v == assign[u]) continue;
        build(v);
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    ifstream fin("grant.in");
    ofstream fout("grant.out");
    
    int N, u;
    fin >> N;
    
    for (int v = 2; v <= N; ++v) {
        fin >> u;
        gr[u].push_back(v);
        cache[v][0] = cache[v][1] = -1;
    }
    cache[1][0] = -1;
    
    doit(1);
    
    ans.clear();
    build(1);
    
    sort(ans.begin(), ans.end());
    
    fout << 1000 * ans.size() << "\n";
    bool flg = false;
    for (auto v : ans) {
        if (flg) fout << " ";
        else flg = true;
        fout << v;
    }
    fout << "\n";
    

	return 0;
}

















