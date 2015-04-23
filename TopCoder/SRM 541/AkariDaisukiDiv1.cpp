// Paste me into the FileEdit configuration dialog

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

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod = 1000000007LL;

int64 aux[4][4];

void mult( int64 a[][4], int64 b[][4] ){
	REP( i, 4 ) REP( j, 4 ){
		aux[i][j] = 0;
		REP( k, 4 ){
			aux[i][j] += (a[i][k]*b[k][j])%mod;
			aux[i][j] %= mod;
		}
	}
	REP( i, 4 ) REP( j, 4 )
		a[i][j] = aux[i][j];
}

int64 count( string &a, string &b ){
	int64 ans = 0;
	REP( i, SIZE(b) ){
		if( i+SIZE(a) < SIZE(b)+1 ) {
			REP( j, SIZE(a) ) if( a[j] != b[i+j] ) goto hell;
			ans++;
			hell:;
		} else break;
	}
	return ans;
}

class AkariDaisukiDiv1 {
public:
	int countF( string Waai, string Akari, string Daisuki, string S, string F, int k ) {
		
		string res = Waai + S + Akari + S + Daisuki;
		int made = 1;
		
		while( made < k && (SIZE(res) < SIZE(F)) ){
			made++;
			res = Waai + res + Akari + res + Daisuki;
		}
	
		int64 resp = 0;
		if( made < k ){
			
			int64 x0 = count(F,res);
			
			string pref = Waai + res.substr(0,SIZE(F)-1);
			string suf = res.substr(SIZE(res)-SIZE(F)+1,SIZE(F)-1) + Daisuki;
			string md = res.substr(SIZE(res)-SIZE(F)+1,SIZE(F)-1) + Akari + res.substr(0,SIZE(F)-1);
			
			int64 x1 = count(F,pref);
			int64 x2 = count(F,md);
			int64 x3 = count(F,suf);
			
			x0 = ((2LL*x0)%mod + ((x1 + x2)%mod + x3)%mod)%mod;
			made++;
			
			while( made < k && ((made*SIZE(Waai) < 2*SIZE(F)) || (made*SIZE(Daisuki) < 2*SIZE(F))) ){
				made++;
				md = suf.substr(SIZE(suf)-SIZE(F)+1,SIZE(F)-1) + Akari + pref.substr(0,SIZE(F)-1);
				pref = Waai + pref.substr(0,SIZE(F)-1);
				suf = suf.substr(SIZE(suf)-SIZE(F)+1,SIZE(F)-1) + Daisuki;
				
				x1 = count(F,pref);
				x2 = count(F,md);
				x3 = count(F,suf);
				
				x0 = ((2LL*x0)%mod + ((x1 + x2)%mod + x3)%mod)%mod;
			}
			
			
			int64 pot[4][4] = { {2,1,1,1},
								{0,1,0,0},
								{0,0,1,0},
								{0,0,0,1} };
			int64 ans[4][4] = { {1,0,0,0},
								{0,1,0,0},
								{0,0,1,0},
								{0,0,0,1} };
			
			k -= made;
			while( k ){
				if( k&1 ) mult( ans, pot );
				mult(pot,pot);
				k >>= 1;
			}
			
			resp = (ans[0][0]*x0)%mod;
			resp += (ans[0][1]*x1)%mod; resp %= mod;
			resp += (ans[0][2]*x2)%mod; resp %= mod;
			resp += (ans[0][3]*x3)%mod; resp %= mod;
			
		} else resp = (count(F,res)%mod);
		
		return int(resp);
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string Waai               = "a";
			string Akari              = "b";
			string Daisuki            = "c";
			string S                  = "x";
			string F                  = "axb";
			int k                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string Waai               = "a";
			string Akari              = "b";
			string Daisuki            = "c";
			string S                  = "x";
			string F                  = "abcdefghij";
			int k                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string Waai               = "a";
			string Akari              = "a";
			string Daisuki            = "a";
			string S                  = "b";
			string F                  = "aba";
			int k                     = 2;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string Waai               = "a";
			string Akari              = "b";
			string Daisuki            = "c";
			string S                  = "d";
			string F                  = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba";
			int k                     = 58;
			int expected__            = 191690599;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string Waai               = "a";
			string Akari              = "x";
			string Daisuki            = "y";
			string S                  = "b";
			string F                  = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
			int k                     = 49;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string Waai               = "waai";
			string Akari              = "akari";
			string Daisuki            = "daisuki";
			string S                  = "usushio";
			string F                  = "id";
			int k                     = 10000000;
			int expected__            = 127859200;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			string Waai               = "vfsebgjfyfgerkqlr";
			string Akari              = "ezbiwls";
			string Daisuki            = "kjerx";
			string S                  = "jbmjvaawoxycfndukrjfg";
			string F                  = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs";
			int k                     = 1575724;
			int expected__            = 483599313;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

     case 7: {
	
			string Waai               = "sx";
			string Akari              = "autqn";
			string Daisuki            = "xyzn";
			string S                  = "e";
			string F                  = "znxyznautqnsxsxsxsxsxeautqnexyznautqnsxeautqnexyzn";
			int k                     = 16;
			int expected__            = 1024;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
      case 8: {

			string Waai               = "tyeocdggodsqtnfcbl";
			string Akari              = "mtvmszj";
			string Daisuki            = "fndlacpvsmnqpyoedjykvadxecdkcpwfsrhbmsmwg";
			string S                  = "sw";
			string F                  = "szjtyeocdggodsqtnfcblswmtvmszjswf";
			int k                     = 1245966;
			int expected__            = 829684666;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 9: {
			string Waai               = ;
			string Akari              = ;
			string Daisuki            = ;
			string S                  = ;
			string F                  = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
