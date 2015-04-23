#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long TYPE;
const TYPE EPS = 1e-15, INF = 1e15;

inline int sgn(TYPE a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(TYPE a, TYPE b) { return sgn(a - b); }

struct pt {
    TYPE x, y;
    int id;
    pt(TYPE x = 0, TYPE y = 0, int id = 0) : x(x), y(y), id(id) {}

    bool operator==(pt p) { return cmp(x, p.x) == 0 && cmp(y, p.y) == 0; }
    bool operator<(pt p) const {
        return cmp(x, p.x) ? cmp(x, p.x) < 0 : cmp(y, p.y) < 0;
    }
    bool operator<=(pt p) { return *this < p || *this == p; }
    TYPE operator||(pt p) { return x*p.x + y*p.y; }
    TYPE operator%(pt p) { return x*p.y - y*p.x; }
    pt operator~() { return pt(x, -y); }
    pt operator+(pt p) { return pt(x + p.x, y + p.y); }
    pt operator-(pt p) { return pt(x - p.x, y - p.y); }
    pt operator*(pt p) { return pt(x*p.x - y*p.y, x*p.y + y*p.x); }
    pt operator/(TYPE t) { return pt(x/t, y/t); }
    pt operator/(pt p) { return (*this * ~p)/(p||p); }
};

TYPE norm(pt a) { return a||a; }
TYPE abs(pt a) { return sqrt(a||a); }
TYPE dist(pt a, pt b) { return abs(a - b); }
TYPE area(pt a, pt b, pt c) { return (a-c)%(b-c); }
int ccw(pt a, pt b, pt c) { return sgn(area(a, b, c)); }
pt unit(pt a) { return a/abs(a); }
double arg(pt a) { return atan2(a.y, a.x); }
pt f_polar(TYPE mod, double ang) { return pt(mod * cos(ang), mod * sin(ang)); }
inline int g_mod(int i, int n) { if(i == n) return 0; return i; }

bool compy(pt a, pt b) {
    return cmp(a.y, b.y) ? cmp(a.y, b.y) < 0 : cmp(a.x, b.x) < 0;
}
bool compx(pt a, pt b) { return a < b; }

bool in_rect(pt a, pt b, pt c) {
    return sgn(c.x - min(a.x, b.x)) >= 0 && sgn(max(a.x, b.x) - c.x) >= 0 &&
        sgn(c.y - min(a.y, b.y)) >= 0 && sgn(max(a.y, b.y) - c.y) >= 0;
}
bool ps_isects(pt a, pt b, pt c) { return ccw(a,b,c) == 0 && in_rect(a,b,c); }

int point_polygon(pt p, vector<pt>& pol) {
    int n = pol.size(), count = 0;

    for(int i = 0; i < n; ++i) {
        int i1 = g_mod(i+1, n);
        if (ps_isects(pol[i], pol[i1], p)) return -1;
        else if(((sgn(pol[i].y - p.y) == 1) != (sgn(pol[i1].y - p.y) == 1)) &&
                ccw(pol[i], p, pol[i1]) == sgn(pol[i].y - pol[i1].y)) ++count;
    }
    return count % 2;
}


#define MAXSZ 20202

int tree[4*MAXSZ];
TYPE split[4*MAXSZ];
vector<pt> pts;

void kd_recurse(int root, int left, int right, bool x) {
    tree[root] = -1;
    if(left == right) {
        tree[root] = left;
        return;
    }

    int mid = (right+left)/2;
    nth_element(pts.begin() + left, pts.begin() + mid,
                pts.begin() + right + 1, x ? compx : compy);
    split[root] = x ? pts[mid].x : pts[mid].y;

    kd_recurse(2*root+1, left, mid, !x);
    kd_recurse(2*root+2, mid+1, right, !x);
}

pair<TYPE, int> res[2];

void check(pt a, pt b)
{
	pair<TYPE, int> cur = make_pair(norm(a - b), b.id);
    res[1] = min(res[1], cur);
    sort(res, res+2);
}


void kd_neighbor(int root, pt a, bool x) {
    if(tree[root] != -1) {
        check(a, pts[tree[root]]);
        return;
    }
    
    TYPE num = x ? a.x : a.y;
    int term = num <= split[root] ? 1 : 2;
    
    kd_neighbor(2*root + term, a, !x);
    
    if ((res[1].first == INF) || ((split[root] - num)*(split[root] - num) <= res[1].first)) {
        kd_neighbor(2*root + 3 - term, a, !x);
    }

}

int main() {
    ios::sync_with_stdio(false);
    int kases;
    cin >> kases;
    for (int kase = 1; kase <= kases; ++kase) {
        
        int N; cin >> N;
        pts.resize(N);

        for (int i = 0; i < N; ++i) {
            cin >> pts[i].x >> pts[i].y;
            pts[i].id = i+1;
        }
        
        int R;
        cin >> R;
        cout << "Case #" << kase << ":\n";
        for (int region = 1; region <= R; ++region) {
            
            int bk; cin >> bk;
            vector<pt> poly(bk);
            for (int i = 0; i < bk; ++i) cin >> poly[i].x >> poly[i].y;
            
            int len = N;
            for (int i = 0; i < len; ++i) {
                if (!point_polygon(pts[i], poly)) {
                    swap(pts[i], pts[len-1]);
                    len--;
                    i--;
                }
            }
            
            kd_recurse(0,0,len-1,true);
            
            cout << "Region " << region << "\n";
            int mk;
            cin >> mk;
            pt a;
            while (mk--) {
                cin >> a.x >> a.y;
                res[0].first = res[1].first = INF;                
                kd_neighbor(0, a, true);
                cout << res[0].second << " " << res[1].second << "\n";
            }
        }
        
    }
    
    
    return 0;
}









