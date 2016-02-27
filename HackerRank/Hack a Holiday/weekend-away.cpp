#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<pair<int,int>> gr[1<<17];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) gr[i].clear();
        int A, B, D;
        for (int i = 0; i < M; ++i) {
            cin >> A >> B >> D;
            gr[A].push_back(make_pair(D, B));
            gr[B].push_back(make_pair(D, A));
        }
        int res = 2e9;
        for (int i = 1; i <= N; ++i) {
            sort(gr[i].begin(), gr[i].end());
            int st = 0, ed = 0;
            while ((ed < int(gr[i].size())) && (gr[i][ed].second == gr[i][st].second)) {
                ed++;
            }
            
            if (ed < int(gr[i].size()) && gr[i][ed].second != gr[i][st].second) {
                res = min(res, gr[i][st].first + gr[i][ed].first);
            }
        }
        cout << res << "\n";
    }

	return 0;
}
