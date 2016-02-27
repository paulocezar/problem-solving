#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int get_dist(vector<int> &p) {
    int dist = 2e9;
    int len = int(p.size()) - 1;
    for (int i = 0; i < len; ++i) dist = min(dist, abs(p[i]-p[i+1]));
    return dist;    
}

int main(int argc, char* argv[]) {
    
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    vector<int> p;

    while (t--) {
        int n; int64 k;
        cin >> n >> k;

        if (n&1) {

            if (n == 1) {
                if (k == 1) cout << "1\n";
                else cout << "-1\n";
                continue;
            }

            p.resize(n);
            int maximal = n/2;
            int64 cur = 0;
            p[0] = 1;
            int i = maximal+1;
            int j = n;
            int pos = 1;
            for (int x = 0; x < maximal; ++x) {
                p[pos++] = i--;
                p[pos++] = j--;
            }

            if ((n < 12) || (k < 512)) {
                do {
                    int dist = get_dist(p);
                    if (dist == maximal) {
                        cur++;
                        if (cur == k) break;
                    }
                } while (next_permutation(p.begin(), p.end()));
            } else if (k < 16384){
                vector<int> pp = p;
                int MAX_TRIES = 1<<8;
                while (MAX_TRIES--) {
                    random_shuffle(p.begin(), p.end());
                    int dist = get_dist(p);
                    if (dist == maximal) pp = max(pp, p);
                }

                p = pp;
                cur = k;
            }

            if (cur == k) {
                for (int i = 0; i < n; ++i) {
                    if (i) cout << " ";
                    cout << p[i];
                }
                cout << "\n";
            } else cout << "-1\n";

        } else {
            if (k > 2) cout << "-1\n";
            else {
                vector<int> res;
                int i = n/2, j = n;
                while (i) {
                    res.push_back(i);
                    res.push_back(j);
                    --i; --j;
                }
                if (k == 2) reverse(res.begin(), res.end());
                for (int i = 0; i < n; ++i) {
                    if (i) cout << " ";
                    cout << res[i];
                }
                cout << "\n";
            }
        }
    }
    
    return 0;
}
