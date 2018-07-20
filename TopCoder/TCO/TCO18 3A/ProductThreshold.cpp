#include <bits/stdc++.h>

using namespace std;

class ProductThreshold
{
public:
	long long subarrayCount(int N, int limit, vector<int> Aprefix, int spread, int offset)
	{
		A = vector<int>(N);
		X = limit;

		const int p = Aprefix.size();
		for (int i = 0; i < p; ++i)
			A[i] = Aprefix[i];
		int seed = abs(A[p-1]);
		for (int i = p; i < N; ++i)
		{
			seed = (seed * 1103515245LL + 12345LL) & ((1LL<<31) - 1LL);
			A[i] = (seed % spread) + offset;
		}

		const int64_t all = (N * (N+1LL)) >> 1;
		return all - divide_and_conquer(0, N-1);
	}
private:
	static void constrain(int64_t& value)
	{
		value = max(-BIG_PRODUCT, min(value, BIG_PRODUCT));
	}

	int64_t divide_and_conquer(int l, int r) const
	{
		if (l == r) return A[l] > X ? 1 : 0;
		const int mid = (l + r) >> 1;

		deque<int> prefixes;

		int64_t prefix = 1;
		for (int i = mid+1; i <= r; ++i)
		{
			prefix *= A[i];
			constrain(prefix);

			// 0 will never be greater than X
			if (prefix == 0)
				break;

			// we build prefixes sorted by checking the sign as the absolute value of
			// the product might only increase
			if (prefix < 0) prefixes.push_front(prefix);
			else prefixes.push_back(prefix);
		}

		int64_t crossing = 0;
		int64_t suffix = 1;
		for (int i = mid; i >= l; --i)
		{
			suffix *= A[i];
			constrain(suffix);

			// 0 will never be greater than X
			if (suffix == 0)
				break;

			if (suffix < 0)
			{
				// a negative suffix must be combined with a negative prefix to get a
				// product greater than X. we need abs(prefix) > X / abs(suffix)
				crossing += lower_bound(prefixes.begin(), prefixes.end(), X / suffix) - prefixes.begin();
			}
			else
			{
				// with a positive suffix we simply need prefix > X / suffix
				crossing += prefixes.end() - upper_bound(prefixes.begin(), prefixes.end(), X / suffix);
			}
		}

		return divide_and_conquer(l, mid) + divide_and_conquer(mid+1, r) + crossing;
	}

	static constexpr int64_t BIG_PRODUCT = 2e9;

	int64_t X;
	vector<int> A;
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
		cout << "Testing ProductThreshold (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1531572131;
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
		ProductThreshold _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int limit = 5;
				int Aprefix[] = {1,2,3,-4,5};
				int spread = 1;
				int offset = 1;
				_expected = 13LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}
			case 1:
			{
				int N = 10;
				int limit = 8;
				int Aprefix[] = {2,2,2,2,2,2,2,2,2,2};
				int spread = 1;
				int offset = 47;
				_expected = 27LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}
			case 2:
			{
				int N = 20;
				int limit = 999888777;
				int Aprefix[] = {47};
				int spread = 7654321;
				int offset = 1;
				_expected = 21LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}
			case 3:
			{
				int N = 5;
				int limit = 8;
				int Aprefix[] = {3,0,3,0,3};
				int spread = 47;
				int offset = 47;
				_expected = 15LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}
			case 4:
			{
				int N = 1000;
				int limit = 1;
				int Aprefix[] = {-1};
				int spread = 1;
				int offset = 2;
				_expected = 1000LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}
			case 5:
			{
				int N = 100;
				int limit = 47;
				int Aprefix[] = {1};
				int spread = 1;
				int offset = 1;
				_expected = 5050LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}
			/*case 6:
			{
				int N = ;
				int limit = ;
				int Aprefix[] = ;
				int spread = ;
				int offset = ;
				_expected = LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}*/
			/*case 7:
			{
				int N = ;
				int limit = ;
				int Aprefix[] = ;
				int spread = ;
				int offset = ;
				_expected = LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
			}*/
			/*case 8:
			{
				int N = ;
				int limit = ;
				int Aprefix[] = ;
				int spread = ;
				int offset = ;
				_expected = LL;
				_received = _obj.subarrayCount(N, limit, vector <int>(Aprefix, Aprefix+sizeof(Aprefix)/sizeof(int)), spread, offset); break;
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
