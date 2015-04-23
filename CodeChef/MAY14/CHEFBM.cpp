#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

pair<int, int> cmd[100100];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < p; ++i) cin >> cmd[i].first >> cmd[i].second;
    
    if (m == 1) {
        for (int i = 0; i < n; ++i) cout << "0\n";
        return 0;
    }
    
    
    sort(cmd, cmd+p);
    
    
    int last_print = 0;
    for (int i = 0; i < p; ) {
        
        while ((last_print+1) != cmd[i].first) {
            cout << m-1 << "\n";
            last_print++;
        }
        last_print++;
        
        int cost = m-1;
        
        int ni = i+1;
        
        int j = cmd[i].second;
        int cmds = 1;
        int cur = 0;
        
        while ((ni < p) && (cmd[ni].first == last_print)) {
            if (cmd[ni].second == j) cmds++;
            else {
                cmd[i+cur] = make_pair(j, cmds);
                j = cmd[ni].second; cmds = 1;
                cur++;
            }
            ni++;
        }
        cmd[i+cur] = make_pair(j,cmds);
        cur++;
                         
        if (cmd[i].first != 1) cost += cmd[i].second;
                
        for (j = 1; j < cur; ++j) {
            if ((cmd[i+j].first != (cmd[i+j-1].first+1)) && (cmd[i+j-1].second > 1)) {
                cost = -1;
                break;
            }
            
            if (cmd[i+j].first != (cmd[i+j-1].first+1)) {
                cost--;
                cost += cmd[i+j].second;
            } else {
                if (cmd[i+j].second < (cmd[i+j-1].second-1)) {
                    cost = -1; 
                    break;
                }
                
                int a = cmd[i+j-1].first + cmd[i+j-1].second;
                int b = cmd[i+j].first + cmd[i+j].second;
                cost += b-a-1;
                
            }
        }
        
        if ((cmd[i+cur-1].first < m) && (cmd[i+cur-1].second > 1)) cost = -1;
        else if ((cost > 0) && (cmd[i+cur-1].first != m)) cost--;
        
        cout << cost << "\n"; 
         
        i = ni;       
    }
    
    while (last_print != n) {
        cout << m-1 << "\n";
        last_print++;
    }
    
    
	return 0;
}

















