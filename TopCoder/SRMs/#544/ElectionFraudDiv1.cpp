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

class ElectionFraudDiv1 {
public:
	int MinimumVoters( vector <int> percentages ) {
		
		int N = SIZE(percentages);
		int get[N];
		
		int ttlprob = 0;
		REP( i, N ) ttlprob += percentages[i];
		
		FOR( votes, 1, 10000 ){
			
			bool ok = true;
			
			REP( i, N ){
				get[i] = int( double(votes*percentages[i])/100.0 + 0.5 );
				int pp = int( (100.0*get[i]) / double(votes) + 0.5 );
				
				if( pp > percentages[i] ){
					while( pp > percentages[i] ){
						get[i]--;
						pp = int( (100.0*get[i]) / double(votes) + 0.5 );
					}
				} else if( pp < percentages[i] ) {
					while( pp < percentages[i] ){
						get[i]++;
						pp = int( (100.0*get[i]) / double(votes) + 0.5 );
					}
				}
				
				if( pp != percentages[i] ) ok = false;
			}
			
			int ttl = 0;
			REP( i, N ) ttl += get[i];
			
			if( (ttl != votes) && ok ){
				int i = 0;
				
				while( ttl < votes && i < N ){
					
					get[i]++;
					if( get[i] > votes ){ get[i]--; i++; }
					else {
						int pp = int( (100.0*get[i]) / double(votes) + 0.5 );
						if( pp == percentages[i] ){
							ttl++;
						} else { get[i]--; i++; }
					}
						
				}
				
				while( ttl > votes && i < N ){
				
					get[i]--;
					if( get[i] < 1 ){ get[i]++; i++; }
					else {
						int pp = int( (100.0*get[i]) / double(votes) + 0.5 );
						if( pp == percentages[i] ){
							ttl--;
						} else { get[i]++; i++; }
					}
				}
				
				if( ttl != votes ) ok = false;
				
			}
			
			if( ok ) return votes;
		}
		
		return -1;
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
			int percentages[]         = {33, 33, 33};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int percentages[]         = {29, 29, 43};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int percentages[]         = {12, 12, 12, 12, 12, 12, 12, 12};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int percentages[]         = {13, 13, 13, 13, 13, 13, 13, 13};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int percentages[]         = {0, 1, 100};
			int expected__            = 200;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int percentages[]         = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4};
			int expected__            = 97;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int percentages[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int percentages[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int percentages[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
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
