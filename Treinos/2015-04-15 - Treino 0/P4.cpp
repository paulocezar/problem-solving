#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    cout << fixed << setprecision(1);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N, M;
        string s;

        cin >> N >> M;
        cin >> s;
        
        int64 res = 0LL; 
        int64 acm = 0LL;
        int64 sum = 0LL;
        
        int64 h = 1e6 + 1;
        
        queue<int64> q;
        deque<int64> dq;
        
        for (int i = 0; i < M; ++i) {
            if (s[i] == '\\') { acm++, h--; }
            
            sum += h;
            q.push(h);
        
            while (!dq.empty() && (dq.back() > h)) { dq.pop_back(); }
            dq.push_back(h);
            
            if (s[i] == '/') { acm++, h++; }
        }
        
        res = acm + 2LL * (sum - int64(M) * dq.front());

        for (int i = M; i < N; ++i) {
            if (s[i-M] != '_') acm--;
            if (dq.front() == q.front()) { dq.pop_front(); }
            sum -= q.front(); q.pop();
            
            if (s[i] == '\\') { acm++, h--; }
            
            sum += h;
            q.push(h);
            
            while (!dq.empty() && (dq.back() > h)) { dq.pop_back(); }
            dq.push_back(h);
            
            if (s[i] == '/') { acm++, h++; }
            res = min(res, acm + 2LL * (sum - int64(M) * dq.front()));        
        }
        cout << "Case #" << tc << ": " << (0.5 * res) << "\n";
        
    }
    

	return 0;
}

















