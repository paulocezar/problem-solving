#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class TheTips {
public:
    double solve( vector <string> clues, vector <int> probability ) {
        int N = clues.size();
        bool g[N][N];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (clues[i][j] == 'Y') {
                    g[i][j] = true;
                } else {
                    g[i][j] = false;
                }
                if (i == j) g[i][j] = true;
            }
        }
        
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
                }
            }
        }

        double res = 0.0;
        for (int j = 0; j < N; ++j) {
            double p = 1.0;
            for (int i = 0; i < N; ++i) {
                if (g[i][j]) {
                    p *= (100.0-probability[i]) / 100.0;
                }
            }
            res += (1.0 - p);
        }
        return res;
        
    }
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
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
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}
	
	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string clues[]            = {"Y"};
			int probability[]         = {50};
			double expected__         = 0.5;

			std::clock_t start__      = std::clock();
			double received__         = TheTips().solve(vector <string>(clues, clues + (sizeof clues / sizeof clues[0])), vector <int>(probability, probability + (sizeof probability / sizeof probability[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string clues[]            = {"YN","NY"};
			int probability[]         = {100,50};
			double expected__         = 1.5;

			std::clock_t start__      = std::clock();
			double received__         = TheTips().solve(vector <string>(clues, clues + (sizeof clues / sizeof clues[0])), vector <int>(probability, probability + (sizeof probability / sizeof probability[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string clues[]            = {"YYY","NYY","NNY"};
			int probability[]         = {100,0,0};
			double expected__         = 3.0;

			std::clock_t start__      = std::clock();
			double received__         = TheTips().solve(vector <string>(clues, clues + (sizeof clues / sizeof clues[0])), vector <int>(probability, probability + (sizeof probability / sizeof probability[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string clues[]            = {"NNN","NNN","NNN"};
			int probability[]         = {0,0,0};
			double expected__         = 0.0;

			std::clock_t start__      = std::clock();
			double received__         = TheTips().solve(vector <string>(clues, clues + (sizeof clues / sizeof clues[0])), vector <int>(probability, probability + (sizeof probability / sizeof probability[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string clues[]            = {"NYYNYYNNNN","NNNNYNNNYN","YNNYYYYYNN","YYNYNNNNYN","NYNNNNNNNY","YNYYNNYNNY","NYNNYYYYYY","NYYYYNNNNN","YYNYNNYYYN","NNYYNYNYYY"}
;
			int probability[]         = {11,66,99,37,64,45,21,67,71,62} ;
			double expected__         = 9.999891558057332;

			std::clock_t start__      = std::clock();
			double received__         = TheTips().solve(vector <string>(clues, clues + (sizeof clues / sizeof clues[0])), vector <int>(probability, probability + (sizeof probability / sizeof probability[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string clues[]            = {"NNY","NNY","NNN"};
			int probability[]         = {50, 50, 1};
			double expected__         = 1.7525;

			std::clock_t start__      = std::clock();
			double received__         = TheTips().solve(vector <string>(clues, clues + (sizeof clues / sizeof clues[0])), vector <int>(probability, probability + (sizeof probability / sizeof probability[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string clues[]            = ;
			int probability[]         = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = TheTips().solve(vector <string>(clues, clues + (sizeof clues / sizeof clues[0])), vector <int>(probability, probability + (sizeof probability / sizeof probability[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string clues[]            = ;
			int probability[]         = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = TheTips().solve(vector <string>(clues, clues + (sizeof clues / sizeof clues[0])), vector <int>(probability, probability + (sizeof probability / sizeof probability[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string clues[]            = ;
			int probability[]         = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = TheTips().solve(vector <string>(clues, clues + (sizeof clues / sizeof clues[0])), vector <int>(probability, probability + (sizeof probability / sizeof probability[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
