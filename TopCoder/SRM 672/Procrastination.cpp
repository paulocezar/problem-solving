#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

map<int64, int> cur_pos;
map<int64, vector<int64>> divisorsOf;

void addDivisors(int64 val) {
	if (divisorsOf.count(val)) return;
	vector<int64>& divisors = divisorsOf[val];
	for (int64 i = 2LL; i*i <= val; ++i) {
		if ((val % i) == 0LL) {
			divisors.push_back(i);
			if (val != i*i) divisors.push_back(val/i);
		}
	}
	sort(divisors.begin(), divisors.end());
	cur_pos[val] = 0;
}

int64 find_next(int64 val, int64 hour) {
	addDivisors(val);
	int& pos = cur_pos[val]; 
	vector<int64>& divisor = divisorsOf[val];
	int has = divisor.size();
	while (pos < has && divisor[pos] <= hour) pos++;
	if (pos == has) return -1LL;
	return divisor[pos];
}

class Procrastination {
public:
    long long findFinalAssignee( long long n ) {
        int64 hour = 1LL;
        int64 cur = n;

        cur_pos.clear();
        divisorsOf.clear();

        while (true) {
        	int64 prev = cur-1;
        	int64 a = find_next(prev, hour);
        	int64 b = find_next(cur, hour);
        	if (a == b && a == -1LL) break;
        	if (a == -1LL) a = b+1LL;
        	if (b == -1LL) b = a+1LL;
            if (a < b) {
        		cur--;
        		hour = a;
        	} else {
        		cur++;
        		hour = b;
        	}
        }

        return cur;
    }
};

// BEGIN CUT HERE
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
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
			long long n               = 3;
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long n               = 8;
			long long expected__      = 11;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long n               = 20;
			long long expected__      = 20;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long n               = 196248;
			long long expected__      = 196259;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long n               = 5587021440LL;
			long long expected__      = 5587021440LL;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			long long n               = 1;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			long long n               = 10000000000LL;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			long long n               = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Procrastination().findFinalAssignee(n);
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
