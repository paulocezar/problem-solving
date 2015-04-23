#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>

using namespace std;

int h, w;

int conn[20*20+1][8];
int seen[20*20+1][8], seen_now;

int ops(int x) {
    switch(x) {
        case 0: return 5;
        case 5: return 0;
        
        case 1: return 4;
        case 4: return 1;
        
        case 2: return 7;
        case 7: return 2;
        
        case 3: return 6;
        case 6: return 3;
    }
    return -1;
}

int opi(int x) {
    switch(x) {
        case 0: return -w;
        case 5: return +w;
        
        case 1: return -w;
        case 4: return +w;
        
        case 2: return +1;
        case 7: return -1;
        
        case 3: return +1;
        case 6: return -1;
    }
    return 0;
}

int getend(int i, int at) {
    
    seen[i][at] = seen_now;
    if (conn[i][at] == 10) return 10*i + at;
    
    if (seen[i][ conn[i][at] ] == seen_now) {
        
        int chng = opi(at);
        int ni = i + chng;
        
        if (((i % w) == 0) && (chng == +1)) return 10*i + at;
        if (((i % w) == 1) && (chng == -1)) return 10*i + at;
        
        if (ni < 1 || ni > h*w) return 10*i + at;
        return getend(ni,ops(at));
                
    }
    
    return getend(i, conn[i][at]);    
}

string numtos(int x) {
    int side = x%10;
    int val = x/10;
    ostringstream ot;
    ot << val << char(side+'A');
    return ot.str();
}

int stonum(string x) {
    int val = 0;
    for (int i = 0; i < int(x.size())-1; ++i) {
        val = 10*val + (x[i]-'0');
    }
    return 10*val + (x[int(x.size())-1]-'A');
}

int main() {
    ios::sync_with_stdio(false);
    
    int board = 1;
    while (cin >> h >> w && (h || w)) {
        
        for (int i = 1; i <= h*w; ++i) {
            for (int j = 0; j < 8; ++j) {
                conn[i][j] = 10;
            }
        }
        
        cin.ignore();
        string line;
        while (getline(cin,line)) {
            istringstream in(line);
            int id;
            in >> id;
            if (!id) break;
            string cn;
            while (in >> cn) {
                conn[id][ cn[0]-'A' ] = cn[1]-'A';
                conn[id][ cn[1]-'A' ] = cn[0]-'A';
            }
        }
        getline(cin,line);
        
        cout << "Board " << board++ << ":\n";
        istringstream in(line);
        string strt;
        while (in >> strt) {
            int istrt = stonum(strt);
            seen_now++;
            cout << strt << " is connected to " << numtos(getend(istrt/10,istrt%10)) << "\n";
        }
        
        cout << "\n";
        
    }
    
    return 0;
}