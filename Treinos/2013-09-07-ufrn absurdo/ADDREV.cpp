#include <iostream>

using namespace std;

int rev(int x) {
    int res = 0;
    while (x) {
        res = 10*res + (x%10);
        x /= 10;
    }
    return res;
} 

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << rev(rev(a) + rev(b)) << "\n";
    }
    return 0;
}