#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

class FleetFunding {
public:
    int maxShips( int m, vector <int> k, vector <int> a, vector <int> b ) {
        int lo = 0, hi = 0, n = int(k.size());
     	for (auto &v: k) hi += v;

     	int used[n];
     	map<int, vector<int>> start;
        for (int i = 0; i < n; ++i) start[a[i]].push_back(i);

        auto comp = [&b](int x, int y) { return b[x] > b[y]; };

       	while (lo <= hi) {
       		int mid = (lo+hi) >> 1;

       		memset(used, 0, sizeof(used));
       		priority_queue<int, vector<int>, decltype(comp)> q(comp);

       		bool ok = true;
       		for (int i = 1; i <= m; ++i) {
       			if (start.count(i)) {
       				for (auto &val : start[i]) q.push(val);
       			}

       			int needs = mid;
       			while (needs && !q.empty()) {
       				int cur = q.top();

       				int build_at = min(needs, k[cur]-used[cur]);
       				used[cur] += build_at;
       				needs -= build_at;
       				if (used[cur] == k[cur]) q.pop();
       			}

       			if (needs) { ok = false; break; }

       			while (!q.empty() && (b[q.top()] == i)) {
       				q.pop();
       			}
       		}

       		if (ok) {
       			lo = mid+1;
       		} else {
       			hi = mid-1;
       		}
       	}
       	return hi;
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
		cout << "Testing FleetFunding (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454778007;
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
		FleetFunding _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int m = 3;
				int k[] = {2,2,2};
				int a[] = {1,2,1};
				int b[] = {3,3,2};
				_expected = 2;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int m = 1;
				int k[] = {10,9,8,7,6,5,4,3,2,1};
				int a[] = {1,1,1,1,1,1,1,1,1,1};
				int b[] = {1,1,1,1,1,1,1,1,1,1};
				_expected = 55;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int m = 10;
				int k[] = {2,4,6,8,10,1,3,5,7,9};
				int a[] = {1,2,3,4,5,6,7,8,9,10};
				int b[] = {1,2,3,4,5,6,7,8,9,10};
				_expected = 1;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int m = 84457;
				int k[] = {374778,169109,529984,498638,29462,465769,29285,394948,307944,459189,
				          349316,766627,686851,404285,850199,359378,3014,248257,558856,27393,32370,
				          574862,337134,965567,32223,935678,389898,973497,990575,483190,122899,
				          857994,991217,149619,415870};
				int a[] = {92,4997,11,28545,933,210,2,124,114,4513,32959,1,57,17,13,133,1843,41851,
				          3,9296,9757,28,3,769,10,11102,683,6173,11821,3982,214,2,4304,439,1998};
				int b[] = {81034,54474,70239,79597,47317,82938,83883,74652,84033,84422,84456,84457,
				          81095,83743,79210,84255,84455,45596,84456,82959,67062,80330,44090,84445,
				          84454,84450,45931,77190,83025,83567,83639,84333,83355,70982,84456};
				_expected = 186;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int m = 2;
				int k[] = {1000000,1000000,1000000,1000000,1000000};
				int a[] = {1,1,1,2,2};
				int b[] = {1,1,2,2,2};
				_expected = 2500000;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 5:
			{
				int m = ;
				int k[] = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int m = ;
				int k[] = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int m = ;
				int k[] = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.maxShips(m, vector <int>(k, k+sizeof(k)/sizeof(int)), vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
