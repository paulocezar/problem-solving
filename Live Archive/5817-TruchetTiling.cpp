#include <iostream>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <iomanip>

using namespace std;

string grid[128];

#define MAXN (100 * 100 * 3)

int pa[MAXN], rk[MAXN];
double ar[MAXN];
const double pi = acos(-1.0);

int find(int x) {
    int ax, px = x;
    while (pa[px] != px) px = pa[px];
    while (x != px) {
        ax = pa[x];
        pa[x] = px;
        x = ax;
    }
    return px;
}

void fUnion(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rk[y] > rk[x]) swap(x,y);
    pa[y] = x;
    if (rk[x] == rk[y]) rk[x]++;
    ar[x] += ar[y];
}

int R, C;

inline int getvertex(int i, int j, int tp) {
    return (3 * (i*C + j) + tp);
}

inline int getvertex(int x, int y) {
    int i = x/2;
    int j = y/2;
    
    if (i == R || j == C) {
        if (i == R && j == C) return getvertex(i-1,j-1,(grid[i-1][j-1]=='0')?2:1);
        
        
        if (i == R) {
            char c = grid[i-1][j];
            return getvertex(i-1,j, (y==2*j)?((c=='0')?1:0):((c=='0')?2:1));
        }
        
        char c = grid[i][j-1];
        return getvertex(i,j-1, (x==2*i)?((c=='0')?1:2):((c=='0')?2:1));
        
    }
    
    if (x & 1) return getvertex(i,j,1);
    
    if (grid[i][j] == '0') {
    int tp = 2;    
    int xi = 2*i;
    int yi = 2*j;
    if (xi == x && yi == y) tp = 0;
    else if (xi == x || yi == y) tp = 1;
    return getvertex(i,j,tp);
    }

    int tp = 0;    
    int xi = 2*i;
    int yi = 2*j;
    if ((xi == x && yi == y) || (xi != x && yi != y)) tp = 1;
    else if (xi == x) tp = 2;
    return getvertex(i,j,tp);
}

int main() {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> R >> C;
        for (int i = 0; i < R; ++i) cin >> grid[i];
        
        int N = R*C*3;
        for (int i = 0; i < N; i+=3) {
            for (int tp = 0; tp < 3; ++tp) {
                pa[i+tp] = i+tp;
                rk[i+tp] = 0;
                ar[i+tp] = ((tp&1)?((8.0-pi)*.5):(.25*pi));
            }
        }
        
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                
                if (i+1 < R) { // abaho
                    if (grid[i][j] == '0') {
                        if (grid[i+1][j] == '0') {
                            fUnion(getvertex(i,j,1),getvertex(i+1,j,0));
                            fUnion(getvertex(i,j,2),getvertex(i+1,j,1));
                        } else {
                            fUnion(getvertex(i,j,1),getvertex(i+1,j,1));
                            fUnion(getvertex(i,j,2),getvertex(i+1,j,2));
                        }
                    } else {
                        if (grid[i+1][j] == '0') {
                            fUnion(getvertex(i,j,0),getvertex(i+1,j,0));
                            fUnion(getvertex(i,j,1),getvertex(i+1,j,1));
                        } else {
                            fUnion(getvertex(i,j,1),getvertex(i+1,j,2));
                            fUnion(getvertex(i,j,0),getvertex(i+1,j,1));
                        }
                    }                    
                }
                
                if (j+1 < C) { // deretcha
                    if (grid[i][j] == grid[i][j+1]) {
                        fUnion(getvertex(i,j,2),getvertex(i,j+1,1));
                        fUnion(getvertex(i,j,1),getvertex(i,j+1,0));
                    } else {
                        fUnion(getvertex(i,j,1),getvertex(i,j+1,1));
                        fUnion(getvertex(i,j,2),getvertex(i,j+1,0));    
                    }
                }                
            }
        }
        
        int q;
        cin >> q;
        cout << "Case " << tc << ":\n";
        while (q--) {
            int x, y;
            cin >> x >> y;
            
            if ((x+y)&1) cout << "0.0000\n";
            else {
                //cout << getvertex(x,y) << endl;
                cout << fixed << setprecision(4) << ar[ find( getvertex(x,y) ) ] << "\n";
            }
        }
        
        
    }
    
    return 0;
}