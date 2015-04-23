#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include <numeric>
#include <limits.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef long long ll;

#define ITE(v) typeof(v.begin())
#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORIT(it,v) for(ITE(v) it = v.begin(); it != v.end(); it++)
#define ALL(v) v.begin(), v.end()
#define SZ(v) int(v.size())
#define pb push_back
#define SQR(a) ((a)*(a))

#define INF 0x3f3f3f3f
#define EPS (1e-8)

#define MAX 100100

struct build {
  int x,h,t;
};

bool cmp(build a, build b) {
  return a.x < b.x;
}

build v[2*MAX];
int n;
multiset<int> s;
ITE(s) it, it1;

vector<ii> ans;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  fin >> n;
  int h,l,r;
  FOR(i,n) {
    fin >> h >> l >> r;
    v[2*i].h = v[2*i+1].h = h;
    v[2*i].t = 0;
    v[2*i+1].t = 1;
    v[2*i].x = l;
    v[2*i+1].x = r;
  }
  sort(v,v+2*n,cmp);
  int lasty = 0;
  int lastx = v[0].x;
  FOR(i,2*n) {
    lastx = v[i].x;
    i--;
    do {
      i++;
      if (v[i].t == 0) s.insert(v[i].h);
      else s.erase(s.find(v[i].h));
    } while (i < 2*n - 1 && v[i+1].x == lastx);

    int y;
    if (s.empty()) y = 0;
    else {
      it = s.end();
      it--;
      y = *it;
    }    
    if (y != lasty) {
      ans.pb(ii(lastx,lasty));
      ans.pb(ii(lastx,y));
    }
    lasty = y;
  }
  fout << ans.size() << endl;
  FORIT(it,ans) fout << it->first << " " << it->second << endl;
  fin.close();
  fout.close();
  return 0;
}