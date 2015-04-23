#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <random>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int A[2048], AA[2048], p[2048], p2[2048], N, k, S;

bool comp(int x, int y) {
    return (A[x] > A[y]);
}

bool comp2(int x, int y) {
    return (A[x] < A[y]);
}


int64 eval(int* idx) {

        for (int i = 1; i <= N; ++i) AA[i] = A[idx[i-1]];
    int64 res = 0LL;
    
    int i = 1;
    int j = 1;
    int64 acm = 0;
    
    while (i <= k) {
    
        while ((j <= N) && (acm+AA[j]) <= S) {
            acm += AA[j];
            j++;
        }
        
        res += S - acm;
        
        if (i < j) acm -= AA[i];
        i++;
    }    
    
    
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> k >> S;
        for (int i = 0; i < N; ++i) { cin >> A[i]; p[i] = i; }
        
        sort(p, p+N, comp);
        int64 cbest = eval(p);

        for (int i = 0; i < N; ++i) p2[i] = p[i];
        sort(p2, p2+N, comp2);
        int64 scndtry = eval(p2);
        if (scndtry <= cbest) {
            cbest = scndtry;
            for (int i = 0; i < N; ++i) p[i] = p2[i];
        }
        
        for (int i = 0; i < N; ++i) p2[i] = p[i];        
        
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(p2, p2+N, default_random_engine(seed));
        
        for (int step = 0; step < 2048; ++step) {
            int64 ep2 = eval(p2);
            if (ep2 < cbest) {
                cbest = ep2;
                for (int i = 0; i < N; ++i) p[i] = p2[i];
            }
            seed = chrono::system_clock::now().time_since_epoch().count();
            
            default_random_engine eng(seed);
            uniform_int_distribution<int> unif(0, N-1);
            uniform_int_distribution<int> unif2(0, k-1);
            
            if (2*unif(eng) < N) {
                
                for (int i = 0; i < N; ++i) p2[i] = p[i];
                int i1 = unif2(eng) + unif(eng);
                int i2 = unif2(eng) + unif(eng);
                if (i2 < i1) swap(i2,i1);
                i1 = min(i1, N-1);
                i2 = min(i2, N-1);
                shuffle(p2+i1, p2+i2+1, default_random_engine(seed));                
            
            } else shuffle(p2, p2+N, default_random_engine(seed));
            
            if (3*unif(eng) < N) {
                int i1 = unif2(eng) + unif(eng);
                int i2 = unif2(eng) + unif(eng);
                if (i2 < i1) swap(i2,i1);
                i1 = min(i1, N-1);
                i2 = min(i2, N-1);   
                sort(p2+i1, p2+i2, comp2);
            }
            
        }
        
        for (int i = 0; i < N; ++i) {
            if (i) cout << " ";
            cout << (p[i]+1);
        }
        cout << "\n";
    }

	return 0;
}

















