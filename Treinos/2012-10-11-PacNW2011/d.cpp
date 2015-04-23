
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

typedef long long int64;

using namespace std;

struct pt {
    int64 x, y;
    explicit pt(int64 xx = 0, int64 yy = 0) : x(xx), y(yy) {}
    bool operator < (const pt &a) const  {
        if (y != a.y) return y < a.y;
        return x < a.x;
    }
    pt operator - (pt p) {
        return pt(x - p.x, y - p.y);
    }
    
    pt operator + (pt p) {
       return pt(x + p.x, y + p.y);
    }
    
    bool operator == (const pt& p) const{
       return ((x == p.x) && (y == p.y));
    }
};

int64 cross(pt a, pt b){
    return a.x*b.y - a.y*b.x;
}

int64 signed_area(pt a, pt b, pt c){
    return cross((a-c), (b-c));
}

int64 side_sign(pt a, pt b, pt c) {
    int64 sa = signed_area(a,b,c);
    if (sa < 0) return -1;
    else if (sa > 0) return 1;
    return 0;
}

#define MAXN 1000000
pt rect[MAXN][3];

vector< int64 > gr[MAXN];
int64 deg[MAXN];

int main() {
    ios::sync_with_stdio(false);
    int64 t;
    cin >> t;
    while (t--) {
        int64 n;
        cin >> n;
        map< pair<pt,pt>, vector<int64> > tr;
        for (int64 i = 0; i < n; ++i) {
            gr[i].clear();
            deg[i] = 0;
            for (int64 pp = 0; pp < 3; ++pp){
                cin >> rect[i][pp].x >> rect[i][pp].y;
            }
            sort(rect[i], rect[i]+3);
            tr[ make_pair(rect[i][0],rect[i][1]) ].push_back(i);
            tr[ make_pair(rect[i][1],rect[i][2]) ].push_back(i);
            tr[ make_pair(rect[i][0],rect[i][2]) ].push_back(i);            
        }
        
        map< pair<pt,pt>, vector<int64> >::iterator it;
        for (it = tr.begin(); it != tr.end(); ++it) {
            int64 dx = it->first.second.x - it->first.first.x;
            if (dx > 0) dx = 1;
            if (dx < 0) dx = -1;
            if (dx && int64(it->second.size()) == 2) {
                pt xx;
                int64 a = it->second[0];
                int64 b = it->second[1];
                for (int64 i = 0; i < 3; ++i) {
                    if ((rect[a][i] == it->first.first) || (rect[a][i] == it->first.second)) continue;
                    xx = rect[a][i];                    
                }
                int64 dir = side_sign(it->first.first,it->first.second,xx);
                if (dir == dx) {
                    gr[b].push_back(a);
                    deg[a]++;
                } else {
                    gr[a].push_back(b);
                    deg[b]++;
                }
            }
        }
        
        queue<int64> q;
        for (int64 i = 0; i < n; ++i) if (deg[i] == 0) q.push(i);
        bool first = true;
        while (!q.empty()) {
            if (!first) cout << " ";
            first = false;
            int64 u = q.front(); q.pop();
            cout << (u+1);
            for (int64 i = 0; i < int64(gr[u].size()); ++i) {
                int64 v = gr[u][i];
                deg[v]--;
                if (deg[v] == 0) q.push(v);
            }
        }
        cout << "\n";
    }
    return 0;
}