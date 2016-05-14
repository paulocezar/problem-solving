#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class MultiplicationTable2 {
public:
    int minimalGoodSet( vector <int> table ) {
        int n = 1;
        int n2 = table.size();
        while (n*n < n2) n++;

        int res = n;
        for (int first = 0; first < n; ++first) {
          queue<int> q;
          set<int> s;
          s.insert(first);
          q.push(first);
          while (!q.empty()) {
            int u = q.front(); q.pop();
            set<int> add;
            for (auto &el : s) {
              int res1 = table[el*n + u];
              int res2 = table[u*n + el];
              if (!s.count(res1)) add.insert(res1);
              if (!s.count(res2)) add.insert(res2);
            }
            for (auto &el : add) {
              q.push(el);
              s.insert(el);
            }
          }
          res = min(res, (int)s.size());
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
		cout << "Testing MultiplicationTable2 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458403208;
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
		MultiplicationTable2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int table[] = {1,1,2,3,
				               1,0,3,2,
				               2,0,1,3,
				               1,2,3,0};
				_expected = 2;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
			}
			case 1:
			{
				int table[] = {0,1,2,3,
				               1,2,3,0,
				               2,3,0,1,
				               3,0,1,2};
				_expected = 1;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
			}
			case 2:
			{
				int table[] = {1,1,1,1,
				               2,2,2,2,
				               3,3,3,3,
				               0,0,0,0};
				_expected = 4;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
			}
			case 3:
			{
				int table[] = {0};
				_expected = 1;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
			}
			/*case 4:
			{
				int table[] = ;
				_expected = ;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int table[] = ;
				_expected = ;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int table[] = ;
				_expected = ;
				_received = _obj.minimalGoodSet(vector <int>(table, table+sizeof(table)/sizeof(int))); break;
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
