#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    priority_queue<int> qmin, qmax;
    
    int x;
    while (cin >> x) {
        
        qmax.push(x);
        if (qmax.size() > (qmin.size()+1)) {
            qmin.push(-qmax.top()); qmax.pop();
        }
        
        if (!qmin.empty() && (qmax.top() > -qmin.top())) {
            int x = -qmin.top(); qmin.pop();
            qmin.push(-qmax.top()); qmax.pop();
            qmax.push(x);
        }
        
        if (qmax.size() > qmin.size()) cout << qmax.top() << "\n";
        else cout << (qmax.top() - qmin.top()) / 2 << "\n";
        
    }
    
    return 0;
}