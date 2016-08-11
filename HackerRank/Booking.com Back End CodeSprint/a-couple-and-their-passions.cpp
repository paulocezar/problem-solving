#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const double PI = 3.14159265359;
const double EARTH_RADIUS = 6371;
const double HALF_C = PI / 180.0;

vector<int> passions;
vector<int> good_for[256];

string destination[256];
double lat[256], lon[256];

double deg2rad(double x) {
  return x * HALF_C;
}

double distance_between(int p1, int p2) {
    double p1_lat_rad = deg2rad(lat[p1]);
    double p2_lat_rad = deg2rad(lat[p2]);
    double p1_lon_rad = deg2rad(lon[p1]);
    double p2_lon_rad = deg2rad(lon[p2]);

    return acos(sin(p1_lat_rad) * sin(p2_lat_rad) +
                cos(p1_lat_rad) * cos(p2_lat_rad) *
                cos(p2_lon_rad - p1_lon_rad)) * EARTH_RADIUS;
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  map<string, int> passion_to_int;

  int n;
  cin >> n;
  passions.clear();
  for (int i = 0; i < n; ++i) {
    int m; cin >> m;
    while (m--) {
      string ax; cin >> ax;
      if (!passion_to_int.count(ax)) {
        passion_to_int[ax] = passion_to_int.size();
      }
      passions.push_back(passion_to_int[ax]);
    }
  }
  sort(passions.begin(), passions.end());
  passions.resize(distance(passions.begin(), unique(passions.begin(), passions.end())));

  int d;
  cin >> d;
  for (int i = 0; i < d; ++i) {
    good_for[i].clear();
    cin >> destination[i] >> lat[i] >> lon[i];
    int m; cin >> m;
    while (m--) {
      string ax; cin >> ax;
      if (passion_to_int.count(ax)) good_for[i].push_back(passion_to_int[ax]);
    }
    sort(good_for[i].begin(), good_for[i].end());
  }

  int best = -1;
  double best_dis = 0.0;
  string da, db;

  for (int i = 0; i < d; ++i) {
    for (int j = i+1; j < d; ++j) {
      int score = 0;
      for (int passion : passions) {
        if (binary_search(good_for[i].begin(), good_for[i].end(), passion) || binary_search(good_for[j].begin(), good_for[j].end(), passion)) score++;
      }
      if (score > best) {
        best = score;
        best_dis = distance_between(i, j);
        da = destination[i];
        db = destination[j];
      } else if (score == best) {
        double ndis = distance_between(i, j);
        if (ndis < best_dis) {
          best_dis = ndis;
          da = destination[i];
          db = destination[j];
        }
      }
    }
  }

  if (da > db) swap(da, db);
  cout << da << " " << db << "\n";

  return 0;
}
