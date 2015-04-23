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

int cenc[26], corg[26];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    string enc, org;
    cin >> enc >> org;

    REP(i, SIZE(org)) {
        corg[org[i]-'a']++;
        cenc[enc[i]-'a']++;
    }
    
    int eq = 0;
    REP(i, 26) eq += ((corg[i]==cenc[i])?1:0);
    int append_begin = 0;
    int len_org = SIZE(org);
    int len_enc = SIZE(enc);

    bool ok = (eq == 26);
    while (!ok && ((append_begin+len_org) < len_enc)) {
        int out = enc[append_begin] - 'a';
        int in = enc[append_begin+len_org] - 'a';
        
        if (cenc[out] == corg[out]) eq--;
        cenc[out]--;        
        if (cenc[out] == corg[out]) eq++;
        
        if (cenc[in] == corg[in]) eq--;
        cenc[in]++;
        if (cenc[in] == corg[in]) eq++;

        ok = ok || (eq == 26);
        append_begin++;
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";
    

	 
	return 0;
}

















