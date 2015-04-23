#include <iostream>
#include <string>

/*
 *  using gmp for arbitrary precision.. http://gmplib.org/
 */
#include <gmpxx.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        
        string alph, sn;
        cin >> alph >> sn;
        
        mpz_class n = mpz_class(sn, 10);
        mpz_class L = alph.size();
        
        int len = 1;
        mpz_class ways = L;
        
        while (n > ways) {
            n -= ways;
            ways *= L;
            len++;
        }
        
        string res = "";

        ways /= L;
        for (int i = 0; i < len; ++i) {
            
            for (auto letter : alph) {
                if (n > ways) {
                    n -= ways;
                } else {
                    res += letter;
                    break;
                }
            }
                        
            ways /= L;
        }
        
        cout << "Case #" << kase << ": " << res << "\n";
        
    }
    
    
    return 0;
}
