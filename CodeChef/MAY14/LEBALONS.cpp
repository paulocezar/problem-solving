#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int N, M, cur_out;

pair<int,int> balloon[64];

int64 memo[64][64][64];
int last_seen[64][64][64], seen_now;

int64 solve(int pos, int last, int cnt) {
    if (pos == N) return ((cnt >= M) ? 1LL : 0LL);
    if (pos == cur_out) return solve(pos+1,last,cnt);
    
    int64 &res = memo[pos][last][cnt];
    if (last_seen[pos][last][cnt] == seen_now) return res;
    last_seen[pos][last][cnt] = seen_now;
    res = solve(pos+1,last,cnt);
    res += solve(pos+1,balloon[pos].first, cnt + ((balloon[pos].first != last) ? 1 : 0));
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    cout << fixed << setprecision(13);
    
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;   
        for (int i = 0; i < N; ++i) cin >> balloon[i].first >> balloon[i].second;
        sort(balloon,balloon+N); 
        seen_now++;
        cur_out = -1;
        int64 total = solve(0,0,0);
        double res = 0.0;
        for (cur_out = 0; cur_out < N; ++cur_out) {
            seen_now++;
            int64 without = solve(0,0,0);
            int64 with = total - without;
            res += double(with*int64(balloon[cur_out].second))/double(total);
        }    
        cout << res << "\n";
    }
    

	return 0;
}

















