#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dp[128][128][128];

class CheeseSlicing {
public:
	int totalArea( int A, int B, int C, int S ) {
		memset(dp, 0, sizeof(dp));

		auto get = [](int x, int y, int z) {
			if (x > y) swap(x, y);
			if (x > z) swap(x, z);
			if (y > z) swap(y, z);
			return dp[x][y][z];
		};

		for (int x = S; x <= 100; ++x) {
			for (int y = x; y <= 100; ++y) {
				for (int z = y; z <= 100; ++z) {
					int &ret = dp[x][y][z];
					ret = y * z;

					for (int s = 1; 2*s <= x; ++s) {
						ret = max(ret, get(s, y, z) + get(x-s, y, z));
					}
					for (int s = 1; 2*s <= y; ++s) {
						ret = max(ret, get(s, x, z) + get(y-s, x, z));
					}
					for (int s = 1; 2*s <= z; ++s) {
						ret = max(ret, get(s, x, y) + get(z-s, x, y));
					}

				}
			}
		}
		return get(A, B, C);
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
		cout << "Testing CheeseSlicing (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491063279;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CheeseSlicing _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 1;
				int B = 3;
				int C = 3;
				int S = 2;
				_expected = 0;
				_received = _obj.totalArea(A, B, C, S); break;
			}
			case 1:
			{
				int A = 5;
				int B = 3;
				int C = 5;
				int S = 3;
				_expected = 25;
				_received = _obj.totalArea(A, B, C, S); break;
			}
			case 2:
			{
				int A = 5;
				int B = 5;
				int C = 5;
				int S = 2;
				_expected = 58;
				_received = _obj.totalArea(A, B, C, S); break;
			}
			case 3:
			{
				int A = 49;
				int B = 92;
				int C = 20;
				int S = 3;
				_expected = 30045;
				_received = _obj.totalArea(A, B, C, S); break;
			}
			case 4:
			{
				int A = 100;
				int B = 100;
				int C = 100;
				int S = 1;
				_expected = 1000000;
				_received = _obj.totalArea(A, B, C, S); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				int C = ;
				int S = ;
				_expected = ;
				_received = _obj.totalArea(A, B, C, S); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				int C = ;
				int S = ;
				_expected = ;
				_received = _obj.totalArea(A, B, C, S); break;
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
