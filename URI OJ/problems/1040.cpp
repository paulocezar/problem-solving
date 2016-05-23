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



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    cout << fixed << setprecision(1);
    
    double N1, N2, N3, N4;
    cin >> N1 >> N2 >> N3 >> N4;
    double media = (2.0*N1 + 3.0*N2 + 4.0*N3 + N4) / 10.0;
    
    cout << "Media: " << media << "\n";
    if (media >= 7.0) {
        cout << "Aluno aprovado.\n";
    } else if (media < 5.0) {
        cout << "Aluno reprovado.\n";
    } else {
        cout << "Aluno em exame.\n"; 
        cin >> N1;
        cout << "Nota do exame: " << N1 << "\n";
        media = (media + N1)/2.0;
    
        if (media >= 5.0) cout << "Aluno aprovado.\n";
        else cout << "Aluno reprovado.\n";
        
        cout << "Media final: " << media << "\n";
    }
     
	return 0;
}

















