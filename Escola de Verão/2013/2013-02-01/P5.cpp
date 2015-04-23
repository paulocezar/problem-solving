#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <cfloat>
#include <sstream>
#include <utility>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <bitset>

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)

#define PB push_back
#define MP make_pair

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3fffffffffll

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int val = (n*n - n)/2, sum = 0, nzeros = 0;
        REP(i, n) {
            int aux;
            cin>>aux;
            sum += aux;
            if(aux == 0) nzeros++;
        }
        
        int ans = abs(sum - val);
        if(sum >= val) {
            ans += max(nzeros - 1, 0);
        } else if(nzeros-1 > ans) {
            ans += nzeros-1-ans;
        }
        
        cout << ans << '\n';
    }
    return 0;
}
