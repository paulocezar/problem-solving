#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int N;
vector<int> a;

int cache[64][1 << 15];
char cached[64][1 << 15];

int solve(int msk, int x) {
	if (!msk) return x;

	int &res = cache[x][msk];
	if (cached[x][msk]) return res;
	cached[x][msk] = 1;

	res = -1;
	int rem = __builtin_popcount(msk);
	for (int i = 0; i < N; ++i) {
		if (msk & (1 << i)) {
			int nxt = x + (x ^ a[i]);
			int nn = nxt & 63;

			res = max(res, ((nxt ^ nn) << (rem-1)) + solve(msk ^ (1<<i), nn));
		}
	}

	return res;
}

class Xscoregame {
public:
    int getscore(vector <int> A) {
    	a = A; N = a.size(); memset(cached, 0, sizeof(cached));
    	return solve((1 << a.size()) - 1, 0);
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
		cout << "Testing Xscoregame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487693113;
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
		Xscoregame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1,2,3};
				_expected = 12;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {10,0,0,0};
				_expected = 80;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {1,1,1,1,1,1};
				_expected = 1;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {1,0,1,0,1,0,1,0};
				_expected = 170;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {50,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
				_expected = 830122;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 5:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.getscore(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
