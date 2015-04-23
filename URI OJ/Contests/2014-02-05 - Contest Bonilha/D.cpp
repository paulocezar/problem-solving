#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N;
    while (cin >> N && N) {
        
        string winner, cur;
        int winnin, a, b;
        cin >> winner >> a >> b;
        winnin = a-b;
        for (int i = 1; i < N; ++i) {
            cin >> cur >> a >> b;
            if ((a-b) < winnin) {
                winnin = a-b; winner = cur;
            }
        } 
        cout << winner << "\n";
    }

    return 0;
}

