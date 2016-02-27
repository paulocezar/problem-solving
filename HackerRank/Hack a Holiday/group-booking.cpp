#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int B[100000];
pair<int, int> PC[1000000];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int G, R;
    cin >> G >> R;
    for (int i = 0; i < G; ++i) cin >> B[i];
    for (int i = 0; i < R; ++i) cin >> PC[i].first >> PC[i].second;
    sort(B, B+G);
    sort(PC, PC+R);

    int j = 0;
    priority_queue<int> Cs;

    int ans = 0;
    for (int i = 0; i < G; ++i) {
        ans++;
        while ((j < R) && (PC[j].first <= B[i])) { Cs.push(PC[j].second); j++; }
        i += Cs.top() - 1; Cs.pop();
    }
    cout << ans << "\n";

	return 0;
}
