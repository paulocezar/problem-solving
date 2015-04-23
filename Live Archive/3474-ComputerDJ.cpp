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

string song[32];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, q;
    while (cin >> n >> q && (n || q)) {
        REP(i, n) cin >> song[i];
        
        while (q--) {
            int64 pos; cin >> pos;
                
            if (n == 1) { cout << song[0] << "\n"; continue; }
            
            int len = 1;
            int64 pw = 1;
            int64 skip = 0;
            while ((skip + pw*int64(n)*len) < pos) {
                pw *= int64(n);
                skip += pw*len;
                len++;
            }
            
            pos = pos-skip-1;
            int64 wut = (pos / len) + 1;
            int64 at = pos - (wut-1)*len;
            //cout << len << " - " << wut << " - " << at << endl;
            
            int cur = 0;
            while (cur < len) {
                int ltr = 0;
                skip = 0;
                while ((skip + pw) < wut) {
                    skip += pw;
                    ltr++;
                }
                wut -= skip;
                
                //cout << char('A'+ltr);
                
                if (cur == at) { cout << song[ltr] << "\n"; break; }
                pw /= int64(n);
                cur++;
            }
            //cout << endl;
            
        }
        cout << "\n";
    }    
        
	return 0;
}

















