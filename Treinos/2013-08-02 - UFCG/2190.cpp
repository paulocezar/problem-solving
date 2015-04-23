#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        int oh, om, ah, am;
        
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> oh >> om >> ah >> am;
            int cur = ((60*ah + am) - (60*oh + om));
            if (cur > 0) sum += cur;
        }
        cout << (sum/n) << "\n";
    }

    return 0;
}
