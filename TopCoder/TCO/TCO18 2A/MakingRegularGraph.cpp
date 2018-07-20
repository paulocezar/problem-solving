#include <bits/stdc++.h>

using namespace std;
using edge = pair<int, int>;

vector<int> res;

bool doit(vector<int>& degree, vector<edge>&edges, vector<edge>::iterator it)
{
	if (it == edges.end())
	{
		for (int i : degree)
			if (i < 2) return false;

		return true;
	}

	auto& candidate = *it;
	if (degree[candidate.first] < 2 && degree[candidate.second] < 2)
	{
		++degree[candidate.first];
		++degree[candidate.second];
		if (doit(degree, edges, it + 1))
		{
			res.push_back(candidate.second);
			res.push_back(candidate.first);
			return true;
		}
		--degree[candidate.first];
		--degree[candidate.second];
	}

	return doit(degree, edges, ++it);
}

class MakingRegularGraph
{
public:
	vector<int> addEdges(int n, vector<int> x, vector<int> y)
	{
		const int e = x.size();
		vector<int> degree(n, 0);

		set<edge> edges;
		for (int i = 0; i < e; ++i)
		{
			edges.emplace(x[i], y[i]);
			++degree[x[i]];
			++degree[y[i]];
		}

		vector<edge> available;
		for (int i = 0; i < n; ++i)
		{
			if (degree[i] < 2)
			{
				for (int j = i+1; j < n; ++j)
				{
					if (degree[j] < 2 && !edges.count({i, j}))
					{
						available.emplace_back(i, j);
					}
				}
			}
		}

		res.clear();
		if (doit(degree, available, available.begin()))
		{
			reverse(res.begin(), res.end());
			return res;
		}

		return vector<int>{-1};
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
		cout << "Testing MakingRegularGraph (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1527955686;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MakingRegularGraph _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 6;
				int x[] = {0,2};
				int y[] = {2,3};
				int __expected[] = {0, 1, 1, 4, 3, 5, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 4;
				int x[] = {1,2,1};
				int y[] = {2,3,3};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 3;
				int x[] = {};
				int y[] = {};
				int __expected[] = {0, 1, 0, 2, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 5;
				int x[] = {0};
				int y[] = {4};
				int __expected[] = {0, 1, 1, 2, 2, 3, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 5;
				int x[] = {2};
				int y[] = {3};
				int __expected[] = {0, 1, 0, 2, 1, 4, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 1000;
				int x[] = {};
				int y[] = {};
				int __expected[] = {-1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 6:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int x[] = ;
				int y[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.addEdges(n, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
