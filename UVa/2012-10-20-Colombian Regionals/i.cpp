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

const string roman = "IVXLCDM";
const int rval[7] = {1, 5, 10, 50, 100, 500, 1000};

const string part[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
const int val[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};


string convert(int x) {
    
    string res = "";
    RREP(i,13) {
        while (x >= val[i]) {
            x -= val[i];
            res += part[i];
        }
    }
    
    return res;
}


int na, nb;
string sa, sb;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);

    
	while (cin >> sa && sa[0] != '*') {
        
        int x = 0;
        REP(i,SIZE(sa)) x += rval[ roman.find(sa[i]) ];
        
        sb = convert(x);
        
        na = SIZE(sa);
        nb = SIZE(sb);
        
        int e = na;
        int c = nb;
        
        for (int i = -nb; i < na; ++i) {
            
            int match = 0;
            for (int j = 0; j < nb; ++j) {
                if (i+j < 0 || i+j >= na) continue;
                if (sa[i+j] == sb[j]) match++;
            }
            
            int ee = na-match;
            int cc = nb-(na-ee);
            if (ee+cc < e+c) {
                e = ee;
                c = cc;
            } else if (ee+cc == e+c) {
                if (ee < e) {
                    e = ee; c = cc;
                }
            }
            
            
        }
        
        
        cout << e << " " << c << "\n";
    
    }
	
	return 0;
}

















