#include <set>
#include <string> 
#include <iostream>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int cur_count[128], eliminated[128], N;
    
bool is_over() {
    int i = 0;
    while (eliminated[i]) i++;
    int val = cur_count[i];
    for (; i < N; ++i) {
        if (eliminated[i]) continue;
        if (cur_count[i] != val) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    while (cin >> N && N) {
        
        cin >> T;
        for (int i = 0; i < N; ++i) {
            eliminated[i] = 0;
            cur_count[i] = 0;
        }

        int player = 0;
        do {
                        
            for (int i = 0; i < T; ++i) {
                while (eliminated[player]) {
                    player++;
                    if (player == N) player = 0;
                }
                
                cur_count[player]++;
                if ((i+1) < T) {
                    player++;
                    if (player == N) player = 0;
                }
            }
            eliminated[player] = 1;
        
        } while (!is_over());
        
        int still = 0, val;
        for (int i = 0; i < N; ++i) {
            if (!eliminated[i]) {
                still++;
                val = cur_count[i];
            }
        }
        cout << still << " " << val << "\n";
    }

	return 0;
}

















