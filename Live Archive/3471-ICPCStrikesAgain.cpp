#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< int > dependson[1024];
vector< int > workon[1024];
vector< int > gr[1024];

int BS[1024];
int deg[1024];

int added[1024], added_now;

int pos[1024];

void doit(int task) {

    added[task] = added_now;
    for (int i = 0; i < int(gr[task].size()); ++i) if (added[gr[task][i]] != added_now) {
        doit(gr[task][i]); 
    }
       
}

bool comp(int a, int b) { return (pos[a] < pos[b]); }

int main() {
    ios::sync_with_stdio(false);
    
    int T, E;
    while (cin >> T >> E && (T || E)) {
        
        for (int empl = 1; empl <= E; ++empl) workon[empl].clear();
            
        for (int task = 1; task <= T; ++task) {
            dependson[task].clear();
            gr[task].clear();
            deg[task] = 0;
        }
        
        for (int task = 1; task <= T; ++task) {
            int NE;
            cin >> BS[task] >> deg[task] >> NE;

            for (int i = 0; i < deg[task]; ++i) {
                int dependent; cin >> dependent;
                dependson[dependent].push_back(task);
                
                gr[task].push_back(dependent);
            }
            
            for (int i = 0; i < NE; ++i) {
                int employee; cin >> employee;
                workon[employee].push_back(task);
            }
        }
        
        queue<int> q;
        for (int task = 1; task <= T; ++task) {
            if (!deg[task]) q.push(task);
        }
        
        int cur_pos = T;
        
        while (!q.empty()) {
            int task = q.front(); q.pop();
            pos[task] = cur_pos--;
            
            for (int i = 0; i < int(dependson[task].size()); ++i) {
                BS[dependson[task][i]] += BS[task];
                deg[dependson[task][i]]--;
                if (!deg[dependson[task][i]]) q.push(dependson[task][i]);
            }
        }
        
        cout << "*****\n";
        for (int empl = 1; empl <= E; ++empl) {
            
            sort(workon[empl].begin(), workon[empl].end(), comp);
            added_now++;
            int salary = 0;
            for (int i = 0; i < int(workon[empl].size()); ++i) {
                if (added[workon[empl][i]] != added_now) {
                    salary += BS[workon[empl][i]];
                    doit(workon[empl][i]);
                }
            }
            
            cout << empl << " " << salary << "\n";
        }
        
        
    }
    
    return 0;
}