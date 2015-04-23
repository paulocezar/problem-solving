#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <cfloat>
#include <sstream>
#include <utility>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <bitset>

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)

#define PB push_back
#define MP make_pair

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3fffffffffll

using namespace std;

typedef long long int64;

class emp{
    public:
    int64 id, sal, h;
    
    emp(int64 aa = 0, int64 bb = 0, int64 cc = 0) : id(aa), sal(bb), h(cc) {}
    
    bool operator < (const emp& a) const {
        if(h != a.h) return h < a.h;
        if(sal != a.sal) return sal < a.sal;
        return id < a.id;
    }
};

class seila{
    public:
    int64 id, sal, h;
    
    seila(int64 aa = 0, int64 bb = 0, int64 cc = 0) : id(aa), sal(bb), h(cc) {}
    
    bool operator < (const seila& a) const {
        if(sal != a.sal) return sal < a.sal;
        if(h != a.h) return h < a.h;
        return id < a.id;
    }
};

vector<int> g[33333], parent, scnt;
int root;

void dfs(int u) {
    scnt[u] = 1;
    REP(i, int(g[u].size())) {
        int v = g[u][i];
        dfs(v);
        scnt[u] += scnt[v];
    }
}   

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int m, q;
        cin>>m>>q;
        vector<emp> vec(m);
        set<seila> yo;
        int num = 0;
        map<int, int> haha;
        
        REP(i, m) {
            cin>>vec[i].id>>vec[i].sal>>vec[i].h;
            yo.insert(seila(vec[i].id, vec[i].sal, vec[i].h));
            if(!haha.count(vec[i].id)) {
                haha[vec[i].id] = num++;
            }
        }
        
        parent.assign(num, -1);
        scnt.assign(num, 0);
        
        sort(vec.begin(), vec.end());
        
        REP(i, m) {
            yo.erase(seila(vec[i].id, vec[i].sal, vec[i].h));
            typeof(yo.begin()) it = yo.upper_bound(seila(-LINF, vec[i].sal, -LINF));
            if(it != yo.end()) {
                g[haha[it->id]].PB(haha[vec[i].id]);
                parent[haha[vec[i].id]] = it->id;
            } else {
                parent[haha[vec[i].id]] = -1;
                root = haha[vec[i].id];
            }
        }
        
        dfs(root);
        
        REP(i, q){
            int64 id;
            cin>>id;
            
            if(parent[haha[id]] == -1) {
                cout << 0;
            } else {
                cout << parent[haha[id]];
            }
            cout << " " << scnt[haha[id]]-1 << '\n';
        }
        
        REP(i, num) {
            g[i].clear();
        }
    }    
    return 0;
}
