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

string grid[32];

int bitcnt[32];

int dx[] = {-1, +1,  0,  0};
int dy[] = { 0,  0, -1, +1};

int door[32][32];

int moves[1<<25];
int seen[1<<25], seen_now;

int N, M;

inline bool might_go(int x, int y, int closed) {
    if ((x < 0) || (x >= N) || (y < 0) || (y >= M)) return false;
    if (grid[x][y] == '*') return false;
    if ((grid[x][y] == '#') && (closed & door[x][y])) return false;
    return true;
}

class sortbymoves {
public:
    bool operator() (const int& lhs, const int&rhs) const {
        if (bitcnt[lhs&31] != bitcnt[rhs&31]) return bitcnt[lhs&31] > bitcnt[rhs&31];
        if (moves[lhs] != moves[rhs]) return moves[lhs] < moves[rhs];
        return lhs < rhs;
    }
};


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    for (int i = 0; i < 32; ++i) bitcnt[i] = __builtin_popcount(i);
    
    while (cin >> N >> M) {
        seen_now++;
        for (int i = 0; i < N; ++i) cin >> grid[i];
        
        int ndoors = 0;
        int xi, yi, xci, yci, xcf, ycf, closed = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == '#') { door[i][j] = (1<<ndoors); closed |= door[i][j]; ndoors++; }
                else if (grid[i][j] == 'j') xi = i, yi = j;
                else if (grid[i][j] == 'b') xci = i, yci = j;
                else if (grid[i][j] == 'x') xcf = i, ycf = j;
            }
        }
        
        bool found = false;
        
        set<int, sortbymoves> q;
        
        int state = (xi<<20) | (yi<<15) | (xci<<10) | (yci<<5) | closed;
            
        q.insert(state);
        moves[state] = 0;
        seen[state] = seen_now;
        
        int cur_moves;
        
            
            while (!q.empty()) {
                state = *q.begin(); q.erase(state);
                cur_moves = moves[state];
                closed = state & 31; state >>= 5;
                yci = state & 31; state >>= 5;
                xci = state & 31; state >>= 5;
                yi = state & 31; state >>= 5;
                xi = state & 31;
                
                if ((xci == xcf) && (yci == ycf)) {
                    cout << (ndoors-bitcnt[closed]) << " " << cur_moves << "\n";
                    found = true;
                    goto theend;
                }
                
                for (int dir = 0; dir < 4; ++dir) {
                    int nxi = xi + dx[dir];
                    int nyi = yi + dy[dir];
                    
                    state = -1;
                    
                    if ((nxi == xci) && (nyi == yci)) {
                        int nxci = xci+dx[dir]; 
                        int nyci = yci+dy[dir];
                        if (might_go(nxci, nyci, closed)) {
                            state = (nxi<<20) | (nyi<<15) | (nxci<<10) | (nyci<<5) | closed;
                            if (seen[state] != seen_now) {
                                moves[state] = 2e9;
                                seen[state] = seen_now;
                            }
                        }
                    } else {
                        if (might_go(nxi, nyi, closed)) {
                            state = (nxi<<20) | (nyi<<15) | (xci<<10) | (yci<<5) | closed;
                            if (seen[state] != seen_now) {
                                moves[state] = 2e9;
                                seen[state] = seen_now;
                            }
                        } else if (might_go(nxi, nyi, 0)) {
                            state = (nxi<<20) | (nyi<<15) | (xci<<10) | (yci<<5) | (closed ^ door[nxi][nyi]);
                            if (seen[state] != seen_now) {
                                moves[state] = 2e9;
                                seen[state] = seen_now;
                            }
                        }
                    }
                    
                    if (state != -1) {
                        if ((cur_moves+1) < moves[state]) {
                            q.erase(state);
                            moves[state] = cur_moves+1;
                            q.insert(state);
                        }
                    }
                }
                
            }
            
    theend:    
        if (!found) cout << "-1\n";
    }

	return 0;
}

















