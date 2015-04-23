#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int64;

#define MAXF 100001

inline int gcd(int64 a, int64 b) {
    while (b) {
        a %= b;
        swap(a,b);
    }
    return a;
}

int64 C[MAXF];
int64 F, G, sum;

inline bool valid(int64 qnt) {
    if ((sum % qnt) || (qnt % F) || ((sum / qnt) <= F)) return false;
    if ((C[0] % qnt) % (qnt / F)) return false;
    return ((G % qnt) == 0);
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> F && F) {
        
        sum = 0LL;
        for (int i = 0; i < F; ++i) {
            cin >> C[i];
            sum += int64(C[i]);
        }
        sort(C,C+F);
        
        G = 0;
        for (int i = 1; i < F; ++i) {
            C[i] -= C[0];
            if (!G) G = C[i];
            else G = gcd(G, C[i]);
        }
        
        int64 sq = ceil(sqrt(sum));
        int64 res = 0LL;
        for (int64 qnt = 2LL; qnt < C[0]; ++qnt) {
            
            if (valid(qnt)) {
                res += (C[0] - qnt) / qnt;
                if (C[0] % qnt) res++;
            }
            if (qnt >= sq) break;
            
            int64 qnt2 = sum / qnt;
            if (valid(qnt2)) {
                res += (C[0] - qnt2) / qnt2;
                if (C[0] % qnt2) res++;
            }
        }
        cout << res << "\n";
        
    }
    return 0;
}