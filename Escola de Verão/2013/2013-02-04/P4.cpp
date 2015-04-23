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
#include <tr1/unordered_map>

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)

#define PB push_back
#define MP make_pair

#define S(n) int((n).size())

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3fffffffffll

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    tr1::unordered_map<char, int> cnt;
    cnt['A'] = cnt['C'] = cnt['G'] = cnt['T'] = 0;
    
    REP(i, S(s)) {
        cnt[s[i]]++;
    }
    
    int menor = INF;
    char c;
    for(typeof(cnt.begin()) it = cnt.begin(); it != cnt.end(); ++it) {
        if(it->second < menor) {
            menor = it->second;
            c = it->first;
        }
    }
    
    cout << menor << '\n';
    REP(i, S(s)) {
        cout << c;
    }
    
    cout << '\n';
    return 0;
}

