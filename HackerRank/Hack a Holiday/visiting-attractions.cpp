#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;
typedef std::pair<double, double> coord_t;

using namespace std;

inline double dist(coord_t &a, coord_t &b) {
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

coord_t att[16], stt[128];

double stt_dist[128][128];
double att_dist[16][16];

int N;

char cached[16][16][1<<10];
double cache[16][16][1<<10];

const double EPS = 1e-9;
inline int SGN(double a) {
    return ((a > EPS)?(1):((a < -EPS)?(-1):(0)));
}

inline int CMP(double a, double b) {
    return SGN(a - b);
}

double solve(int at, int need, int vis) {

    if (!need) return 0.0;
    double &res = cache[at][need][vis];
    if (cached[at][need][vis]) return res;
    cache[at][need][vis] = 1;
    res = 2e9;
    for (int i = 0; i < N; ++i) {
        if (vis & (1<<i)) continue;
        double cur = att_dist[at][i+1] + 1.0 + solve(i+1, need-1, vis | (1<<i));
        if (CMP(cur, res) < 0) res = cur;
    }
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    cout << fixed << setprecision(6);

    cin >> att[0].first >> att[0].second;

    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> att[i].first >> att[i].second;
    
    int S;
    cin >> S;
    for (int i = 1; i <= S; ++i) cin >> stt[i].first >> stt[i].second;

    for (int i = 1; i <= S; ++i) {
        stt_dist[i][i] = 0.0;
        for (int j = i+1; j <= S; ++j) {
            double dst = dist(stt[i], stt[j]);
            stt_dist[i][j] = stt_dist[j][i] = dst / 5.0;
        }
    }

    int L;
    cin >> L; cin.ignore();
    for (int i = 0; i < L; ++i) {
        string line;
        getline(cin, line);
        int cur;
        istringstream in(line);
        vector<int> ids;
        while (in >> cur){
            for (auto prv: ids) {
                double dst = dist(stt[prv], stt[cur]) / 25.0;    
                if (CMP(stt_dist[prv][cur], dst) < 0) dst = stt_dist[prv][cur];
                stt_dist[prv][cur] = stt_dist[cur][prv] = dst;
            }
            ids.push_back(cur);
        }
    }

    for (int k = 1; k <= S; ++k) {
        for (int i = 1; i <= S; ++i) {
            for (int j = 1; j <= S; ++j) {
                double nval = stt_dist[i][k]+stt_dist[k][j];
                if (CMP(nval, stt_dist[i][j]) < 0) stt_dist[i][j] = nval;
            }
        }
    }

    for (int i = 0; i <= N; ++i) {
        att_dist[i][i] = 0.0;
        for (int j = i+1; j <= N; ++j) {
            double dst = dist(att[i], att[j]) / 5.0;

            for (int k = 1; k <= S; ++k) {
                for (int l = 1; l <= S; ++l) {
                    double dst_2 = ((dist(att[i], stt[k])+ dist(stt[l], att[j])) / 5.0) + stt_dist[k][l];
                    if (CMP(dst_2, dst) < 0) dst = dst_2;
                }
            }

            att_dist[i][j] = att_dist[j][i] = dst;
        }
    }

    memset(cached, 0, sizeof(cached));

    int lo = 0, hi = N; 
    while (lo <= hi) {
        int mid = (lo+hi) >> 1;
        
        double ttl = solve(0, mid, 0);
        if (CMP(ttl, 13.0) <= 0) {
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }

    cout << hi;
    int at = 0, vis = 0;
    double spent = 0.0;
    for (int pos = 0; pos < hi; ++pos) {
        if (pos) cout << " ";
        else cout << "\n";

        for (int i = 0; i < N; ++i) {
            if (vis & (1<<i)) continue;
            double cst = att_dist[at][i+1] + 1.0;
            double nxt = spent + cst + solve(i+1, hi-pos-1, vis | (1<<i));
            if (CMP(nxt, 13.0) <= 0) {
                at = i+1;
                cout << at;
                vis |= (1<<i);
                spent += cst;
                break;
            }
        }
    }
    cout << "\n";

	return 0;
}
