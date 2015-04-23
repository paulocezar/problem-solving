#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int64;

int64 el[5];

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    while (cin >> n && n) {
        
        int hi = 0, times = 0;
        
        map<int64, int> cnt;
        for (int i = 0; i < n; ++i) {
            for (int x = 0; x < 5; ++x) {
                cin >> el[x];
            }
            sort(el, el+5);
            int64 cur = 0;
            for (int x = 0; x < 5; ++x) {
                cur *= 1000LL;
                cur += el[x];
            }
            cnt[cur]++;
            if (cnt[cur] > hi) hi = cnt[cur], times = 1;
            else if (cnt[cur] == hi) times++;
        }
            
        cout << times * hi << "\n";
    }
    
    return 0;
}