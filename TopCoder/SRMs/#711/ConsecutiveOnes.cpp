#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class ConsecutiveOnes {
public:
    long long get(long long n, int k) {
    	auto mxcon = [](int64 ax) {
    		int cnt = 0, mx = 0;
    		while (ax > 0LL) {
    			if (ax & 1LL) cnt++;
    			else { mx = max(mx, cnt); cnt = 0; }
    			ax >>= 1;
    		}
    		mx = max(mx, cnt);
    		return mx;
    	};

    	if (mxcon(n) >= k) return n;

    	int64 res = n | ((1LL << k) - 1LL);
    	int64 bit = 1LL << k;

    	while (bit) {
    		if ((res & bit) && ((res ^ bit) >= n)) {
    			if (mxcon(res ^ bit) >= k) res ^= bit;
    		}
    		bit >>= 1;
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
		cout << "Testing ConsecutiveOnes (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1490434505;
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
		ConsecutiveOnes _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long n = 1LL;
				int k = 2;
				_expected = 3LL;
				_received = _obj.get(n, k); break;
			}
			case 1:
			{
				long long n = 5LL;
				int k = 2;
				_expected = 6LL;
				_received = _obj.get(n, k); break;
			}
			case 2:
			{
				long long n = 7LL;
				int k = 2;
				_expected = 7LL;
				_received = _obj.get(n, k); break;
			}
			case 3:
			{
				long long n = 364269800189924LL;
				int k = 33;
				_expected = 364273356242943LL;
				_received = _obj.get(n, k); break;
			}
			/*case 4:
			{
				long long n = LL;
				int k = ;
				_expected = LL;
				_received = _obj.get(n, k); break;
			}*/
			/*case 5:
			{
				long long n = LL;
				int k = ;
				_expected = LL;
				_received = _obj.get(n, k); break;
			}*/
			/*case 6:
			{
				long long n = LL;
				int k = ;
				_expected = LL;
				_received = _obj.get(n, k); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
