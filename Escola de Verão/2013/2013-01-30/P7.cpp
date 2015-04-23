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

int mmc(int a, int b) { return ((a/__gcd(a,b))*b); }

struct fr_t {
	int a, b;
	explicit fr_t(int aa = 0, int bb = 1) : a(aa), b(bb) {
		int g = __gcd(a,b); a /= g; b /= g;
	}
	bool operator < (const fr_t &y) const {
		return ((a*y.b) < (y.a*b));
	}
	bool operator == (const fr_t &y) const {
		return ((a==y.a) && (b==y.b));
	}
	fr_t operator +(const fr_t &y) const {
		int m = mmc(b, y.b);
		return fr_t((m/b)*a + (m/y.b)*a, m);
	}
	fr_t& operator +=(const fr_t &y) {
		int m = mmc(b, y.b);
		int n = (m/b)*a + (m/y.b)*y.a;
		a = n, b = m;
		n = __gcd(a,b);
		a /= n; b /= n;
		return *this;
	}
	fr_t operator * (const fr_t &y) const {
		return fr_t(a*y.a, b*y.b);
	}
	fr_t& operator *=(const fr_t &y) {
		a *= y.a;
		b *= y.b;
		int g = __gcd(a,b);
		a /= g; b /= g;
		return *this;
	}
};

fr_t p[20];
int N, A, B, C, idx[20];

int main(){
    ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while (t--) {
		
		cin >> N >> A >> B >> C;
		
		REP(i, N) {
			int x; cin >> x;
			p[i] = fr_t(x,100);
		}
		
		fr_t res(0);
		
        sort(p,p+N);
        int ii = 0, jj = N-1;
        REP(i, N) {
            if (i&1) idx[ii++] = i;
            else idx[jj--] = i;
        }

		REP(i, N) res += p[i]*p[i]*fr_t(C);
		REP(i, N) FOR(j,i+1,N-1) {
			int dx = j-i;
			int cc = A*dx*dx + B*dx + C;
			cc *= 2;
			res += p[idx[i]]*p[idx[j]]*fr_t(cc);
		}

		cout << res.a << "/" << res.b << "\n";
	}
    return 0;
}
