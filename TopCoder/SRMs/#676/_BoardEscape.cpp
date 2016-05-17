#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dx[] = {-1,+1, 0, 0};
int dy[] = { 0, 0,-1,+1};

class BoardEscape {
	public:
	string findWinner(vector <string> s, int k) {
		if (k & 1) { k = min(k, 5001); }
		else { k = min(k, 5000); }

		int r = s.size();
		int c = s[0].size();

		int grundy[2][r][c];
		int old = 0, cur = 1;

		for (int step = 0; step < k; ++step) {
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					if (s[i][j] == 'E') {
						grundy[cur][i][j] = 0;
						continue;
					}
					set<int> seen;
					for (int dir = 0; dir < 4; ++dir) {
						int ni = i+dx[dir];
						int nj = j+dy[dir];
						if (ni < 0 || nj < 0 || ni >= r || nj >= c || (s[ni][nj]=='#')) continue;
						seen.insert(grundy[old][ni][nj]);
					}
					int r = 0;
					while (seen.count(r)) r++;
					grundy[cur][i][j] = r;
				}
			}
			old = 1-old;
			cur = 1-cur;
		}


		int xr = 0;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (s[i][j] == 'T') xr ^= grundy[old][i][j];
			}
 		}

		if (xr) return "Alice";
		return "Bob";
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
		cout << "Testing BoardEscape (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450455867;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BoardEscape _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s[] = {"TE"};
				int k = 2;
				_expected = "Alice";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 1:
			{
				string s[] = {"E#E",
				              "#T#",
				              "E#E"};
				int k = 1000000;
				_expected = "Bob";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 2:
			{
				string s[] = {"T.T.T.",
				              ".E.E.E"};
				int k = 1;
				_expected = "Alice";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 3:
			{
				string s[] = {"TTE"};
				int k = 6;
				_expected = "Alice";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 4:
			{
				string s[] = {"..........................",
				              "......TTT..TTT..T...T.....",
				              ".....T.....T..T.TT.TT.....",
				              "......TTT..TTT..T.T.T.....",
				              ".........T.T.T..T...T.....",
				              "......TTT..T..T.T...T.....",
				              "..........................",
				              "...E#E#E#E#E#E#E#E#E#E#...",
				              "..........................",
				              "......TTT..TTT...TTT......",
				              ".....T........T.T.........",
				              "......TTT.....T..TTT......",
				              ".....T...T...T..T...T.....",
				              "......TTT....T...TTT......",
				              "..........................",
				              "...#E#E#E#E#E#E#E#E#E#E...",
				              "..........................",
				              "....TT...T...T..T.TTT.T...",
				              "...T.....T...T..T.T...T...",
				              "...T.TT..T...TTTT.TT..T...",
				              "...T..T..T...T..T.T.......",
				              "....TT...TTT.T..T.T...T...",
				              ".........................."};
				int k = 987654321;
				_expected = "Bob";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			/*case 5:
			{
				string s[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}*/
			/*case 6:
			{
				string s[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}*/
			/*case 7:
			{
				string s[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
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
