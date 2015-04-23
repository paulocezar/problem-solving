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
#include <bitset>

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

const double EPS = 1e-9;
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

typedef pair<int, int> prime_pot;

long long dp[2][1<<15];
int N, satisfies[500];

bitset< 32100 > bs;
vector<int> primes;

void sieve(){
	primes.clear();
	REP( i, 32000 ) bs[i] = (i&1);
	bs[1] = false; bs[2] = true; primes.PB( 2 );
	for( int i = 3; i < 32000; i++ ) if( bs[i] ){
		primes.PB(i);
		for( int j = i*i; j < 32000; j+=i ) bs[j] = false;
	}
}

set< int > nprimes;
void fact(long long n, vector<prime_pot>& fat){
    
	int limit = sqrt(n) + 1;
	prime_pot p;
	
	int i;
    for( i = 0; i < SIZE(primes) && primes[i] <= limit; i++ ){
        if((n % primes[i]) == 0){
            p = MP(primes[i], 0);
            while((n % primes[i]) == 0){
                p.second++;
                n /= primes[i];
            }
            fat.PB(p);
            if(n == 1)
                return;
        }
    }

    if(n != 1){
		if( n > 32000 ) nprimes.insert(n);
		fat.PB(MP(n, 1));
	}
}

long long gcd( long long a, long long b ){
	while( b ){
		a %= b;
		swap(a,b);
	}
	return a;
}

class EllysNumbers {
public:
	long long getSubsets( long long n, vector <string> special ){
		sieve();
		
		string inp = "";
		REP( i, SIZE(special) ) inp += special[i];
		
		
		vector< vector<prime_pot> > aux;
		istringstream in(inp);
		
		int x;
		bool hasone = false;
		
		nprimes.clear();
		while( in >> x ){
			if( x == 1 ) hasone = true;
			else if( gcd(n,x) == x ){
				aux.PB( vector< prime_pot >() );
				fact( x, aux.back() );
			}
		}
		
		FORIT( x, nprimes ) primes.PB( *x );
		
		vector<prime_pot> n_fat;
		fact( n, n_fat );
		
		int pfact = SIZE(n_fat);
		int lim = 1<<pfact;	
		
		N = SIZE(aux);
		
		REP( cand, N ){
			int pos = 0;
			int sz = SIZE(aux[cand]);
			for( int i = 0; i < pfact && pos < sz; i++ ){
				if( n_fat[i] == aux[cand][pos] ){
					satisfies[cand] |= (1<<i);
					pos++;
				} 
			}
			if( pos != sz ) satisfies[cand] = 0;  
		}
		
		REP( i, lim ) dp[0][i] = 0;
		dp[0][0] = 1;
		
		int old = 0;
		int cur = 1;
		REP( i, N ){
			
			REP( mask, lim ){
				
				dp[cur][mask] = dp[old][mask];
				if( satisfies[i] && ((satisfies[i] & mask) == satisfies[i]) )
					dp[cur][mask] += dp[old][satisfies[i] ^ mask];
				
			}
			
			old = !old;
			cur = !cur;
		}
		
		
		if( hasone ) return 2LL*dp[old][lim-1];
		else return dp[old][lim-1];
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			long long n               = 12;
			string special[]          = {"4 2 5 6 3"};
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = EllysNumbers().getSubsets(n, vector <string>(special, special + (sizeof special / sizeof special[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			long long n               = 42;
			string special[]          = {"1 2 3 4 5 6 7 13 14 21 42"};
			long long expected__      = 10;

			clock_t start__           = clock();
			long long received__      = EllysNumbers().getSubsets(n, vector <string>(special, special + (sizeof special / sizeof special[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			long long n               = 1337;
			string special[]          = {"1 13 42 666 2674"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = EllysNumbers().getSubsets(n, vector <string>(special, special + (sizeof special / sizeof special[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			long long n               = 1073741824;
			string special[]          = {"1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 1",
 "6384 32768 65536 131072 262144 524288 1048576 2097",
 "152 4194304 8388608 16777216 33554432 67108864 134",
 "217728 268435456 536870912"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = EllysNumbers().getSubsets(n, vector <string>(special, special + (sizeof special / sizeof special[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			long long n               = 7420738134810LL;
			string special[]          = {"435 625199055 4199 33263 17 222870 284870433 72093",
 "2379 7 11 31 247110827 23 1771 81809 851968487 13 ", 
 "476379795 1001 5 435274114 38264554 7429 239906525",
 " 3 227183706 887045414 606786670 3795 797605175 29",
 " 30 747186719 19 2 562347843 74 2294 588002688 743",
 "6429 703 591740547 36657492 37 444178205 1002001 2",
 "17626404"};
			long long expected__      = 110;

			clock_t start__           = clock();
			long long received__      = EllysNumbers().getSubsets(n, vector <string>(special, special + (sizeof special / sizeof special[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long n               = ;
			string special[]          = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = EllysNumbers().getSubsets(n, vector <string>(special, special + (sizeof special / sizeof special[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long n               = ;
			string special[]          = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = EllysNumbers().getSubsets(n, vector <string>(special, special + (sizeof special / sizeof special[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long n               = ;
			string special[]          = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = EllysNumbers().getSubsets(n, vector <string>(special, special + (sizeof special / sizeof special[0])));
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
