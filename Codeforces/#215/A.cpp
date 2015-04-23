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

#define MAXN 101010

int cntx[MAXN], cnty[MAXN], cntz[MAXN];

inline bool okay(int c1, int c2, int c3, int x1, int x2, int x3) {
    return ((c1==x1) && (c2==x2) && (c3==x3));
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int n = SIZE(s);
    
    cntx[0] = cnty[0] = cntz[0] = 0;
    
    for (int i = 1; i <= n; ++i) {
        cntx[i] = cntx[i-1];
        cnty[i] = cnty[i-1];
        cntz[i] = cntz[i-1];
        switch (s[i-1]) {
            case 'x': cntx[i]++; break;
            case 'y': cnty[i]++; break;
            case 'z': cntz[i]++; break;
            default: break;
        }        
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int x = cntx[r] - cntx[l-1];
        int y = cnty[r] - cnty[l-1];
        int z = cntz[r] - cntz[l-1];
        
        int len = r-l+1;
        
        int a, b, c;
        a = b = c = len/3;       
        if (len % 3) {
            a++;
            if (len % 3 == 2) b++;
        }
        
        if (len < 3 
            || okay(a,b,c,z,y,x)
            || okay(a,b,c,y,x,z)
            || okay(a,b,c,x,z,y)) cout << "YES\n";
        else cout << "NO\n";
        
    }
    
	return 0;
}

















