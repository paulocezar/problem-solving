#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class TaroJiroGrid {
public:
    bool check(vector<string> &grid) {
        int N = grid.size();
        for (int j = 0; j < N; ++j) {
            int cnt = 1;
            int i = 1;
            while (i < N) {
                if (grid[i][j] == grid[i-1][j]) cnt++;
                else {
                    if ((2*cnt) > N) return false;
                    cnt = 1;
                }
                i++;
            }
            if ((2*cnt) > N) return false;
        }
        return true;
    }
    int getNumber( vector <string> grid ) {
        int N = grid.size();
        
        if (check(grid)) return 0;
        
        for (int i = 0; i < N; ++i) {
            string old = grid[i];
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 'W') grid[i][j] = 'B';
            }
            if (check(grid)) return 1;
            grid[i] = old;
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 'B') grid[i][j] = 'W';
            }
            if (check(grid)) return 1;
            grid[i] = old;
        }
        
        return 2;
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
			string grid[]             = {"WB",
 "BB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string grid[]             = {"WB",
 "WW"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string grid[]             = {"WB",
 "WB"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string grid[]             = {"WBBW",
 "WBWB",
 "WWBB",
 "BWWW"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string grid[]             = {"WBBWBB",
 "BBWBBW",
 "WWBWBW",
 "BWWBBB",
 "WBWBBW",
 "WWWBWB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])));
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
