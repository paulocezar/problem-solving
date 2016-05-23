#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> a;
int n, first;
int64 k;

int cache[64][64][64][64];
char cached[64][64][64][64];

int solve(int last, int sm1, int sm2, int at) {
  if (at == n) return 0;
  int &ret = cache[last][sm1][sm2][at];
  if (cached[last][sm1][sm2][at]) return ret;
  cached[last][sm1][sm2][at] = 1;
  ret = solve(last, sm1, sm2, at+1);
  int64 bg = a[at] - a[first];

  int64 ax = a[at] - a[last];
  int64 sm = a[sm2] - a[sm1];
  int nsm1 = sm1, nsm2 = sm2;
  if ((sm == 0LL) || (ax < sm)) {
    sm = ax;
    nsm1 = last, nsm2 = at;
  }
  if (bg <= (k*sm)) ret = max(ret, 1 + solve(at, nsm1, nsm2, at+1));
  return ret;
}

class CliqueParty {
	public:
	int maxsize(vector <int> _a, int _k) {
    a = _a; k = _k;
    sort(a.begin(), a.end());
    n = a.size();
    int ans = 0;
    for (first = 0; first < n; ++first) {
      memset(cached, 0, sizeof(cached));
      ans = max(ans, 1 + solve(first, first, first, first+1));
    }
    return ans;
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
		cout << "Testing CliqueParty (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457366445;
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
		CliqueParty _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1,2,3};
				int k = 2;
				_expected = 3;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 1:
			{
				int a[] = {1,2,3};
				int k = 1;
				_expected = 2;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 2:
			{
				int a[] = {4,10,5,6};
				int k = 2;
				_expected = 3;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 3:
			{
				int a[] = {1,2,3,4,5,6};
				int k = 3;
				_expected = 4;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 4:
			{
				int a[] = {10,9,25,24,23,30};
				int k = 7;
				_expected = 4;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			case 5:
			{
				int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
				int k = 42;
				_expected = 1;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}
			/*case 6:
			{
				int a[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int k = ;
				_expected = ;
				_received = _obj.maxsize(vector <int>(a, a+sizeof(a)/sizeof(int)), k); break;
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
