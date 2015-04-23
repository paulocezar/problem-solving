#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>

using namespace std;

bitset< 151 > bs;
vector<int> primes;

void sieve() {
    for (int i = 1; i <= 150; ++i) bs[i] = i&1;
    bs[1] = false;
    bs[2] = true;
    
    for (int i = 3; i <= 13; i += 2) if (bs[i]) {
        for (int j = i*i; j <= 150; j += i) bs[j] = false;
    }
   
    primes.push_back(2);
    for (int i = 3; i <= 150; i+=2) if (bs[i]) primes.push_back(i);
}

int numask[151];


int N, K, a[32];
int cache[32][21][1<<15];
char last_cached[32][21][1<<15], cached_now;

int solve(int pos, int last_alone, int mask) {
    
    if (pos == N) return 0;
    
    int &res = cache[pos][last_alone][mask];
    if (last_cached[pos][last_alone][mask] == cached_now) return res;
    last_cached[pos][last_alone][mask] = cached_now;
    
    res = 1e9;
    for (int i = max(1, a[pos] / K); i <= 150; ++i) {
        if (numask[i] == -1) continue;
        if (numask[i] & mask) continue;
        if (i*K < a[pos]) continue;
        res = min(res, i*K-a[pos] + solve(pos+1, last_alone, mask | numask[i]));
    }
    
    while (last_alone < 20) {
        if (primes[15+last_alone]*K >= a[pos]) {
            res = min(res, primes[15+last_alone]*K-a[pos] + solve(pos+1, last_alone+1, mask));
        }
        last_alone++;
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    sieve();
    
    for (int i = 1; i <= 150; ++i) {
        numask[i] = 0;
        for (int j = 0; j < int(primes.size()); ++j) {
            if (i%primes[j]) continue;
            if (j >= 15) {
                numask[i] = -1;
                break;
            }
            numask[i] |= (1<<j); 
        }
    }
    
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        
        sort(a, a+N);
        int res = 0;
        
        if (a[N-1] <= K) {
            for (int i = 0; i < N; ++i) res += (K-a[i]);
            if (a[0] == 0) res -= K;
        } else {
            cached_now++;
            res = solve(0, 0, 0);
        }
        cout << "Case #" << kase << ": " << res << "\n";
    }
    
    
    return 0;
}
