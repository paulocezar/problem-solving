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

#define MAXN 100000
int p[MAXN+10];

string s;

void init() {
    int N = SIZE(s);
    p[0] = p[1] = 0;
    FOR(i,2,N) {
        int j = p[i-1];
        while (s[i-1] != s[j]) {
            if (j == 0) { j = -1; break; }
            j = p[j];
        }
        p[i] = ++j;
    }
}

int64 occur(string t) {
    //cout << "searchin " << s << " in " << t << endl;
    int64 res = 0LL;
    int N = SIZE(s);
    int pos = 0;
    REP(i, SIZE(t)) {
        while (pos && (s[pos] != t[i])) pos = p[pos];
        if (s[pos] == t[i]) pos++;
        if (pos == N) {
            pos = p[pos];
            res++;
        }
    }
    //cout << "found " << res << endl;
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    int kase = 1;
    int n;
    while (cin >> n) {
        cin >> s;
        cout << "Case " << kase++ << ": ";
        if (n == 0) {
            cout << ((s == "0")?1:0) << "\n";
        } else if (n == 1) {
            cout << ((s == "1")?1:0) << "\n";
        } else {
            
            
            int len = SIZE(s);
            
            init();
            
            string f2 = "0";
            string f1 = "1";
            
            int len2 = 1;
            int len1 = 1;
            
            int n1 = 1;
            
            while ((n1 < n) && (len2 <= len)) {
                f2 = f1 + f2;
                swap(f1,f2);
                
                len2 += len1;
                swap(len2,len1);
                
                n1++;
            }
            
            if (n1 == n) {
                cout << occur(f1) << "\n";
            } else {
                int64 x2 = occur(f1);
                int64 x1 = occur(f1+f2);
                    
                    
                int64 add[2];
                
                add[0] = occur(f2 + f1) - occur(f2) - x2;
                add[1] = occur(f1 + f1) - 2LL*x2;
                
                for (int i = 0; (n1+i+2) <= n; ++i) {
                    int64 cur = x1 + x2 + add[i&1];
                    x2 = x1;
                    x1 = cur;
                    //x2 += x1 + add[i&1];
                    //swap(x2,x1);
                }
                cout << x1 << "\n";
            }
                        
        }
    }
    
	 
	return 0;
}

















