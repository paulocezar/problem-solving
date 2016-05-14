#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<pair<int,int>> neigh = {{-1,0}, {+1,0}, {0,-1}, {0,+1}};

class ColorfulGarden {
public:
    vector <string> rearrange( vector <string> garden ) {
        map<char, int> cnt;
        for (auto &row : garden) {
          for (char &flower : row) {
            cnt[flower]++;
          }
        }
        vector<pair<int, char>> needed;
        for (auto &ntry : cnt) {
          needed.push_back(make_pair(-ntry.second, ntry.first));
        }
        sort(needed.begin(), needed.end());
        int n = garden[0].size();
        vector<string> res(2, string(n, ' '));

        int i = 0, j = 0;
        for (auto &put : needed) {

        	while (put.first) {
          	bool ok = true;
          	int tries = 0;
          	do {
          		if (tries > 2*n) break;
          		tries++;

          		if (j >= n) {
          			j = 0;
          			i = 1-i;
          		}

          		ok = res[i][j] == ' ';

          		for (auto &dir : neigh) {
          			int ii = i+dir.first;
          			int jj = j+dir.second;
          			if (0 <= ii && ii < 2 && 0 <= jj && jj < n) {
          				if (res[ii][jj] == put.second) ok = false;
          			}
          		}
          		if (!ok) j++;
          	} while (!ok);

          	if (!ok) {
          		res.clear();
          		goto hell;
          	}

          	res[i][j] = put.second;

          	put.first++;
          	j++;
          	if (put.first) {
          		j++;
          	}

          }
        }
      hell:
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
		cout << "Testing ColorfulGarden (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1461427229;
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
		ColorfulGarden _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string garden[] = {"aa",
				                   "bb"};
				string __expected[] = {"ab", "ba" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 1:
			{
				string garden[] = {"xxxx",
				                   "xxxx"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 2:
			{
				string garden[] = {"abcd",
				                   "abcd"};
				string __expected[] = {"abcd", "dcba" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 3:
			{
				string garden[] = {"abcdefghijklm",
				                   "nopqrstuvwxyz"};
				string __expected[] = {"abcdefghijklm", "nopqrstuvwxyz" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 4:
			{
				string garden[] = {"aaa",
				                   "aab"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 5:
			{
				string garden[] = {"aaaac",
													 "bbbbc"};
				string __expected[] = { "ababa",
																"cabcb"};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			/*case 6:
			{
				string garden[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string garden[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
