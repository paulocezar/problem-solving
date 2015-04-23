/*
ID: knightp2
PROG: preface
LANG: C++
*/
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
#include <fstream>
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

int main(int argc, char* argv[]) {
    ifstream fin("preface.in");
    ofstream fout("preface.out");	
    
    int n;
    fin >> n;
    
    map< char, int > res;
    
    for (int ncur = 1; ncur <= n; ++ncur) {
        
        int cur = ncur;
        while (cur >= 1000) {
            cur -= 1000;
            res['M']++;
        }
        
        while (cur >= 900) {
            cur -= 900;
            res['C']++;
            res['M']++;
        }
        
        while (cur >= 500) {
            cur -= 500;
            res['D']++;
        }
        
        while (cur >= 400) {
            cur -= 400;
            res['C']++;
            res['D']++;
        }
        
        while (cur >= 100) {
            cur -= 100;
            res['C']++;
        }

        while (cur >= 90) {
            cur -= 90;
            res['X']++;
            res['C']++;
        }
        
        while (cur >= 50) {
            cur -= 50;
            res['L']++;
        }
        
        while (cur >= 40) {
            cur -= 40;
            res['X']++;
            res['L']++;
        }
        
        while (cur >= 10) {
            cur -= 10;
            res['X']++;
        }

        while (cur >= 9) {
            cur -= 9;
            res['I']++;
            res['X']++;
        }
        
        while (cur >= 5) {
            cur -= 5;
            res['V']++;
        }
        
        while (cur >= 4) {
            cur -= 4;
            res['I']++;
            res['V']++;
        }
        
        while (cur >= 1) {
            cur -= 1;
            res['I']++;
        }        
    }
        
    if (res['I']) fout << 'I' << " " << res['I'] << "\n";
    if (res['V']) fout << 'V' << " " << res['V'] << "\n";
    if (res['X']) fout << 'X' << " " << res['X'] << "\n";
    if (res['L']) fout << 'L' << " " << res['L'] << "\n";
    if (res['C']) fout << 'C' << " " << res['C'] << "\n";
    if (res['D']) fout << 'D' << " " << res['D'] << "\n";
    if (res['M']) fout << 'M' << " " << res['M'] << "\n";
    
        
	return 0;
}

















