#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int64;

#define MAXL 1001
#define MAXP 1001
#define MAXN (MAXP+MAXL)

const double EPS = 1e-8;

int x[MAXN], y[MAXN], v[MAXN], kind[MAXN];
int id[MAXN], side[MAXN], sum[2][2];
double ang[MAXN]; 

int origin;

bool comp(int a, int b) {
    if (a == origin) return true;
    if (b == origin) return false;
    if (fabs(ang[a]-ang[b]) < EPS) return x[a] < x[b];
    return (ang[a] < ang[b]);
}

int64 ccw(int a, int b) {
    return (int64(x[a]-x[origin])*int64(y[b]-y[origin]) - int64(x[b]-x[origin])*int64(y[a]-y[origin]));
}

int main() {
    ios::sync_with_stdio(false);
    
    int P, L;
    while (cin >> P >> L && (P || L)) {
        int N = P+L;
        for (int i = 0; i < P; ++i) {
            cin >> x[i] >> y[i] >> v[i];
            kind[i] = 0;
            id[i] = i;
        }
        for (int i = P; i < N; ++i) {
            cin >> x[i] >> y[i] >> v[i];
            kind[i] = 1;
            id[i] = i;
        }
        int res = 2e9;
        for (origin = 0; origin < N; ++origin) {
            
            for (int i = 0; i < N; ++i) {
                ang[i] = ((x[i] == x[origin]) ? 2e9 : (double(y[i]-y[origin])/double(x[i]-x[origin])));
            }
            
            sort(id, id+N, comp);
            
            side[id[1]] = 0;
            for (int i = 2; i < N; ++i) {
                int sig_tri = ccw(id[1], id[i]);
                if (sig_tri < 0LL) {
                    side[id[i]] = 1;
                } else if (sig_tri > 0LL) {
                    side[id[i]] = 0;
                } else {
                    if ((x[id[1]] != x[origin]) && (int64(x[id[1]]-x[origin])*int64(x[id[i]]-x[origin]) > 0LL)) side[id[i]] = 0;
                    else if ((y[id[1]] != y[origin]) && (int64(y[id[1]]-y[origin])*int64(y[id[i]]-y[origin]) > 0LL)) side[id[i]] = 0;
                    else side[id[i]] = 1;
                }
            }
            
            sum[0][0] = sum[0][1] = sum[1][0] = sum[1][1] = 0;
            for (int i = 1; i < N; ++i)
                sum[kind[id[i]]][side[id[i]]] += v[id[i]];
            
            
            res = min(res, min(sum[1][0]+sum[0][1], sum[0][0]+sum[1][1]));
            for (int i = 1; i < N; ++i) {
                
                int j = i;
                while (j < N && fabs(ang[id[j]]-ang[id[i]]) < EPS) {
                    sum[kind[id[j]]][side[id[j]]] -= v[id[j]];
                    side[id[j]] = 1 - side[id[j]];
                    sum[kind[id[j]]][side[id[j]]] += v[id[j]];
                    j++;
                }
                i = j-1;
                
                res = min(res, min(sum[1][0]+sum[0][1], sum[0][0]+sum[1][1]));
            }
            
            
        }
        cout << res << "\n";
        
    }
    
    return 0;
}
