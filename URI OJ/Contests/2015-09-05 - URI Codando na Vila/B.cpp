#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1000000
int forbid[MAXN+1], seen[MAXN+1], dist[MAXN+1], cur;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    

    int O, D, K, x;
    while (cin >> O >> D >> K && (O || D || K)) {
    	cur++;        
    	for (int i = 0; i < K; ++i) {
    		cin >> x;
            if ((x > MAXN) || (x <= 0)) continue;
    		forbid[x] = cur;
    	}

        dist[O] = 0;
    	seen[O] = cur;
    	queue<int> q;
        q.push(O);
    	while (!q.empty()) {
    		O = q.front(); q.pop();
    		if (O == D) break;
    		for (int i = 0; i < 5; ++i) {	
                switch(i) {
                    case 0: x = O + 1; break;
                    case 1: x = O - 1; break;
                    case 2: x = 2 * O; break;
                    case 3: x = 3 * O; break;
                    case 4: x = ((O & 1) ? (-1) : (O/2));  break;
                }

    			if ((x <= 0) || (x > MAXN)) continue;
                if (seen[x] == cur || forbid[x] == cur) continue;

    			seen[x] = cur;
    			dist[x] = dist[O] + 1;
    			q.push(x);    			
     		}
    	}
    	if (seen[D] != cur) dist[D] = -1;
    	cout << dist[D] << "\n";
    }

	return 0;
}

















