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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

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

template<typename T> T inline SQR(const T &a) { return a*a; }
template<typename T> T inline ABS(const T &a) { return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN(double a){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP(double a, double b){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int c, n, needed, stillon;
int choice[128][5];
bool valid[128];

bool comp(pair<int,int> a, pair<int,int> b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

bool apurate(int &x) {
    map<int,int> cnt;
    REP(i,n) {
        if (!valid[i]) continue;
        REP(j,c) if (stillon & (1<<choice[i][j])) {
            cnt[choice[i][j]]++;
            break;
        }
    }
    vector< pair<int,int> > q;
    FORIT(cnd,cnt) q.PB(MP(cnd->second,cnd->first));
    sort(ALL(q),comp);
    if (q[0].first >= needed) {
        x = q[0].second;
        return true;
    }
    x = q[SIZE(q)-1].second;
    return false;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    int el = 0;
	while (cin >> c >> n && (c || n)) {
	    int invalid = n;
        REP(i,n) {
            set<int> opt;
            valid[i] = false;
            REP(j,c) {
                cin >> choice[i][j];
                opt.insert(choice[i][j]);
            }
            int mn = *opt.begin(), mx = *opt.rbegin();
            if ((SIZE(opt) == c) && (mn == 1) && (mx == c))
                valid[i] = true, invalid--;
        }
        needed = (n-invalid)/2 + 1;
        ++el;
        cout << "Election #" << el << "\n";
        cout << "   " << invalid << " bad ballot(s)\n";

        stillon = (1<<(c+1))-1;
        int on = c;
        while (on >= 2) {
            int cand;
            if (apurate(cand)) {
                cout << "   Candidate " << cand << " is elected.";
                stillon = 0;
                on = 0;
            } else if (on != 2) {
                stillon ^= (1<<cand);
                --on;    
            } else on = 1;
        }
        if(on) cout << "   The following candidates are tied:";
        FOR(i,1,c) {
            if (stillon & (1<<i)) cout << " " << i;
        }
        cout << "\n";
	} 
	
	
	return 0;
}

















