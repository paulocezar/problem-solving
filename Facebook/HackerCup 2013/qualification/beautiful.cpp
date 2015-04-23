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
    
    int m;
    cin >> m;
    FOR(kase,1,m) {
        string s;
        map<char,int> cnt;
        while (cnt.empty()) {
            getline(cin, s);
            REP(i, SIZE(s)) {
                if (('A' <= s[i]) && (s[i] <= 'Z'))
                    s[i] = char(s[i]-'A'+'a');
                if (('a' <= s[i]) && (s[i] <= 'z'))
                    cnt[s[i]]++;
            }
        }
        vector<int> wg;
        FORIT(ltr,cnt) wg.PB(ltr->second);
        sort(ALL(wg));
        int res = 0;
        int bea = 26;
        
        RREP(i, SIZE(wg)) {
            res += wg[i] * bea;
            bea--;
        }
        
        cout << "Case #" << kase << ": " << res << "\n";
    }
	 
	return 0;
}

















