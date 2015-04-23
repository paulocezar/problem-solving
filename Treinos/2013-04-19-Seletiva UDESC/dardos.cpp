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

int main() {
    ios::sync_with_stdio(false);
    
    int N;
    while ((cin >> N) && N) {
        double x, y;
        int res = 0;
        for (int i = 0; i < N; ++i) {
            cin >> x >> y;
            double dist = sqrt(x*x + y*y);
            if (dist <= 2.0) res += 7;
            else if (dist <= 4.0) res += 5;
            else if (dist <= 6.0) res += 3;
            else if (dist <= 8.0) res += 1;
        }
        cout << res <<  "\n";
        
    }
    return 0;
}