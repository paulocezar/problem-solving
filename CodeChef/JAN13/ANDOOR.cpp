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

const double PI = acos(-1.0);

inline double sqr(double x) { return (x*x); }
inline double dist2(double a1, double a2, double b1, double b2) { return (sqr(a1-b1) + sqr(a2-b2)); }

#define MAXN 1000
double x[MAXN], y[MAXN], r[MAXN];

inline void addp(map<double, int> &mm, double vv, int v) {
    mm[vv] += v;
}

inline void add(map<double, int> &mm, double f, double t) {
    addp(mm, f, 1);
    addp(mm, t, -1);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    cout << fixed << setprecision(13);

    int t;
    cin >> t;
    while (t--) {
        int W, H, N;
        cin >> W >> H >> N;
        for (int i = 0; i < N; ++i) cin >> x[i] >> y[i] >> r[i];
        
        for (int i = 0; i < N; ++i) {
            bool xout = ((x[i]+r[i]) < 0.0 || (x[i]-r[i]) > double(W));
            bool yout = ((y[i]+r[i]) < 0.0 || (y[i]-r[i]) > double(H));
            if (xout && yout) {
                swap(x[i], x[N-1]);
                swap(y[i], y[N-1]);
                swap(r[i], r[N-1]);
                --N; --i;
            }
        }
        
        double res = 0.0;
        for (int i = 0; i < N; ++i) {
            bool ok = true;
            for (int j = 0; j < N; ++j) {
                if (sqr(r[j]-r[i]) >= dist2(x[i],y[i],x[j],y[j]) && (r[j]>r[i])) {
                    ok = false; break;
                }
            }
            if (!ok) continue;
            
            map<double, int> ang;
            ang[0] = 0;
            ang[2.0 * PI] = 0;

            for (int j = 0; j < N; ++j) if (i != j) {
                double d2 = dist2(x[i],y[i],x[j],y[j]);
                if (d2 >= sqr(r[i]+r[j]) || d2 <= sqr(r[i]-r[j])) continue;
                double a = r[i];
                double b = sqrt(d2);
                double c = r[j];
                // ...
                double offset = acos((sqr(a)+sqr(b)-sqr(c))/(2.0*a*b));
                double med = atan2(y[j]-y[i], x[j]-x[i]) + 2.0*PI;
                if (med >= 2.0*PI) med -= 2.0*PI;
                
                double alpha = med - offset; if (alpha < 0.0) alpha += 2.0 * PI;
                double beta = med + offset; if (beta > 2.0*PI) beta -= 2.0 * PI;

                if (alpha > beta) {
                    add(ang, 0.0, beta);
                    add(ang, alpha, 2.0*PI);
                } else  {
                    add(ang, alpha, beta);
                }
            }
            
            // ...

            double tot = 0.0, ant = 0.0; int h = 0;
            map<double, int>::iterator it;
            for (it = ang.begin(); it != ang.end(); ++it) {
                if (h==0 && it->first > 0.0) tot += it->first-ant;
                h += it->second;
                ant = it->first;
            }
            res += tot * r[i];
        }

        cout << res << "\n";

    }

	return 0;
}

















