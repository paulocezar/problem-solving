#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <tr1/unordered_map>
#include <queue>

#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f

using namespace std;

const double EPS = 1e-9;

int cmp(double a, double b = 0.0) {
    if(fabs(a-b) < EPS) return 0;
    return a > b ? 1 : -1;
}

struct pt{
    double x, y;
    
    pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    
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
    
    bool operator < (const pt& p) const{
        if(fabs(x - p.x) >= EPS) return x < p.x;
        return y < p.y;
    }
    
    bool operator == (const pt& p) const{
        return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
    }
};

struct st{
    pt cur;
    int ah, av;
    
    st(pt a = pt(), int b = 0, int c = 0) : cur(a), ah(b), av(c) {}
    
    bool operator < (const st& s) const {
        return cur < s.cur;
    }
};

double cross(pt a, pt b){
    return a.x*b.y - a.y*b.x;
}

double signed_area(pt a, pt b, pt c){
    return cross((a-c), (b-c))/2.0;
}

bool in_box(pt a, pt b, pt c) {
    return (cmp(c.x, min(a.x, b.x)) >= 0 && cmp(c.x, max(a.x, b.x)) <= 0
        && cmp(c.y, min(a.y, b.y)) >= 0 && cmp(c.y, max(a.y, b.y)) <= 0);
}

bool intersect(pt a, pt b, pt c, pt d, pt& inter) {
    double det = cross(b-a, d-c);
    if(fabs(det) < EPS) {
        if(fabs(signed_area(a, b, c)) < EPS) {
            inter = pt(INF, INF);
            return true;
        }
        return false;
    }
    
    double ua = (cross(d - c, a - c))/det;
    inter = a + (b - a)*ua;
    
    return true;
}

bool intersect_seg(pt a, pt b, pt c, pt d, pt& inter) {
    if(!intersect(a, b, c, d, inter)) return false;
    
    if(inter == pt(INF, INF)) {
        return in_box(a, b, min(c, d)) || in_box(c,d , min(a, b));
    }
    
    return in_box(a, b, inter) && in_box(c, d, inter);
}

pair<pt, pt> walls[11];
pt ori, dest;
int n, m, w;

inline bool isV(pt a) {
    return (a.x >= 0.0 && a.x < n && a.y >= 0.0 && a.y < m);
}

int solve() {
    priority_queue<pair<int, st> > q;
    map<st, int> dis;
    
    dis[st(ori, 0, 0)] = 0;
    q.push(mp(0, st(ori, 0, 0)));
    while(!q.empty()) {
        int d = -q.top().first;
        st s = q.top().second;
        q.pop();
        
        cout << "estou no estado " << s.cur.x << " " << s.cur.y << " ah = " << s.ah << " av = " << s.av << " e cheguei aqui com distancia " << d << endl;
        
        if(s.cur == dest && s.ah == 0 && s.av == 0) {
            return d;
            cout << "cheguei no destino de forma invalida" << endl;
        }
        
        for(int x = -1; x <= 1; x++) {
            for(int y = -1; y <= 1; y++) {
                if (x && y) continue;
                st np = st(pt(s.cur.x + s.av + x, s.cur.y + s.ah + y), s.ah + y, s.av + x);
                cout << "vou tentar ir pro ponto " << np.cur.x << " " << np.cur.y << endl;
                
                if(isV(np.cur) && (!dis.count(np) || (d + 1) < dis[np])) {
                    cout << "este ponto e valido e da pra melhorar a distancia dele" << endl;
                    bool deumerda = false;
                    for(int i = 0; i < w; i++) {
                        pt aux;
                        if(intersect_seg(s.cur, np.cur, walls[i].first, walls[i].second, aux)) {
                            cout << "pra fazer este movimento eu bato numa parede" << endl;
                            deumerda = true;
                            break;
                        }
                    }

                    if(!deumerda) {
                        cout << "da pra fazer o movimento de boa" << endl;
                        dis[np] = d+1;
                        q.push(mp(-dis[np], np));
                    }
                }
            }
        }
    }
    
    return INF;
}

int main(){
    ios::sync_with_stdio(false);
    string line;
    while(getline(cin, line)) {
        istringstream iss(line);
        iss >> m >> n;
        iss >> ori.y >> ori.x >> dest.y >> dest.x;
        iss >> w;
        for(int i = 0; i < w; i++) {
            cin>>walls[i].first.y>>walls[i].first.x>>walls[i].second.y>>walls[i].second.x;
        }
        
        cout << solve() << '\n';
    }
    return 0;
}