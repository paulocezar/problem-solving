#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

using namespace std;

typedef long long int64;

int main() {
    ios::sync_with_stdio(false);
    
    int64 f[21];
    f[0] = 1LL;
    for (int i = 1; i <= 20; ++i)
        f[i] = int64(i) * f[i-1];
    
    int c, v;
    while ((cin >> c >> v) && (c != -1)) {
        int64 t1 = f[c] * (v ? int64(c + 1) : 1LL);
        int64 t2 = t1 * f[v];
        int64 t3 = f[c+v] / f[v];
        cout << t1 << " " << t2 << " " << t3 << "\n";
    }
    
    
    return 0;
}