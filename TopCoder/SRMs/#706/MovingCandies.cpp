#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<pair<int,int>> dir = {{-1,0}, {0,-1}, {1, 0}, {0, 1}};

class MovingCandies {
public:
	int minMoved( vector <string> t ) {
    int n = t.size();
    int m = t[0].size();

    int total = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (t[i][j] == '#') total++;
      }
    }

    if (total < (n + m - 1)) return -1;

    int dist[n+m][n][m];
    memset(dist, 0, sizeof(dist));

    queue<pair<int, pair<int,int>>> q;
    dist[t[0][0] == '.' ? 1 : 0][0][0] = 1;
    q.push({t[0][0] == '.' ? 1 : 0, {0, 0}});
    while (!q.empty()) {
      int c = q.front().first;
      int i = q.front().second.first;
      int j = q.front().second.second; q.pop();

      for (auto &d : dir) {
        int ni = i + d.first;
        int nj = j + d.second;
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        int cur = (t[ni][nj] == '.' ? 1 : 0);
        int nc = c + cur;
        if ((nc < (n+m)) && (dist[nc][ni][nj] == 0)) {
          dist[nc][ni][nj] = dist[c][i][j] + 1;
          q.push({nc, {ni, nj}});
        }
      }
    }

    for (int res = 0; res < n+m; ++res) {
      if (!dist[res][n-1][m-1]) continue;
      int has = dist[res][n-1][m-1] - res;
      if (has + res <= total) return res;
    }

    return -1;
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
		cout << "Testing MovingCandies (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485014539;
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
		MovingCandies _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string t[] = {
				             "#...###",
				             "#...#.#",
				             "##..#.#",
				             ".#....#"
				             };
				_expected = 3;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 1:
			{
				string t[] = {
				             "#...###",
				             "#...#.#",
				             "##..###",
				             ".#....#"
				             };
				_expected = 2;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 2:
			{
				string t[] = {
				             ".#..",
				             "##..",
				             "..#.",
				             "..#.",
				             "..##",
				             "..##"
				             };
				_expected = 2;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 3:
			{
				string t[] = {
				             ".....",
				             ".###.",
				             "####.",
				             "....."
				             };
				_expected = -1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 4:
			{
				string t[] = {
				             ".#...#.###.#",
				             "#.#.##......",
				             ".#.#......#.",
				             "..#.......#.",
				             "##.........."
				             };
				_expected = 9;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 5:
			{
				string t[] = {
				             "###.#########..#####",
				             ".#######.###########"
				             };
				_expected = 0;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 6:
			{
				string t[] = {
				             "..",
				             ".."
				             };
				_expected = -1;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			/*case 7:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string t[] = ;
				_expected = ;
				_received = _obj.minMoved(vector <string>(t, t+sizeof(t)/sizeof(string))); break;
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
