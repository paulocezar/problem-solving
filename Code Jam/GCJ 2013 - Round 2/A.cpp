#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

#include <gmpxx.h>

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = a.begin(); i != a.end(); i++)

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct event_t {
    int at, type, qnt;
    event_t(int a = 0, int t = 0, int q = 0) : at(a), type(t), qnt(q) {}
    bool operator < (const event_t& e) const {
        if (at != e.at) return at < e.at;
        if (type != e.type) return type < e.type;
        return qnt < e.qnt;
    }
};

const mpz_class mod("1000002013");

mpz_class N;

mpz_class cost(mpz_class a, mpz_class b) {
    mpz_class dist = (b - a);
    return (dist * (N + N - dist + 1)) / 2;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    FOR(kase,1,t) {
        int M;
        cin >> N >> M;
        
        vector< event_t > event;
        
        mpz_class should = 0;
        REP(i,M) {
            int o, e, p;
            cin >> o >> e >> p;
            should += p * cost(o,e);
            
            event.PB(event_t(o,0,p));
            event.PB(event_t(e,1,p));
        }
        sort(ALL(event));

        mpz_class paid = 0;
        priority_queue< pair<int,int> > q;
        REP(i, SIZE(event)) {
            if (event[i].type) {
                while (event[i].qnt) {
                    pair<int,int> x = q.top(); q.pop();
                    int pp = min(event[i].qnt, x.second);
                    
                    paid += pp * cost(x.first, event[i].at);
                    
                    event[i].qnt -= pp;
                    x.second -= pp;
                    if (x.second) q.push(x);
                }
            } else {
                q.push(MP(event[i].at,event[i].qnt));
            }
        }
        cout << "Case #" << kase << ": " << ((should - paid) % mod) << "\n";
    }
    
    
	return 0;
}

















