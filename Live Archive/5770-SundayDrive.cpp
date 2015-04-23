#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <utility>
#include <cmath>
#include <iomanip>

#define ALL(x) (x).begin(),(x).end()
#define REP(i, n) for(int i = 0; i < n; ++i)

typedef long long int64;

using namespace std;

const double pi = acos(-1.0);
int n, m;
double len[1111][11];
bool st[1111];

bool vis[1111][11];
double dp[1111][11];

inline double getDist(int laneA, int laneB, double sz) {
    return sqrt(sz*sz + 100.0*(laneA - laneB)*(laneA - laneB));
}

double solve(int cseg, int clane) {
    if(cseg == n) {
        return 0.0;
    }
    
    double &val = dp[cseg][clane];
    if(vis[cseg][clane]) {
        return val;
    }
    vis[cseg][clane] = true;
    
    val = 1e100;
    if(!st[cseg]) {
        val = min(val, len[cseg][clane] + solve(cseg+1, clane));
        return val;
    }
    
    REP(i, m) {
        if(abs(i - clane)*100 > len[cseg][clane]) {
            continue;
        }
        
        if(i == clane) {
            val = min(val, len[cseg][clane] + solve(cseg + 1, i));
        } else {
            val = min(val, getDist(clane, i, len[cseg][clane]) + solve(cseg+1, i));
        }
    }
    
    return val;
}

int main(){
    while(cin>>n>>m && (n + m)) {
        REP(i, n) {
            char c;
            double d;
            cin>>c>>d;
            if(c == 'S') {
                st[i] = true;
            } else {
                st[i] = false;
            }
            
            REP(j, m) {
                vis[i][j] = false;
                if(c == 'S') {
                    len[i][j] = d;
                } else if (c == 'L') {
                    len[i][j] = (2.0*pi*(5.0 + j*10.0 + d))/4.0;
                } else if (c == 'R') {
                    len[i][j] = (2.0*pi*(5.0 + (m - j - 1)*10.0 + d))/4.0;
                }
            }
        }
        
        double ans = 1e100;
        REP(i, m) {
            ans = min(ans, solve(0, i));
        }
        
        cout << fixed << setprecision(2) << ans << '\n';
    }
    return 0;
}