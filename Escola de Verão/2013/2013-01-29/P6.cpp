#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <cfloat>
#include <sstream>
#include <utility>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <bitset>

#define S(n) int((n).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)

#define pb push_back
#define mp make_pair

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3fffffffffll

using namespace std;

typedef long long int64;

const double eps = 1e-9;
const double inf = 1e50;

struct pt;

typedef pair<pt, pt> line;
typedef vector<pt> polygon;

int cmp(double a, double b = 0.0) {
    if(a - b > eps) return 1;
    if(b - a > eps) return -1;
    return 0;
}

bool between(double a, double b, double c) {
    if(a > b) swap(a, b);
    return cmp(a, c) <= 0 && cmp(c, b) <= 0;
}

struct pt{
    double x, y;
    
    pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    
    double len() {
        return sqrt(x*x + y*y);
    }
    
    double len2() {
        return x*x + y*y;
    }
    
    pt normalize() {
        return (*this)/len();
    }
    
    pt operator - (pt p) {
        return pt(x - p.x, y - p.y);
    }
    
    pt operator + (pt p) {
        return pt(x + p.x, y + p.y);
    }
    
    pt operator * (double k) {
        return pt(x*k, y*k);
    }
    
    pt operator / (double k) {
        return pt(x/k, y/k);
    }
    
    bool operator < (const pt& p)  const {
        if(cmp(x, p.x)) return x < p.x;
        return y < p.y;
    }
    
    bool operator == (const pt p) {
        return (!cmp(x, p.x) && !cmp(y, p.y));
    }
};

double cross(pt a, pt b) {
    return a.x*b.y - a.y * b.x;
}

int side_sign(pt a, pt b, pt c) {
    return cmp(cross(a-c, b-c));
}

bool in_box(pt a, pt b, pt c) {
    return between(a.x, b.x, c.x) && between(a.y, b.y, c.y);
}

bool intersect(line a, line b, pt& inter) {
    double det = cross(a.first - b.first, a.second - b.second);
    if(!cmp(det)) {
        if(side_sign(a.first, a.second, b.first)) return false;
        inter = pt(inf, inf);
        return true;
    }
    
    inter = a.first + (a.second - a.first) * cross(b.second - b.first, a.first - b.first) / det;
    return true;
}

bool intersect_seg(line a, line b, pt& inter) {
    if(!intersect(a, b, inter)) return false;
    if(inter == pt(inf, inf)) {
        return in_box(a.first, a.second, min(b.first, b.second)) || in_box(b.first, b.second, min(a.first, a.second));
    }
    
    return in_box(a.first, a.second, inter) && in_box(b.first, b.second, inter);
}

int n;

class mou{
public:
    pt h;
    line e, d;
    
    mou(pt h = pt(), line e = mp(pt(), pt()), line d = mp(pt(), pt())) : h(h), e(e), d(d) {}
    
    bool operator < (const mou& a)  const {
        return h.y > a.h.y;
    }
};

bool isInside(mou a, mou b) {
    // checa se b esta dentro de a
    return (b.e.first.x >= a.e.first.x && b.d.second.x <= a.d.second.x);
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    while(cin>>n && n != -1) {
        vector<mou> vec(n);
        double altura = -inf;
        REP(i, n) {
            int e, d, h;
            cin>>e>>d>>h;
            altura = max(altura, double(h));
            pt H = pt(e + (d -e)/2, h);
            vec[i] = mou(H, mp(pt(e, 0), H), mp(H, pt(d, 0)));
        }
        
        sort(vec.begin(), vec.end());
        
        vector<pt> omg;
        for(int i = 0; i < int(vec.size()); i++) {
            for(int j = i+1; j < int(vec.size()); ) {
                pt aux, haha = pt();
                bool tem = false, tevealgum = false;
                if(intersect_seg(vec[i].e, vec[j].e, aux)) {
                    tem = true;
                    haha = aux;
                }
                
                if(intersect_seg(vec[i].e, vec[j].d, aux)) {
                    tem = true;
                    if(haha == pt()) {
                        haha = aux;
                    } else {
                        if(aux.y > haha.y) {
                            haha = aux;
                        }
                    }
                }
                
                if(tem) {
                    tevealgum = true;
                    omg.pb(haha);
                } else {
                    omg.pb(vec[i].e.first);
                }
                
                tem = false;
                haha = pt();
                if(intersect_seg(vec[i].d, vec[j].e, aux)) {
                    tem = true;
                    haha = aux;
                }
                
                if(intersect_seg(vec[i].d, vec[j].d, aux)) {
                    tem = true;
                    if(haha == pt()) {
                        haha = aux;
                    } else {
                        if(aux.y > haha.y) {
                            haha = aux;
                        }
                    }
                }
                
                if(tem) {
                    tevealgum = true;
                    omg.pb(haha);
                } else {
                    omg.pb(vec[i].d.second);
                }
                
                if(!tevealgum) {
                    if(isInside(vec[i], vec[j])) {
                        vec.erase(vec.begin() + j);
                    } else {
                        j++;
                    }
                } else j++;
            }
        }
        
        sort(omg.begin(), omg.end());
        double largura = omg[S(omg) - 1].x - omg[0].x;
        double sumt = 0.0;
        for(int i = 1; i < S(omg); i++) {
            if(omg[i].y == altura) {
                sumt += ((altura - omg[i-1].y) * (omg[i].x - omg[i-1].x))/2.0;
            } else if(omg[i-1].y == altura) {
                sumt += ((altura - omg[i].y) * (omg[i].x - omg[i-1].x))/2.0;
            } else if(omg[i-1].y == 0.0){
                sumt += (omg[i].x - omg[i-1].x) * altura;
            } else {
                sumt += (((altura - omg[i].y) + (altura - omg[i-1].y)) * (omg[i].x - omg[i-1].x))/2.0;
            }
        }
        
        cout << altura*largura - sumt << '\n';
    }
    return 0;
}

