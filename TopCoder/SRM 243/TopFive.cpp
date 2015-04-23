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

int receive[55][3];
double prob[55][3];

int N, mypoints;

double dp[5][55];
bool calc[5][55];

double solve( int rem, int pos ){

	if( rem < 0 ) return 0.0;
	if( pos == N ) return 1.0;
	
	if( calc[rem][pos] ) return dp[rem][pos];
	calc[rem][pos] = true;
	
	double &res = dp[rem][pos];
	res = 0.0;
	
	double btr = 0.0;
	
	REP( i, 8 ){
		
		int score = 0;
		double pp = 1.0;
		
		REP( x, 3 ) if( i & (1<<x) ){
			
			pp *= prob[pos][x];
			score += receive[pos][x];
		
		} else {
			
			pp *= (1.0-prob[pos][x]);
			
		}
		
		if( score >= mypoints ) btr += pp;
					
	}
	res = btr*solve(rem-1,pos+1) + (1.0-btr)*solve(rem,pos+1);
	
	return res;
}


class TopFive {
public:
	double findProbability( vector <string> results, vector <string> accuracies, int points ) {
		
		mypoints = points;
		N = SIZE(results);
		
		REP( i, N ){
			istringstream in(results[i]);
			REP( x, 3 ) in >> receive[i][x];
			istringstream in2(accuracies[i]);
			REP( x, 3 ){
				in2 >> prob[i][x];
				prob[i][x] /= 100.;
			}			
		}
		
		memset( calc, false, sizeof(calc) );
		return solve(4,0);
		
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			string results[]          = {"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200"};
			string accuracies[]       = {"100 100 100",
"100 100 100",
"100 100 100",
"100 100 100",
"0 0 50"
};
			int points                = 100;
			double expected__         = 0.5;

			clock_t start__           = clock();
			double received__         = TopFive().findProbability(vector <string>(results, results + (sizeof results / sizeof results[0])), vector <string>(accuracies, accuracies + (sizeof accuracies / sizeof accuracies[0])), points);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string results[]          = {"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200"};
			string accuracies[]       = {"100 100 100",
"100 100 100",
"100 100 100",
"100 100 100",
"100 100 100"};
			int points                = 100;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = TopFive().findProbability(vector <string>(results, results + (sizeof results / sizeof results[0])), vector <string>(accuracies, accuracies + (sizeof accuracies / sizeof accuracies[0])), points);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string results[]          = {"928 209 594", "547 408 596", "190 865 494", "353 392 962", "6 252 267",
 "817 671 562", "631 78 290", "593 292 312", "59 51 286", "553 541 487",
 "466 318 271", "605 892 562", "596 261 63", "865 895 625", "893 479 586",
 "759 596 476", "157 407 819", "509 695 861", "696 730 430", "271 221 0",
 "922 296 640", "999 456 654", "320 550 805", "835 808 711", "9 161 670",
 "82 737 480", "939 12 363"};
			string accuracies[]       = {"84 87 72", "39 60 84", "56 78 48", "0 80 59", "11 69 94",
 "100 53 77", "87 77 55", "0 67 7", "89 63 3", "4 69 99", 
"58 9 49", "81 8 84", "81 85 55", "84 68 28", "7 1 46", 
"30 50 51", "16 82 8", "60 17 88", "44 30 67", "20 65 65", 
"40 75 73", "38 97 20", "82 38 88", "90 78 58", "58 30 66",
 "3 95 50", "76 60 57"};
			int points                = 1623;
			double expected__         = 0.8657569451352308;

			clock_t start__           = clock();
			double received__         = TopFive().findProbability(vector <string>(results, results + (sizeof results / sizeof results[0])), vector <string>(accuracies, accuracies + (sizeof accuracies / sizeof accuracies[0])), points);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string results[]          = {"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200",
"600 600 600"};
			string accuracies[]       = {"100 100 100",
"100 100 100",
"100 100 100",
"100 100 100",
"75 75 75"
};
			int points                = 500;
			double expected__         = 0.015625;

			clock_t start__           = clock();
			double received__         = TopFive().findProbability(vector <string>(results, results + (sizeof results / sizeof results[0])), vector <string>(accuracies, accuracies + (sizeof accuracies / sizeof accuracies[0])), points);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string results[]          = {"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200",
"33 33 33",
"33 200 200"};
			string accuracies[]       = {"100 0 0",
"0 0 100",
"0 100 0",
"100 100 100",
"100 100 100",
"33 80 50"
};
			int points                = 200;
			double expected__         = 0.10000000000000009;

			clock_t start__           = clock();
			double received__         = TopFive().findProbability(vector <string>(results, results + (sizeof results / sizeof results[0])), vector <string>(accuracies, accuracies + (sizeof accuracies / sizeof accuracies[0])), points);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string results[]          = ;
			string accuracies[]       = ;
			int points                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TopFive().findProbability(vector <string>(results, results + (sizeof results / sizeof results[0])), vector <string>(accuracies, accuracies + (sizeof accuracies / sizeof accuracies[0])), points);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string results[]          = ;
			string accuracies[]       = ;
			int points                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TopFive().findProbability(vector <string>(results, results + (sizeof results / sizeof results[0])), vector <string>(accuracies, accuracies + (sizeof accuracies / sizeof accuracies[0])), points);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string results[]          = ;
			string accuracies[]       = ;
			int points                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TopFive().findProbability(vector <string>(results, results + (sizeof results / sizeof results[0])), vector <string>(accuracies, accuracies + (sizeof accuracies / sizeof accuracies[0])), points);
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
