#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    set<int> seen;
    
    for (int minute = 0; minute <= 720; ++minute) {
        int m = minute % 60;
        int h = minute / 12;
        int ang = abs(6*(m-h));
        ang = min(ang, 360-ang);
        seen.insert(ang);
    }
    
    int check;
    while (cin >> check) cout << (seen.count(check) ? "Y\n" : "N\n");
    
    
    return 0;
}