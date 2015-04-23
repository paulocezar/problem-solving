#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>

#define SIZE(x) int((x).size())

using namespace std;

typedef long long int64;

string xpr;
int pos;

struct node_t {
    int k, pa;
    int64 ttm[2];
    
    vector< node_t* > chld;
    
    void calc() {
        if (SIZE(chld) == 0) {
            pa = 1;
            ttm[0] = k;
            ttm[1] = 0;
        } else {
            pa = 0;
            ttm[0] = 0;
            ttm[1] = 0;
    
            for (size_t i = 0, sz = chld.size(); i < sz; ++i) { 
                chld[i]->calc();
    
                if (pa & 1) ttm[0] += (chld[i]->ttm[1]), ttm[1] += (chld[i]->ttm[0]);
                else ttm[0] += (chld[i]->ttm[0]), ttm[1] += (chld[i]->ttm[1]);
        
                pa += chld[i]->pa;
                pa %= 2;
            }
    
            if (pa & 1) {
                int64 t0 = ttm[0] + (k/2)*ttm[1] + ((k-1)/2)*ttm[0];
                int64 t1 = ttm[1] + (k/2)*ttm[0] + ((k-1)/2)*ttm[1];
                ttm[0] = t0, ttm[1] = t1;
            } else {
                ttm[0] = k*ttm[0];
                ttm[1] = k*ttm[1];
            }
            
            pa = (k * pa) % 2;
        }
    }
    
    int64 walk(int64 N, int cur_on) {
        //cout << N << " " << cur_on << endl;
        if (SIZE(chld) == 0) {
            return N;
        } else {
            
            int ppa = 0;
            int64 t0 = 0;
            int64 t1 = 0;
    
            for (size_t i = 0, sz = chld.size(); i < sz; ++i) { 
                    
                if (ppa & 1) t0 += (chld[i]->ttm[!cur_on]), t1 += (chld[i]->ttm[cur_on]);
                else t0 += (chld[i]->ttm[cur_on]), t1 += (chld[i]->ttm[!cur_on]);
        
                ppa += chld[i]->pa;
                ppa %= 2;
            }
            
            int64 res = 0;
            int ncur_on = cur_on;            
            if (ppa & 1) {
                int64 fll = (N-1LL) / (t0 + t1);
                N -= fll*(t0 + t1);
                res += fll * 2LL * (t0 + t1);

                if (N > t0) {
                   N -= t0;
                   res += t0 + t1;
                   ncur_on = !ncur_on;
                }

            } else {
                int64 fll = (N-1LL) / (t0);
                N -= fll*t0;
                res += fll * (t0 + t1);
            }
            
            ppa = 0;
            for (size_t i = 0, sz = chld.size(); i < sz; ++i) { 
                if (N > chld[i]->ttm[ppa?(!ncur_on):ncur_on]) {
                    N -= chld[i]->ttm[ppa?(!ncur_on):ncur_on];
                    res += (chld[i]->ttm[0] + chld[i]->ttm[1]);
                } else {
                    res += chld[i]->walk(N, ppa?(!ncur_on):ncur_on);
                    break;
                }
                ppa += chld[i]->pa;
                ppa %= 2;                
            }
    
            
            return res;
        }
    }    
       
};

node_t* parse() {
    node_t* res = new node_t();
    if (isdigit(xpr[pos])) {
        int val = 0;
        while (pos < SIZE(xpr) && isdigit(xpr[pos])) {
            val = 10*val + (xpr[pos]-'0');
            pos++;
        }
        res->k = val;
        return res;
    } else { // (
        pos++;
        res->chld.push_back(parse());
        while (xpr[pos] == ' ') {
            pos++;
            res->chld.push_back(parse());
        }
        pos++; // )
        pos++; // *
        int val = 0;
        while (pos < SIZE(xpr) && isdigit(xpr[pos])) {
            val = 10*val + (xpr[pos]-'0');
            pos++;
        }
        res->k = val;        
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    
    int64 N;
    while (cin >> N && N) {
        cin.ignore();
        getline(cin,xpr);
        pos = 0;
        
        node_t* root = new node_t();
        while (pos < SIZE(xpr)) {
            root->chld.push_back(parse());
            pos++;
        }
        
        root->k = 1;
        root->calc();
        cout << root->walk(N,0) << "\n";   
    }
    
    return 0;
}