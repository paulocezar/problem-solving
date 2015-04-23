#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> solve(vector<int> &opr, vector<char> &op, int player) {
    
    if (op.size() == 1) {
        pair<int,int> ret = make_pair(0,0);
        switch (op[0]) {
            case '+': ret.second = opr[0] + opr[1]; break; 
            case '-': ret.second = opr[0] - opr[1]; break;
            case '*': ret.second = opr[0] * opr[1]; break;
        }
        return ret;
    }
    
    int res, mv = -1;
    
    
    
    for (int i = 0; i < int(op.size()); ++i) {
        
        vector<int> nopr = opr;
        vector<char> nop = op;
        
        switch (op[i]) {
            case '+': nopr[i] += nopr[i+1]; break; 
            case '-': nopr[i] -= nopr[i+1]; break;
            case '*': nopr[i] *= nopr[i+1]; break;
        }
        
        nopr.erase(nopr.begin()+i+1);
        nop.erase(nop.begin()+i);
        
        int cur = solve(nopr, nop, 1-player).second;
        if (player) {
            if (mv == -1 || cur < res) res = cur, mv = i;
        } else {
            if (mv == -1 || cur > res) res = cur, mv = i;
        }
    }
    
    return make_pair(mv, res);
}

int main() {
    ios::sync_with_stdio(false);
    
    int tc;
    cin >> tc;
    for (int kase = 1; kase <= tc; ++kase) {
        int nop; cin >> nop;
        vector<int> opr(nop+1);
        vector<char> op(nop);
        cin >> opr[0];        
        for (int i = 0; i < nop; ++i) {
            cin >> op[i];
            cin >> opr[i+1];
        }
        pair<int,int> onef = solve(opr,op,0);
        pair<int,int> twof = solve(opr,op,1);
        
        cout << "Case " << kase << ":\n";
        cout << "Player 1 (" << opr[onef.first] << op[onef.first] << opr[onef.first+1] 
            << ") leads to " << onef.second << "\n";
        
        cout << "Player 2 (" << opr[twof.first] << op[twof.first] << opr[twof.first+1] 
            << ") leads to " << twof.second << "\n";
        
        if (onef.second > -twof.second) cout << "Player 1 wins\n";
        else if (onef.second < -twof.second) cout << "Player 2 wins\n";
        else cout << "Tie\n";
    }
    
    return 0;
}
