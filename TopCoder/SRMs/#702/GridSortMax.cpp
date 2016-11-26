#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class GridSortMax {
public:
  string findMax( int n, int m, vector <int> grid ) {
  	int gr[n][m];
  	for (int i = 0; i < n; ++i) {
  		for (int j = 0; j < m; ++j) {
  			gr[i][j] = grid[i*m + j];
  		}
  	}

  	int cur = 1;

  	set<int> line_blocked, col_blocked;

  	for (int i = 0; i < n; ++i) {
  		for (int j = 0; j < m; ++j) {

  			if (gr[i][j] != cur && (!line_blocked.count(i) || !col_blocked.count(j))) {
  				for (int ii = 0; ii < n; ++ii) {
  					for (int jj = 0; jj < m; ++jj) {
  						if (gr[ii][jj] == cur) {
  							if (i != ii && (line_blocked.count(i) || line_blocked.count(ii))) goto somewhere;
  							if (j != jj && (col_blocked.count(j) || col_blocked.count(jj))) goto somewhere;
  							if (i != ii) {
  								for (int aj = 0; aj < m; ++aj) {
  									swap(gr[i][aj], gr[ii][aj]);
  								}
  							}
  							if (j != jj) {
  								for (int ai = 0; ai < n; ++ai) {
  									swap(gr[ai][j], gr[ai][jj]);
  								}
  							}
  							goto somewhere;
  						}
  					}
  				}
  			}

			somewhere:
  			if (gr[i][j] == cur) {
  				line_blocked.insert(i);
  				col_blocked.insert(j);
  			}
  			cur++;
  		}
  	}

  	string res = "";
  	cur = 1;
  	for (int i = 0; i < n; ++i) {
  		for (int j = 0; j < m; ++j) {
  			if (gr[i][j] == cur) res += "1";
  			else res += "0";
  			cur++;
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
		cout << "Testing GridSortMax (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1479175204;
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
		GridSortMax _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int m = 2;
				int grid[] = {
				              1,2,
				              3,4
				             };
				_expected = "1111";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int m = 2;
				int grid[] = {
				              2,1,
				              3,4
				             };
				_expected = "1100";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 2;
				int m = 2;
				int grid[] = {
				              4,2,
				              3,1
				             };
				_expected = "1001";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 1;
				int m = 10;
				int grid[] = {10,6,2,3,5,7,1,9,4,8};
				_expected = "1111111111";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 3;
				int m = 5;
				int grid[] = {
				              5,2,10,7,9,
				              3,4,14,11,1,
				              15,12,6,8,13
				             };
				_expected = "101100100100000";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 6;
				int m = 2;
				int grid[] = {
				              3,9,
				              5,1,
				              10,6,
				              2,7,
				              8,11,
				              12,4
				             };
				_expected = "100000101010";
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}
			/*case 6:
			{
				int n = ;
				int m = ;
				int grid[] = ;
				_expected = ;
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int m = ;
				int grid[] = ;
				_expected = ;
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int n = ;
				int m = ;
				int grid[] = ;
				_expected = ;
				_received = _obj.findMax(n, m, vector <int>(grid, grid+sizeof(grid)/sizeof(int))); break;
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
