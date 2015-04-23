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

#define MAXN 2048
#define VALUE(c) ((c)-'a')

typedef unsigned long long hash;

hash h[2048], pw[2048];
hash BASE;

hash calc_hash(int beg, int end) {
	return h[end+1] - h[beg]*pw[end-beg+1];
}

int acm[2048];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    srand(time(NULL));
    hash bases[] = {33ULL, 29ULL, 33ULL, 37ULL, 41ULL};
    random_shuffle(bases, bases+5);
    BASE = bases[0];
    
    string s, good;
    cin >> s >> good;
    
    int n = SIZE(s);
    
	pw[0] = 1ULL;
	for (int i=1; i<=n; ++i) {
        pw[i] = pw[i-1]*BASE;
    }
    
    
	acm[0] = 0;
	h[0] = 0ULL;
    REP(j,n) {
        acm[j+1] = acm[j];
        if (good[s[j]-'a'] == '0') acm[j+1]++;    
        h[j+1] = h[j]*BASE + VALUE(s[j]);
    }
    
    int k;
    cin >> k;
    
    tr1::unordered_set< hash > seen;
    REP(i, n) FOR(j,i,n-1) {
        if (acm[j+1]-acm[i] <= k) 
            seen.insert(pw[j-i+1]*5381ULL + calc_hash(i,j));   
    }
    cout << SIZE(seen) << "\n";
    
	return 0;
}

















