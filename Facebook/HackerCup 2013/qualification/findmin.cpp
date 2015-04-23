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

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
	int T;
    cin >> T;
    FOR(kase,1,T) {
        int n, k;
        cin >> n >> k;
        int64 a, b, c, r;
        cin >> a >> b >> c >> r;
        b %= r; c %= r;
        
        map<int, int> cnt;
        
        cnt[a]++;
        int64 old = a % r;
        queue<int> q;
        q.push(old);
        //cerr << old;
        FOR(i, 1, k-1) {
            int64 nxt = (((b * old) % r) + c) % r;
            cnt[nxt]++;
            old = nxt;
            //cerr << " " << old;
            q.push(old);
        }

        cout << "Case #" << kase << ": ";
        
        int guess = 0;
        set<int> gotout;
        
        FOR(i,k,n-1) {
            
            while (cnt.count(guess)) guess++;
            
            int trythis = guess;
            if (!gotout.empty()) {
                if ((*gotout.begin()) < trythis) {
                    trythis = *gotout.begin();
                }
            }
            
            if (i == (n-1)) {
                cout << trythis << "\n";
                break;
            }
            //cerr << " " << trythis << endl;
            cnt[trythis]++;
            cnt[q.front()]--;
            if (cnt[q.front()] == 0) {
                cnt.erase(q.front());
                gotout.insert(q.front());
            }
            
            if (i == 2*k) {
                q.push(trythis);
                break;
            }
            
            q.pop();
            q.push(trythis);
            gotout.erase(trythis);
        }
        //cerr << " ---- " << endl;
        int rem = n - (2*k+1);
        if (rem > 0) {
            rem %= (k+1);
            rem--;
            if (rem < 0) rem = k;
            while (rem) {
                rem--;
                q.pop();
            }
            cout << q.front() << "\n";
        }
        
    }

	return 0;
}

















