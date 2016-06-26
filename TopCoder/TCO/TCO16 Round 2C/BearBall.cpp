#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class BearBall {
public:
    int countThrows( vector <int> x, vector <int> y ) {
        int res = 0;
        int N = x.size();
        for (int i = 0; i < N; ++i) {

          map<double, vector<int>> lines;
//cout << "FIX: " << x[i] << " " << y[i] << endl;
          for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            double dx = x[j] - x[i];
            double dy = y[j] - y[i];

            if (x[i] != x[j]) {
              lines[dy / dx].push_back(j);
            } else {
              lines[-1e9].push_back(j);
            }
          }

          for (auto &ntry : lines) {
            vector<int> &vec = ntry.second;
            sort(vec.begin(), vec.end(), [&](int a, int b) {
              if (x[a] != x[b]) return x[a] < x[b];
              return y[a] < y[b];
            });
            int l = 0, sz = vec.size();
            while (l < sz && ((x[vec[l]] < x[i]) || ((x[vec[l]] == x[i]) && (y[vec[l]] < y[i])))) l++;
//cout << "LEFT:" << endl;
//for (int j = 0; j < l; ++j) cout << x[vec[j]] << " " << y[vec[j]] << endl;
//cout << "RIGHT:" << endl;
//for (int j = l; j < sz; ++j) cout << x[vec[j]] << " " << y[vec[j]] << endl;
            int r = sz - l;
            int at_one = 0;
            if (l) at_one++;
            if (r) at_one++;

            if (lines.size() > 1) {
              int at_two = sz - at_one;
              res += at_one;
              res += 2 * at_two;
//cout << " at one: " << at_one << endl;
//cout << " at two: " << at_two << endl;
            } else {
              res += (l * (l+1)) / 2;
              res += (r * (r+1)) / 2;
            }
          }
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
		cout << "Testing BearBall (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1466269219;
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
		BearBall _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,4,2};
				int y[] = {1,10,7};
				_expected = 6;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0,0,0,1,1};
				int y[] = {0,1,2,0,1};
				_expected = 22;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {5,7,9,11};
				int y[] = {4,3,2,1};
				_expected = 20;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {10,10,50,50,90,90};
				int y[] = {5,17,5,17,5,17};
				_expected = 34;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {-100, -90, -80, -70, -85, -90, 0, 20};
				int y[] = {-5, -8, -13, -21, -13, -13, -13, -69};
				_expected = 68;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
