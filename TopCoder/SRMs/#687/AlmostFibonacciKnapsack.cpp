#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class AlmostFibonacciKnapsack {
public:
    vector <int> getIndices( long long x ) {
    	vector<int64> nums = {2, 3};

    	for (int i = 2; ; ++i) {
    		nums.push_back(nums[i-1] + nums[i-2] - 1LL);
    		if (nums.back() >= x) break;
    	}

    	vector<int> res = {};

    	while (x > 1LL) {
    		int at = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
    		res.push_back(at);
    		x -= nums[at-1];
    	}

    	if (x > 1) return { -1 };
    	else if (x == 1) {
    		if (res.back() < 3) return { -1 };
    		res[res.size() - 1] -= 1;
    		res.push_back(res.back() - 1);
    	}

    	return res;
    }
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "Testing AlmostFibonacciKnapsack (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460026806;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AlmostFibonacciKnapsack _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long x = 148LL;
				int __expected[] = {6, 10, 8, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}
			case 1:
			{
				long long x = 2LL;
				int __expected[] = {1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}
			case 2:
			{
				long long x = 13LL;
				int __expected[] = {2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}
			case 3:
			{
				long long x = 3LL;
				int __expected[] = {2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}
			case 4:
			{
				long long x = 86267769395LL;
				int __expected[] = {3, 14, 15, 9, 26, 53, 5, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}
			case 5:
			{
				long long x = int64(1e18);
				int __expected[] = {-1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}
			/*case 6:
			{
				long long x = LL;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}*/
			/*case 7:
			{
				long long x = LL;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getIndices(x); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
