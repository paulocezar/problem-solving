#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string tos(int x) {
    ostringstream ot;
    ot << x;
    return ot.str();
}

void print(int from, int to) {
    if (from == to) cout << "0" << from << "\n";
    else {
        string a = tos(from);
        string b = tos(to);
        cout << "0" << from << "-";
        int i = 0;
        while  (a[i] == b[i]) ++i;
        while (i < int(b.size())) {
            cout << b[i]; ++i;
        }
        cout << "\n";
    }
} 

int main() {
    ios::sync_with_stdio(false);

    int tc = 1;
    int n;
    while (cin >> n && n) {
        
        int last, first, num;
        
        cout << "Case " << tc++ << ":\n";

        cin >> first;
        last = first;
        for(int i = 0; i < n-1; ++i) {
            cin >> num;
            if (num != last+1)  {
                print(first,last);
                first = num;
                last = num;
            } else last = num;
        }
        print(first,last);
        cout << "\n";
    }
    
    return 0;
}
