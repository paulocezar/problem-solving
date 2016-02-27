#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int last_done[256][256][256], done_now;
bool can_do[256][256][256];
char obj;

bool do_it(int R, int G, int B) {
    if ((R+G+B) == 1) {
        switch(obj) {
            case 'R': return (R == 1);
            case 'G': return (G == 1);
            case 'B': return (B == 1);
        }
    }

    bool &res = can_do[R][G][B];
    if (last_done[R][G][B] == done_now) return res;
    last_done[R][G][B] = done_now;
    res = false;
    if (!res && R && G) res = res || do_it(R-1, G-1, B+1);
    if (!res && R && B) res = res || do_it(R-1, G+1, B-1);
    if (!res && G && B) res = res || do_it(R+1, G-1, B-1);
    if (!res && R >= 2) res = res || do_it(R-1, G, B);
    if (!res && G >= 2) res = res || do_it(R, G-1, B);
    if (!res && B >= 2) res = res || do_it(R, G, B-1);
    return res;
}

int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int R = 0, G = 0, B = 0;
    for (int i = 0; i < n; ++i) {
        switch(s[i]) {
            case 'R': R++; break;
            case 'G': G++; break;
            case 'B': B++; break;
        }
    }

    for (char cur : "BGR") {
        done_now++;
        obj = cur;
        if (do_it(R, G, B)) cout << cur;   
    }
    cout << "\n";

    return 0;
}
