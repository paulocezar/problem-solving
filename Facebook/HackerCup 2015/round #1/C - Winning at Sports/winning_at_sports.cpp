#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod = 1000000007LL;

int64 cache[1<<11][1<<11];
int last_cached[1<<11][1<<11], cached_now;

int scoreA, scoreB;

bool stress_free;

int64 count(int pa, int pb) {
    if ((pa == scoreA) || (pb == scoreB)) return 1LL;
    
    int64 &ret = cache[pa][pb];
    if (last_cached[pa][pb] == cached_now) return ret;
    last_cached[pa][pb] = cached_now;
    ret = 0;
    
    if (stress_free) {
        ret = count(pa+1, pb);
        if ((pb+1) < pa) ret += count(pa, pb+1);
        if (ret >= mod) ret -= mod;
    } else {
        ret = count(pa, pb+1);
        if ((pa+1) <= pb) ret += count(pa+1, pb);
        if (ret >= mod) ret -= mod;
    }
    return ret;
}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        string line; cin >> line;
        for (size_t i = 0; i < line.size(); ++i) if (line[i] == '-') line[i] = ' ';
        istringstream in(line);
        in >> scoreA >> scoreB;
        cached_now++; stress_free = true;
        int64 sfree = count(1, 0);
        cached_now++; stress_free = false;
        int64 sfull = count(0, 0);
        cout << "Case #" << tc << ": " << sfree << " " << sfull << "\n";
    }
    

	return 0;
}

















