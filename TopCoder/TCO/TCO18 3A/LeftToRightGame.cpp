#include <bits/stdc++.h>

using namespace std;

class LeftToRightGame
{
public:
  int needed, mod;

  char cached[1024][1024];
  char cache[1024][1024];

  bool alice_can_win(int length, int rem)
  {
    if (length == needed) return rem;

    auto& alice_wins = cache[length][rem];

    if (cached[length][rem]) return alice_wins;
    cached[length][rem] = 1;

    bool alice = false;
    bool bob = false;

    for (int dig = 0 + (length ? 0 : 1); dig < 10; ++dig)
    {
      bool res = alice_can_win(length+1, (rem*10 + dig) % mod);
      alice = alice || res;
      bob = bob || !res;
    }

    alice_wins = (length & 1) ? !bob : alice;

    return alice_wins;
  }

  string whoWins(int length, int divisor)
  {
    needed = length;
    mod = divisor;
    memset(cached, 0, sizeof(cached));

    return alice_can_win(0, 0) ? "Alice" : "Bob";
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
		cout << "Testing LeftToRightGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1530979212;
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
		LeftToRightGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int length = 4;
				int divisor = 10;
				_expected = "Bob";
				_received = _obj.whoWins(length, divisor); break;
			}
			case 1:
			{
				int length = 3;
				int divisor = 1000;
				_expected = "Alice";
				_received = _obj.whoWins(length, divisor); break;
			}
			case 2:
			{
				int length = 2;
				int divisor = 3;
				_expected = "Bob";
				_received = _obj.whoWins(length, divisor); break;
			}
			case 3:
			{
				int length = 147;
				int divisor = 47;
				_expected = "Alice";
				_received = _obj.whoWins(length, divisor); break;
			}
			/*case 4:
			{
				int length = ;
				int divisor = ;
				_expected = ;
				_received = _obj.whoWins(length, divisor); break;
			}*/
			/*case 5:
			{
				int length = ;
				int divisor = ;
				_expected = ;
				_received = _obj.whoWins(length, divisor); break;
			}*/
			/*case 6:
			{
				int length = ;
				int divisor = ;
				_expected = ;
				_received = _obj.whoWins(length, divisor); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
