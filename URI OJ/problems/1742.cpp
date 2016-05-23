#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int mod = 1e9 + 7;

int db[] = { 1, 2, 4, 8};
int dx[] = {-1, 0,+1, 0};
int dy[] = { 0,-1, 0,+1};

int gr[1024][1024];
int ans[1024][1024];
int dist[1024][1024];
int last_seen[1024][1024], seen_now;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);

    int N, M, H;
    int xi, yi, xf, yf, nx, ny, aa, dd, blocked;

    while (cin >> N >> M >> H) {
        for (int x = 0; x <= N; ++x) {
            for (int y = 0; y <= M; ++y) {
                gr[x][y] = 0;
            }
            gr[x][0] |= 2;
            gr[x][M] |= 8;
        }

        for (int y = 0; y <= M; ++y) {
            gr[0][y] |= 1;
            gr[N][y] |= 4;
        }

        while (H--) {
            cin >> xi >> yi >> xf >> yf;
            for (int y = yi+1; y < yf; ++y) {
                gr[xi][y] |= 4;
                gr[xf][y] |= 1;
            }
            for (int x = xi+1; x < xf; ++x) {
                gr[x][yi] |= 8;
                gr[x][yf] |= 2;
            }
        }
        
        cin >> H;
        while (H--) {
            cin >> xi >> yi >> xf >> yf;
            seen_now++;
            queue<int> q;
            q.push((xi<<10)|yi);
            ans[xi][yi] = 1;
            dist[xi][yi] = 0;
            last_seen[xi][yi] = seen_now;
            while (!q.empty()) {
                xi = q.front(); q.pop();
                yi = xi & 1023; xi >>= 10;
                if ((xi == xf) && (yi == yf)) break;
                aa = ans[xi][yi];
                dd = dist[xi][yi]+1;
                blocked = gr[xi][yi];
                for (int dir = 0; dir < 4; ++dir) {
                    if (blocked & db[dir]) continue;
                    nx = xi + dx[dir];
                    ny = yi + dy[dir];
                    if (last_seen[nx][ny] != seen_now) {
                        q.push((nx<<10)|ny);
                        last_seen[nx][ny] = seen_now;
                        dist[nx][ny] = dd;
                        ans[nx][ny] = aa;
                    } else if (dd == dist[nx][ny]) {
                        ans[nx][ny] += aa;
                        ans[nx][ny] %= mod;
                    }
                }
            }
            cout << ans[xf][yf] << "\n";
        }
        cout << "\n";
    }


    return 0;
}
