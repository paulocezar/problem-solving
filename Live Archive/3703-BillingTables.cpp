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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char prfx[13]; int prflen = 0;
string paname;

struct node_t{
    string name;
    map<char,node_t*> chld;
    explicit node_t() { name = ""; chld.clear(); }
    bool isleaf() { return !name.empty(); }
    
    string compress(bool incl = false) {
        
        if (isleaf()) {
            if (chld.empty()) return name;
            
            string oldpa = paname;
            paname = name;
            set<string> ss;
                
            for (char c = '0'; c <= '9'; ++c) {
                if (chld.count(c)) ss.insert(chld[c]->compress(true));
            }
                
            if (SIZE(ss) == 1 && (*ss.begin() == name)) {
                chld.clear();
                paname = oldpa;
                return name;
            }
            
            paname = oldpa;
            return "?";                       
        } else {            
            set<string> ss;
            for (char c = '0'; c <= '9'; ++c) {
                if (chld.count(c)) ss.insert(chld[c]->compress(incl));
            }
            
            if (SIZE(ss) == 1) {   
                if (incl) {
                    if (*ss.begin() == paname) {
                        chld.clear();
                        name = paname;
                        return name;
                    }
                } else if( *ss.begin() != "?"){
                    if (SIZE(chld) == 10) {
                        chld.clear();
                        name = *ss.begin();
                        return name;
                    }
                }
            }
            return "?";                
        }
    }
    
    int calc(bool incl = false) {
        int res = 0;
        if (isleaf()) {
            
            if (name != "invalid") {
                if (!chld.empty()) {
                    
                    res += (10 - SIZE(chld));
                    FORIT(val,chld) res += val->second->calc(true);
                    
                } else res += 1;
            } else {
                FORIT(val,chld) res += val->second->calc(false);   
            }
            
        } else {
            if (incl) res += (10 - SIZE(chld));
            FORIT(val,chld)  res += val->second->calc(incl);  
        }
        return res;
    }
    
    void gen(bool incl = false) {
        
        if (isleaf()) {
            if (chld.empty()) {
                if (name != "invalid") {
                    prfx[prflen] = '\0';
                    cout << prfx << " " << name << "\n";
                }
                return;
            }
            
            string oldpa = paname;
            paname = name;
            
            for (char c = '0'; c <= '9'; ++c) {
                prfx[prflen++] = c;
                
                if (chld.count(c)) {
                    chld[c]->gen(true);
                } else if(name != "invalid") {
                    prfx[prflen] = '\0';
                    cout << prfx << " " << name << "\n";
                }
                prflen--;
            }                        
            paname = oldpa;                        
        } else {
            
            for (char c = '0'; c <= '9'; ++c) {
                if (chld.count(c)) {
                    prfx[prflen++] = c;
                    chld[c]->gen(incl);
                    --prflen;
                } else if(incl && paname != "invalid") {
                    prfx[prflen] = c;
                    prfx[prflen+1] = '\0';
                    cout << prfx << " " << paname << "\n";
                }
            }
                
        }
    }
}; 

char from[13], to[13];
string name;
node_t *root;
bool forced, forcedbeg, forcedend;

inline bool fullrange(int pos) {
    if (forced) return true;
    for(int i = pos; i < 11; ++i)
        if ((!forcedbeg && from[i] != '0') || (!forcedend && to[i] != '9')) return false;
    return true;
}

void add(node_t* node, int pos) {
    
    if (node->isleaf()) return;
    if (fullrange(pos)) { node->name = name; return; }
    
    char bg = forcedbeg ? '0' : from[pos];
    char ed = forcedend ? '9' : to[pos];
    
    
    bool oldfb = forcedbeg;
    bool oldfe = forcedend;
    bool oldfd = forced;
    
    for (char c = bg; c <= ed; ++c) {
        if (!((node->chld).count(c))) { node->chld[c] = new node_t(); }
        
        if (bg != ed) {
        
            if (c != bg && c != ed) forced = true;
            if (c == bg) forcedend = true;
            if (c == ed) forcedbeg = true;
            add(node->chld[c],pos+1);
            
            forced = oldfd;
            forcedend = oldfe;
            forcedbeg = oldfb;    
                        
        } else add(node->chld[c],pos+1);
        
    }    
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    forced = false;
    forcedend = false;
    forcedbeg = false;
    prflen = 0;
    
    int n;
    bool blnk = false;
    while (cin >> n) {
        string ff, spc, tt;
        
        if (blnk) cout << "\n";
        else blnk = true;
        
        root = new node_t();
        REP(i,n) {
            cin >> ff >> spc >> tt >> name;
            
            int prf = SIZE(ff) - SIZE(tt);
            REP(i,prf) { to[i] = ff[i]; from[i] = ff[i]; }
            FOR(i,prf,SIZE(ff)-1) { to[i] = tt[i-prf]; from[i] = ff[i]; }
            FOR(i,SIZE(ff),10) from[i] = '0', to[i] = '9';
            from[11] = '\0'; to[11] = '\0';            
            add(root,0);                
        }
        root->compress();
        int res = root->calc();
        if (root->isleaf() && root->chld.empty()) {
            if (root->name == "invalid") cout << "0\n";
            else {
                cout << "10\n";
                for (char c = '0'; c <= '9'; ++c) cout << c << " " << root->name << "\n";
            }
        } else {
           cout << res << "\n";
           root->gen();
        }
    }
    
    return 0;
}
















