#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class DengklekGaneshAndChains {
public:
    string getBestChains( vector <string> chains, vector <int> lengths ) {
    	int N = chains.size();
    	int K = chains[0].size();

    	for (auto& s : chains) {
    		string best = s;
    		for (int r = 1; r < K; ++r) {
    			rotate(s.begin(), s.begin()+1, s.end());
    			if (s > best) best = s;
    		}
    		s = best;
    	}
    	sort(chains.begin(), chains.end());

    	string res = "";
    	for (int v : lengths) {
    		string pick = "";
    		int idx = -1;
    		for (int i = 0; i < N; ++i) {
    			if (!chains[i].size()) continue;
    			string cur = chains[i].substr(0, v);
    			if (idx == -1 || cur > pick) {
    				pick = cur;
    				idx = i;
    			}
    		}
    		res += pick;
    		chains[idx] = "";
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
		cout << "Testing DengklekGaneshAndChains (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1499529688;
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
		DengklekGaneshAndChains _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string chains[] = {"topc", "oder", "open", "twob"};
				int lengths[] = {2, 1, 3};
				_expected = "wotrod";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 1:
			{
				string chains[] = {"ssh", "she", "see", "sea"};
				int lengths[] = {2, 3, 2, 3};
				_expected = "ssshesesee";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 2:
			{
				string chains[] = {"wri", "ter", "who", "are", "you"};
				int lengths[] = {3};
				_expected = "you";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 3:
			{
				string chains[] = {"harus", "imfyo"};
				int lengths[] = {5, 5};
				_expected = "yoimfushar";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			/*case 4:
			{
				string chains[] = ;
				int lengths[] = ;
				_expected = ;
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				string chains[] = ;
				int lengths[] = ;
				_expected = ;
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string chains[] = ;
				int lengths[] = ;
				_expected = ;
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
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
