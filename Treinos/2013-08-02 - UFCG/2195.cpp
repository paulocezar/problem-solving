#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int64;

int main() {
    ios::sync_with_stdio(false);
    
    int64 n;
    while (cin >> n && (n != 0LL)) {
        int64 nn, res = 1;
        
    	for (int64 i = 2LL; i*i <= n; ++i) {
    		if ((n%i) == 0LL) {
    			
                int64 divisor = i;
                nn = n;
                while (!(nn % divisor)) { res++; nn /= divisor; }
                
                if ((n/i) > i) {
                    divisor = n / i;
                    nn = n;
                    while (!(nn % divisor)) { res++; nn /= divisor; }
                }
    		}
    	}
        cout << n << " " << res << "\n";
    }
    
    return 0;
}