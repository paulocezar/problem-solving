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

int main(){
    ios::sync_with_stdio(false);
	string key;
	string msg;
	while (cin >> key && key != "0") {
		cin >> msg;int kk = int(key.size());
		REP(i, int(msg.size())) {
			int old = msg[i]-'A';
			int chng = key[i%kk]-'A'+1;
			old = (old + chng)%26;
			cout << char(old+'A');
		}
		cout<< "\n";
	}
    return 0;
}
