#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MSZ 1001000

int stk[MSZ];
int front, back, ssz;

inline int popback() {
    ssz--;
    back--;
    if (back == -1) back = MSZ-1;
    return stk[back];
}

inline void pushback(int x) {
    ssz++;
    stk[back] = x;
    back++;
    if (back == MSZ) back = 0;
}

inline void pushfront(int x) {
    ssz++;
    front--;
    if (front == -1) front = MSZ-1;
    stk[front] = x;
}

inline void popfront() {
    ssz--;
    ++front;
    if (front == MSZ) front = 0;
}

inline int next_int() {
    int res = 0;
    char sig = '+';
    char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') sig = '-', c = getchar();
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar();
    }
    if (sig == '-') return -res;
    return res;
}

int main() {
    
    int n = next_int();
    
    ssz = 0, front = 0, back = 0;
    for (int i = 0; i < n; ++i) {
        
        int x = next_int();
        
        if (x == 0) {
            
            int add = min(ssz, max(0, n-ssz));
            int pos = back-1;

            while (add--) {
                if (pos == -1) pos = MSZ-1;
                pushfront(stk[pos]);
                pos--;
            }
            
        } else if (x == -1) {
            printf("%d\n", popback());
        } else {
            pushback(x);
            if (ssz > n) popfront();
        }
    } 
    
    return 0;
}
 