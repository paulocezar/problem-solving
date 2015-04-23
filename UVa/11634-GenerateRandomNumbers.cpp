#include <iostream>
#include <set>
#include <tr1/unordered_set>

using namespace std;

typedef long long int64;

int main() {
    ios::sync_with_stdio(false);
    
    int64 a;
    
    while (cin >> a && a) {
        
        tr1::unordered_set< int64 > seen;
    
        while (seen.insert(a).second) {
            a *= a;
            a /= 100;
            a %= 10000;
        }
        
        cout << int(seen.size()) << "\n";
        
    }
    
    
    return 0;
}