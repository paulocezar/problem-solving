#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> tr[128];
char gr[128][128];
int deg[128];
char vis[128];
vector<int> parent;

void build(int u) {
	queue<int> q;
	q.push(u);
	while (!q.empty()) {

		int v = q.front(); q.pop();

		if (u != v) {
			gr[u][v] = 1; deg[u]++;
			gr[v][u] = 1; deg[v]++;
		}

		for (auto &w : tr[v]) {
			if (v && (parent[v-1] == w)) continue;
			q.push(w);
		}
	}
	for (auto &w : tr[u]) {
		if (u && (parent[u-1] == w)) continue;
		build(w);
	}
}

class EllysTree {
public:
    vector <int> getMoves( vector <int> _parent ) {
    	parent = _parent;
    	int N = parent.size();
    	for (int i = 0; i <= N; ++i) { tr[i].clear(); deg[i] = 0; vis[i] = 0; }

    	for (int i = 0; i < N; ++i) {
    		tr[i+1].push_back(parent[i]);
    		tr[parent[i]].push_back(i+1);
    	}
    	memset(gr, 0, sizeof(gr));
    	build(0);

    	int d1 = 0;
    	for (int i = 1; i <= N; ++i) if (deg[i] == 1) d1++;
    	vector<int> ret;

    	if (d1 < 2) {
    		vis[0] = 1;
    		int prev = 0;

    		for (int i = 0; i < N; ++i) {
    			for (int cur = 1; cur <= N; ++cur) {
    				if (vis[cur]) continue;
    				if ((deg[cur] == 1) && (i < (N-1))) continue;
    				if (!gr[prev][cur]) continue;
    				vis[cur] = 1;
    				ret.push_back(cur);
    				prev = cur;
    				break;
    			}
    		}
    	}

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
		cout << "Testing EllysTree (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459009310;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EllysTree _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {9, 13, 7, 9, 8, 14, 14, 0, 6, 9, 2, 2, 5, 5, 7};
				int __expected[] = {1, 5, 2, 11, 13, 12, 8, 3, 7, 15, 14, 4, 6, 9, 10 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 1:
			{
				int parent[] = {3, 4, 5, 0, 2};
				int __expected[] = {1, 2, 3, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 2:
			{
				int parent[] = {0, 0};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 3:
			{
				int parent[] = {0, 6, 6, 2, 6, 1, 3, 5};
				int __expected[] = {2, 4, 1, 3, 7, 6, 5, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			/*case 4:
			{
				int parent[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int parent[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int parent[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
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
