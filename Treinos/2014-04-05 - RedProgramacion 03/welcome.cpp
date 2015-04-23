#include <set>
#include <string> 
#include <iostream>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int N;
string first[512], last[512];

int getfirsts(int grouped_by) {
    set<char> seen;
    for (int i = 0; i < N; ++i) {
        if (grouped_by & (1<<(last[i][0]-'A'))) continue;
        seen.insert(first[i][0]);
    }
    return seen.size();
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    while (cin >> N && N) {
        
        int lasts = 0;
        for (int i = 0; i < N; ++i) {
            cin >> first[i] >> last[i];
            lasts |= (1<<(last[i][0]-'A'));
        }
        
        int res = getfirsts(0);
        for(int subset = lasts; subset > 0; subset = (subset-1) & lasts) {   
            res = min(res, getfirsts(subset) + __builtin_popcount(subset));
        }
        
        cout << res << "\n";
        
        
    }

	return 0;
}

















