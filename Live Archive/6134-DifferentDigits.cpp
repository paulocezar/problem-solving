#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool ok(int x) {
    int used = 0;
    while (x > 0) {
        if (used & 1<<(x%10)) return false;
        used |= (1<<(x%10));
        x /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    vector<int> cool;
    for (int i = 1; i <= 5000; ++i) if (ok(i))
        cool.push_back(i);
    
    int N, M;
    while (cin >> N >> M) {
        cout << upper_bound(cool.begin(), cool.end(), M)-lower_bound(cool.begin(), cool.end(), N) << "\n";
    }
    
}