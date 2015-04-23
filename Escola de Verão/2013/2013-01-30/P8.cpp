#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <cfloat>
#include <sstream>
#include <utility>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <bitset>

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)

#define PB push_back
#define MP make_pair

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3fffffffffll

using namespace std;

string gr[55];
int calc[55][55], calc_now;
string mem[55][55];

inline bool best(string &a, string &b) {
	bool ret = a.size() > b.size();
	ret = ret || ((a.size()==b.size()) && (a < b));
	return ret;
}

string solve(int l, int r) {
	if (l == r) return "";
	
	string &res = mem[l][r];
	if (calc[l][r] == calc_now) return res;
	calc[l][r] = calc_now;
	
	res = "";
	res += gr[l][r];
	for (int ll = l+1; ll <= r; ++ll) {
		for (int rr = r-1; rr >= ll; --rr) {
			if (gr[l][ll] == gr[rr][r]) {
				string cand = gr[l][ll] + solve(ll, rr) + gr[rr][r];
				if (best(cand, res)) res = cand;
			}
		}
	}

	return res;
}


int main(){
    ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		REP(i, N) cin >> gr[i];
		calc_now++;
		string res = solve(0, N-1);
		
		if (res == "") cout << "NO PALINDROMIC PATH\n";
		else cout << res << "\n";
	}
    return 0;
}
