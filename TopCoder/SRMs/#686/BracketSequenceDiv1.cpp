#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bool check(string &s, bool allow_closing = false) {
  stack<char> stk;
  int has_open = 0;
  for (char &c : s) {
    char op = 'A';
    switch (c) {
      case '(':
      case '[':
        stk.push(c);
        has_open++;
        break;
      case ')': op = '('; break;
      case ']': op = '['; break;
    }
    if (op != 'A') {
      if (has_open) {
        if (stk.top() != op) return false;
        else { stk.pop(); has_open--; }
      } else if (allow_closing) {
        stk.push(c);
      } else return false;
    }
  }
  if (allow_closing && has_open) return false;
  s = "";
  while (!stk.empty()) { s += stk.top(); stk.pop(); }
  if (allow_closing) {
    for (char &c : s) {
      switch (c) {
        case '(': c = ')'; break;
        case ')': c = '('; break;
        case '[': c = ']'; break;
        case ']': c = '['; break;
      }
    }
    reverse(s.begin(), s.end());
  }
  return true;
}

class BracketSequenceDiv1 {
public:
    long long count( string s ) {
        int N = s.size();

        int N2 = N>>1;
        int N1 = N - N2;

        map<string, int64> cnt;

        int lmask = (1<<N1);
        for (int mask = 0; mask < lmask; ++mask) {
          string ss = "";
          for (int i = 0; i < N1; ++i) if (mask & (1<<i)) {
            ss += s[i];
          }
          if (check(ss)) {
            cnt[ss]++;
          }
        }

        int64 ret = 0LL;

        lmask = (1<<N2);
        for (int mask = 0; mask < lmask; ++mask) {
          string ss = "";
          for (int i = 0; i < N2; ++i) if (mask & (1<<i)) {
            ss += s[N1+i];
          }
          if (check(ss, true)) ret += cnt[ss];
        }

        ret--;
        return ret;
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
		cout << "Testing BracketSequenceDiv1 (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459213251;
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
		BracketSequenceDiv1 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "()[]";
				_expected = 3LL;
				_received = _obj.count(s); break;
			}
			case 1:
			{
				string s = "())";
				_expected = 2LL;
				_received = _obj.count(s); break;
			}
			case 2:
			{
				string s = "()()";
				_expected = 4LL;
				_received = _obj.count(s); break;
			}
			case 3:
			{
				string s = "([)]";
				_expected = 2LL;
				_received = _obj.count(s); break;
			}
			case 4:
			{
				string s = "())[]][]([]()]]()]]]";
				_expected = 3854LL;
				_received = _obj.count(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = LL;
				_received = _obj.count(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = LL;
				_received = _obj.count(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = LL;
				_received = _obj.count(s); break;
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
