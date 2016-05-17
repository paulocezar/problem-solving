#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod = 1000000007LL;

vector<int> w, h;

int64 memo[64][64];
int last_seen[64][64], seen_now, fix, n, fix_val;

int64 solve(int pos, int last_bound) {
	if (pos == n) return 1LL;

	int64 &ret = memo[pos][last_bound];

	if (last_seen[pos][last_bound] == seen_now) return ret;
	
	last_seen[pos][last_bound] = seen_now;
	ret = 0LL;

	while ((last_bound < n) && ((h[last_bound]*w[pos]) < fix_val)) last_bound++;

	int options = last_bound - (pos-1);
	if (last_bound > fix) options--;
	
	if (options > 0) {
		ret = (int64(options) * solve(pos+1, last_bound)) % mod;
	}
	
	return ret;
}

class BearCavalry {
	public:
	int countAssignments(vector <int> warriors, vector <int> horses) {
		
		sort(warriors.begin()+1, warriors.end(), greater<int>());
		sort(horses.begin(), horses.end());
		
		w = warriors;
		h = horses;
		
		n = warriors.size();

		int64 ans = 0LL;
		
		for (fix = 0; fix < n; ++fix) {
			seen_now++;
			fix_val = h[fix] * w[0];
			ans += solve(1, 0);
			ans %= mod;
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
		cout << "Testing BearCavalry (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1447862404;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BearCavalry _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int warriors[] = {5,8,4,8};
				int horses[] = {19,40,25,20};
				_expected = 2;
				_received = _obj.countAssignments(vector <int>(warriors, warriors+sizeof(warriors)/sizeof(int)), vector <int>(horses, horses+sizeof(horses)/sizeof(int))); break;
			}
			case 1:
			{
				int warriors[] = {1,1};
				int horses[] = {1,1};
				_expected = 0;
				_received = _obj.countAssignments(vector <int>(warriors, warriors+sizeof(warriors)/sizeof(int)), vector <int>(horses, horses+sizeof(horses)/sizeof(int))); break;
			}
			case 2:
			{
				int warriors[] = {10,2,10};
				int horses[] = {100,150,200};
				_expected = 3;
				_received = _obj.countAssignments(vector <int>(warriors, warriors+sizeof(warriors)/sizeof(int)), vector <int>(horses, horses+sizeof(horses)/sizeof(int))); break;
			}
			case 3:
			{
				int warriors[] = {10,20};
				int horses[] = {1,3};
				_expected = 1;
				_received = _obj.countAssignments(vector <int>(warriors, warriors+sizeof(warriors)/sizeof(int)), vector <int>(horses, horses+sizeof(horses)/sizeof(int))); break;
			}
			case 4:
			{
				int warriors[] = {20,20,25,23,24,24,21};
				int horses[] = {20,25,25,20,25,23,20};
				_expected = 0;
				_received = _obj.countAssignments(vector <int>(warriors, warriors+sizeof(warriors)/sizeof(int)), vector <int>(horses, horses+sizeof(horses)/sizeof(int))); break;
			}
			case 5:
			{
				int warriors[] = {970,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,
				                 800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800};
				int horses[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
				               1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
				               1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
				_expected = 318608048;
				_received = _obj.countAssignments(vector <int>(warriors, warriors+sizeof(warriors)/sizeof(int)), vector <int>(horses, horses+sizeof(horses)/sizeof(int))); break;
			}
			/*case 6:
			{
				int warriors[] = ;
				int horses[] = ;
				_expected = ;
				_received = _obj.countAssignments(vector <int>(warriors, warriors+sizeof(warriors)/sizeof(int)), vector <int>(horses, horses+sizeof(horses)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int warriors[] = ;
				int horses[] = ;
				_expected = ;
				_received = _obj.countAssignments(vector <int>(warriors, warriors+sizeof(warriors)/sizeof(int)), vector <int>(horses, horses+sizeof(horses)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int warriors[] = ;
				int horses[] = ;
				_expected = ;
				_received = _obj.countAssignments(vector <int>(warriors, warriors+sizeof(warriors)/sizeof(int)), vector <int>(horses, horses+sizeof(horses)/sizeof(int))); break;
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
