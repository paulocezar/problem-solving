#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char gr[26][26];
char seen[26];

bool has_cycle(int u) {
	seen[u] = 1;

	for (int v = 0; v < 26; ++v) {
		if (gr[u][v]) {
			if (seen[v] == 1) return true;
			/* next time don't ignore the bugs you find motherfucker.. */
			if (/*!seen[v] && */has_cycle(v)) return true;
		}
	}
	seen[u] = 2;
	return false;
}

class AlphabetOrderDiv1 {
public:
	string isOrdered( vector <string> words ) {

		memset(gr, 0, sizeof(gr));

		for (auto &w : words) {
			int n = w.size();
			for (int i = 0; i < n; ++i) {
				for (int j = i+1; j < n; ++j) {
					if (w[i] != w[j]) {
						gr[w[i]-'a'][w[j]-'a'] = 1;
					}
				}
			}
		}

		memset(seen, 0, sizeof(seen));

		for (int i = 0; i < 26; ++i) if (has_cycle(i)) return "Impossible";
		return "Possible";
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
		cout << "Testing AlphabetOrderDiv1 (225.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484186405;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 225.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AlphabetOrderDiv1 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"single","round","match"};
				_expected = "Possible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"topcoder","topcoder"};
				_expected = "Impossible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"algorithm", "contest"};
				_expected = "Impossible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"pink","floyd"};
				_expected = "Possible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 4:
			{
				string words[] = {"gimnasia","y","esgrima","la","plata"};
				_expected = "Impossible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 5:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
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
