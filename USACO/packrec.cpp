/*
ID: knightp2
PROG: packrec
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
    
using namespace std;

const int NREC = 4;

int ord[NREC];
int side[NREC][2];

int ans;
set< pair<int,int> > ans_sides;

void check(int x, int y) {
    if (x * y < ans) {
        ans = x*y;
        ans_sides.clear();
        ans_sides.insert(make_pair(min(x,y),max(x,y)));
    } else if (x * y == ans) {
        ans_sides.insert(make_pair(min(x,y),max(x,y)));
    }
}

void try_layouts(int oriented) {

    int x[NREC];
    int y[NREC];
    
    for (int i = 0; i < NREC; ++i) {
        if (oriented & (1<<i)) x[i] = side[ord[i]][0], y[i] = side[ord[i]][1];
        else x[i] = side[ord[i]][1], y[i] = side[ord[i]][0];
    }
    
// layout 1
    int xx = 0, yy = 0;
    for (int i = 0; i < NREC; ++i) {
        xx += x[i]; yy = max(yy,y[i]);    
    }
    check(xx,yy);
// layout 2
    xx = max(x[0]+x[1]+x[2],x[3]);
    yy = max(y[0],max(y[1],y[2])) + y[3];
    check(xx,yy);
// layout 3
    xx = max(x[0]+x[1]+x[2],x[2]+x[3]);
    yy = max(y[2],y[3]+max(y[0],y[1]));
    check(xx,yy);
// layout 4~5
    xx = x[1]+x[2]+x[3];
    yy = y[0]+min(((x[1] >= x[0])?y[1]:400),
              min(((x[2] >= x[0])?y[2]:400),
                  ((x[3] >= x[0])?y[3]:400)));
    yy = max(yy,max(y[1],max(y[2],y[3])));
    check(xx,yy);
// layout 6
    xx = x[2]+x[3];
    yy = max(y[2]+y[0],y[3]+y[1]);
    if (x[0]+x[1] <= xx) {
        if (y[2] < y[3] && x[0] > x[2]) return;
        if (y[2] > y[3] && x[1] > x[3]) return;
        check(xx,yy);
    }           
}

int main() {
    ifstream fin("packrec.in");
    ofstream fout("packrec.out");
    
    for (int i = 0; i < NREC; ++i) 
        for (int j = 0; j < 2; ++j)
            fin >> side[i][j];

    for (int i = 0; i < NREC; ++i)
        ord[i] = i;

    ans = 2e9;
    ans_sides.clear();

    do {
        
        for (int mask = 0; mask < (1<<NREC); ++mask)
            try_layouts(mask);
        
    } while (next_permutation(ord,ord+4));

    fout << ans << "\n";
    set< pair<int,int> >::iterator it = ans_sides.begin();
    while (it != ans_sides.end()) {
        fout << it->first << " " << it->second << "\n";
        ++it;
    }

    
    return 0;
}
