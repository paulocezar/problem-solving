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
        
        int res = 0;
        while (N > 1) {
            N = (N+2) / 3;
            res += N;
        }
        cout << res <<  "\n";
        
    }
    return 0;
}