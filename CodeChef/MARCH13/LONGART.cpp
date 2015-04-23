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


int64 res[256];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int N; string A; cin >> N >> A;
        int M; string B; cin >> M >> B;
        
        priority_queue< pair<int,char> > q[256];        
        REP(i, N) res[A[i]] = 0LL;

        REP(i, N*M) {
            string wrd; int hi;
            cin >> wrd >> hi;
            res[wrd[0]] += hi;    
            if (hi) q[wrd[0]].push(MP(hi,wrd[1]));
        }

        int64 longest = res[A[0]];
        REP(i,N) longest = min(longest,res[A[i]]);
        
        cout << longest << "\n";
        
        vector< pair<int,string> > ndd;
        int64 compressed = 0LL;
        
        while (compressed < longest) {
            
            int repeat = q[A[0]].top().first;
            REP(i, N) {
                repeat = min(repeat, q[A[i]].top().first);
            }
            compressed += repeat;
            string sentence = "";
            REP(i, N) {
                if (i) sentence += " ";
                pair<int,char> cur = q[A[i]].top(); q[A[i]].pop();
                sentence += A[i];
                sentence += cur.second;
                cur.first -= repeat;
                if (cur.first) q[A[i]].push(cur);
            }
            
            ndd.PB(MP(repeat,sentence));
        }
            
        if (SIZE(ndd) <= 30000) {
            cout << SIZE(ndd) << "\n";
            REP(i, SIZE(ndd)) {
                cout << ndd[i].first << " " << ndd[i].second << "\n";
            }
        } else cout << "-1\n";
    }
    
	return 0;
}

















