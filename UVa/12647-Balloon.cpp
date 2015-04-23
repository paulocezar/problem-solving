#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 101101

int xlo[MAXN], xhi[MAXN], ylo[MAXN], yhi[MAXN];
int xres[MAXN], yres[MAXN];
pair<int,int> ev[MAXN];

vector< int > sons[MAXN];
int seen[MAXN], seen_now, N, C;

void propagate(int node, int stopx, int stopy) {
    if (node >= N) {
        xres[node-N] = stopx, yres[node-N] = stopy;
    } else {
        seen[node] = seen_now;
        for (int i = 0; i < int(sons[node].size()); ++i) {
            if (stopx == -1) {
                int son = sons[node][i];
                if (son >= N) yres[son-N] = stopy;
                else propagate(son, ((ylo[son] > yhi[son])?xlo[son]:xhi[son]),stopy);
            } else {
                propagate(sons[node][i], stopx, stopy);   
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    
    while (cin >> N >> C) {
        
        for (int i = 0; i < N; ++i) {
            sons[i].clear();
            cin >> xlo[i] >> ylo[i] >> xhi[i] >> yhi[i];
            if (xlo[i] > xhi[i]) {
                swap(xlo[i],xhi[i]);
                swap(ylo[i],yhi[i]);
            }
            ev[i].first = max(ylo[i],yhi[i]);
            ev[i].second = i;
        }
        sort(ev, ev+N);
        
        set< pair<int,int> > query;
        
        for (int i = 0; i < C; ++i) {
            int x; cin >> x;
            
            xres[i] = x; 
            yres[i] = -1;
            
            query.insert(make_pair(x,N+i));
        }
        
        seen_now++;
        for (int i = 0; i < N; ++i) {
            int seg = ev[i].second;
            
            set< pair<int,int> >::iterator it;
            it = query.upper_bound(make_pair(xlo[seg],-1));
            
            while (it != query.end() && (it->first <= xhi[seg])) {
                sons[seg].push_back(it->second);
                query.erase(it);                
                it = query.upper_bound(make_pair(xlo[seg],-1));
            }
            
            if (ylo[seg] == yhi[seg]) {
                propagate(seg, -1, yhi[seg]);
            } else if (ylo[seg] < yhi[seg]) {
                query.insert(make_pair(xhi[seg],seg));
            } else {
                query.insert(make_pair(xlo[seg],seg));
            }
        }
        
        for (int i = 0; i < N; ++i) if (seen[i] != seen_now) {
            propagate(i, ((ylo[i] > yhi[i])?xlo[i]:xhi[i]), -1);
        }
        
        for (int i = 0; i < C; ++i) {
            cout << xres[i];
            if (yres[i] != -1) cout << " " << yres[i];
            cout << "\n";
        }
        
    }
    
    return 0;
}
