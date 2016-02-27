#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int M;
    cin >> M;

    int cur;
    unordered_set<int> seen;
    stack<int> stk;
    bool ok = true;

    while (M--) {
        cin >> cur;
        if (!stk.empty() && cur < stk.top()) {
            ok = false;
            break;
        }
        if (!seen.insert(cur).second) {
            ok = false; break;
        }
        if (!stk.empty() && (stk.top() == cur)) {
            stk.pop();
        }
        cur--;
        if (cur <= 0) continue;
        if (!seen.count(cur)) {
            if (!stk.empty() && stk.top() > cur) {
                ok = false; break;
            }
            if (stk.empty() || (stk.top() != cur)) {
                stk.push(cur);
            }
        }
    }
    
    cout << (ok ? "YES\n" : "NO\n");

	return 0;
}
