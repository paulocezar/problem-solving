#include <iostream>

using namespace std;

int main(){

    int t, tc = 1;
    cin >> t;
    while( t-- ){

        int c;
        cin >> c;
        int q, d, n, p;
        q = c/25; c = c - q*25;
        d = c/10; c = c - 10*d;
        n = c/5; c = c - 5*n;
        p = c;
        cout << tc++ << " " << q << " QUARTER(S), " << d << " DIME(S), " << n << " NICKEL(S), " << p << " PENNY(S)\n";

    }

    return 0;
}
