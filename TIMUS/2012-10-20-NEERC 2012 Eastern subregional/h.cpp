#include <iostream>
#include <algorithm>

typedef long long int64;
using namespace std;

int64 p, a[1001];
int ds;

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n >> p;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a,a+n);
    
    ds = 0;
    int sp = 0;
    int i = 0;
    while (i < n) {
        if (a[i] > p) break;
        int j = i;
        while ((j < n) && ((a[j] * int64(j-i+1)) <= p)) ++j;
        if (j < n) {
           if (a[j] == a[j-1]) {
              int val = a[j];
              while ((j-1) >= i && a[j-1] == val) --j; 
           } 
        }
        if (j <= i) break;
        ds += (j-i);
        sp++;
        i = j;
    }
    
    cout << ds << " " << sp << "\n";
    
    return 0;
}