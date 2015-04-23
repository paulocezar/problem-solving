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
#include <tr1/unordered_map>
#include <tr1/unordered_set>

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = a.begin(); i != a.end(); i++)

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXSZ 5000500

bool k_cmp(int a1, int b1, int a2, int b2, int a3 = 0, int b3 = 0) {
    return a1 != b1 ? a1 < b1 : (a2 != b2 ? a2 < b2 : a3 < b3);
}

int bucket[MAXSZ+1], tmp[MAXSZ];
template<class T> void k_radix(T keys, int *in, int *out,
                               int off, int n, int k) {
    memset(bucket, 0, sizeof(int) * (k+1));

    for(int j = 0; j < n; j++)
        bucket[keys[in[j]+off]]++;
    for(int j = 0, sum = 0; j <= k; j++)
        sum += bucket[j], bucket[j] = sum - bucket[j];
    for(int j = 0; j < n; j++)
        out[bucket[keys[in[j]+off]]++] = in[j];
}

int m0[MAXSZ/3+1];
vector<int> k_rec(const vector<int>& v, int k) {
    int n = v.size()-3, sz = (n+2)/3, sz2 = sz + n/3;
    if(n < 2) return vector<int>(n);

    vector<int> sub(sz2+3);
    for(int i = 1, j = 0; j < sz2; i += i%3, j++)
        sub[j] = i;

    k_radix(v.begin(), &sub[0], tmp, 2, sz2, k);
    k_radix(v.begin(), tmp, &sub[0], 1, sz2, k);
    k_radix(v.begin(), &sub[0], tmp, 0, sz2, k);

    int last[3] = {-1, -1, -1}, unique = 0;
    for(int i = 0; i < sz2; i++) {
        bool diff = false;
        for(int j = 0; j < 3; last[j] = v[tmp[i]+j], j++)
            diff |= last[j] != v[tmp[i]+j];
        unique += diff;

        if(tmp[i]%3 == 1) sub[tmp[i]/3] = unique;
        else sub[tmp[i]/3 + sz] = unique;
    }

    vector<int> rec;
    if(unique < sz2) {
        rec = k_rec(sub, unique);
        rec.resize(sz2+sz);
        for(int i = 0; i < sz2; i++) sub[rec[i]] = i+1;
    } else {
        rec.resize(sz2+sz);
        for(int i = 0; i < sz2; i++) rec[sub[i]-1] = i;
    }

    for(int i = 0, j = 0; j < sz; i++)
        if(rec[i] < sz)
            tmp[j++] = 3*rec[i];
    k_radix(v.begin(), tmp, m0, 0, sz, k);
    for(int i = 0; i < sz2; i++)
        rec[i] = rec[i] < sz ? 3*rec[i] + 1 : 3*(rec[i] - sz) + 2;

    int prec = sz2-1, p0 = sz-1, pret = sz2+sz-1;
    while(prec >= 0 && p0 >= 0)
        if(rec[prec]%3 == 1 && k_cmp(v[m0[p0]], v[rec[prec]],
                                     sub[m0[p0]/3], sub[rec[prec]/3+sz]) ||
           rec[prec]%3 == 2 && k_cmp(v[m0[p0]], v[rec[prec]],
                                     v[m0[p0]+1], v[rec[prec]+1],
                                     sub[m0[p0]/3+sz], sub[rec[prec]/3+1]))
            rec[pret--] = rec[prec--];
        else
            rec[pret--] = m0[p0--];
    if(p0 >= 0) memcpy(&rec[0], m0, sizeof(int) * (p0+1));

    if(n%3==1) rec.erase(rec.begin());
    return rec;
}

vector<int> karkkainen(const string& s) {
    int n = s.size(), cnt = 1;
    vector<int> v(n + 3);

    for(int i = 0; i < n; i++) v[i] = i;
    k_radix(s.begin(), &v[0], tmp, 0, n, 256);
    for(int i = 0; i < n; cnt += (i+1 < n && s[tmp[i+1]] != s[tmp[i]]), i++)
        v[tmp[i]] = cnt;

    return k_rec(v, cnt);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int W;
    cin >> W;
    string word[W];
    int res[W];
    REP(i, W) {
        cin >> word[i];
        res[i] = 0;
    }
    
    int N;
    cin >> N;

    REP(www, N) {
        string song;
        cin >> song;
        
        vector<int> sa = karkkainen(song);
        
        REP(i,W) {
        
            int lo = 0, hi = SIZE(sa);
            int left = -1, right = -1;
        
            while (lo <= hi) {
                int mid = (lo+hi)>>1;
            
                int cmp = 0;
                int j = 0, k = sa[mid], sz = SIZE(word[i]);
                while (j < sz) {
                    if (word[i][j] != song[k]) {
                        if (word[i][j] < song[k]) cmp = 1;
                        else cmp = -1;
                        break;
                    }
                    j++, k++;
                }
            
                if (cmp < 0) lo = mid+1;
                else if (cmp > 0) hi = mid-1;
                else {
                    left = mid;
                    hi = mid-1;
                }
            }
        

            lo = 0, hi = SIZE(sa);
        
            while (lo <= hi) {
                int mid = (lo+hi)>>1;
            
                int cmp = 0;
                int j = 0, k = sa[mid], sz = SIZE(word[i]);
                while (j < sz) {
                    if (word[i][j] != song[k]) {
                        if (word[i][j] < song[k]) cmp = 1;
                        else cmp = -1;
                        break;
                    }
                    j++, k++;
                }
            
                if (cmp < 0) lo = mid+1;
                else if (cmp > 0) hi = mid-1;
                else {
                    right = mid;
                    lo = mid+1;
                }
            }
        
            if (left != -1) res[i] += (right-left+1);
        
        }
        
    }
    
    REP(i,W) cout << res[i] << "\n";
    
    
	return 0;
}

















