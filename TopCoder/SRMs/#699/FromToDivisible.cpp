#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 gcd(int64 a, int64 b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int64 lcm(int64 a, int64 b) {
	int64 g = gcd(a, b);
	a /= g;
	return a * b;
}

class FromToDivisible {
	public:
	int shortest(int N, int S, int T, vector <int> a, vector <int> b) {
		queue<int> q;

		int M = a.size();
		int seen[M];

		for (int i = 0; i < M; ++i) {
			seen[i] = -1;
			if (S % a[i]) continue;
			seen[i] = 1;
			q.push(i);
		}

		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int i = 0; i < M; ++i) {
				if (seen[i] != -1) continue;
				int64 cm = lcm(b[u], a[i]);
				if (cm <= int64(N)) {
					seen[i] = seen[u] + 1;
					q.push(i);
				}
			}
		}

		int res = -1;

		for (int i = 0; i < M; ++i) {
			if (seen[i] == -1) continue;
			if (T % b[i]) continue;
			if ((res == -1) || (seen[i] < res)) res = seen[i];
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
		cout << "Testing FromToDivisible (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1474903333;
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
		FromToDivisible _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 11;
				int S = 9;
				int T = 6;
				int a[] = {3,10};
				int b[] = {5,2};
				_expected = 2;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 123456789;
				int S = 18;
				int T = 12;
				int a[] = {1,42,50};
				int b[] = {1,17,3};
				_expected = 1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 60;
				int S = 30;
				int T = 8;
				int a[] = {16,15,12};
				int b[] = {2,20,5};
				_expected = -1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 77;
				int S = 10;
				int T = 62;
				int a[] = {2,5,7,4,17,26};
				int b[] = {25,7,11,13,31,34};
				_expected = 4;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 100;
				int S = 90;
				int T = 40;
				int a[] = {20,30,100,99,100};
				int b[] = {10,30,100,100,99};
				_expected = 2;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 1000000000;
				int S = 7000;
				int T = 424212345;
				int a[] = {35000000,120000000,424212345,200000000,3500,19};
				int b[] = {15,1,7000,200000000,400000000,17};
				_expected = 3;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 6:
			{
				int N = 2;
				int S = 1;
				int T = 2;
				int a[] = {2};
				int b[] = {1};
				_expected = -1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 7:
			{
				int N = 15;
				int S = 5;
				int T = 14;
				int a[] = {5};
				int b[] = {7};
				_expected = -1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 8:
			{
				int N = ;
				int S = ;
				int T = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int N = ;
				int S = ;
				int T = ;
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
