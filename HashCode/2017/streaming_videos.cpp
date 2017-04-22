#include <bits/stdc++.h>

using namespace std;

class video_t {
public:
  int id, size;
};

class endpoint_t {
public:
  int id;
  long long LD, total_demand;
  map<int, long long> video_demand;

  // .first = cache_server id, .second = latency from cache server to this endpoint
  vector<pair<int,int>> cache_servers;

  bool operator < (const endpoint_t &e) const {
    if (total_demand*LD != e.total_demand*e.LD) return total_demand*LD > e.total_demand*e.LD;
    if (cache_servers.size() != e.cache_servers.size()) return cache_servers.size() < e.cache_servers.size();
    if (total_demand != e.total_demand) return total_demand > e.total_demand;
    return LD > e.LD;
  }
};

class request_t {
public:
  int video, endpoint, predicted;
};

// solutions are maps from cache server id to ordered vector of videos on that cache server
typedef map<int, set<int>> solution_t;

long long eval(const solution_t &sol, const vector<request_t> &requests, const vector<endpoint_t> &endpoints) {
  long long sum = 0LL;
  for (const auto &request : requests) {
    auto &endpoint = endpoints[request.endpoint];
    int L = endpoint.LD;
    for (auto &cache : endpoint.cache_servers) {
      auto it = sol.find(cache.first);
      if (it != sol.end()) {
        auto videos = it->second;
        if (videos.count(request.video)) {
          L = min(L, cache.second);
        }
      }
    }
    sum += request.predicted * (endpoint.LD - L);
  }
  // maybe divide then multiply .. ?
  return (sum * 1000LL) / requests.size();
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int V, E, R, C, X;
  cin >> V >> E >> R >> C >> X;

  vector<video_t> videos(V);
  for (int i = 0; i < V; ++i) {
    videos[i].id = i;
    cin >> videos[i].size;
  }

  vector<endpoint_t> endpoints(E);
  for (int i = 0; i < E; ++i) {
    endpoints[i].id = i;
    int K;
    cin >> endpoints[i].LD >> K;
    endpoints[i].cache_servers.resize(K);
    for (auto &cache_server : endpoints[i].cache_servers) {
      cin >> cache_server.first >> cache_server.second;
    }
  }

  vector<request_t> requests(R);
  for (auto &request : requests) {
    cin >> request.video >> request.endpoint >> request.predicted;
    endpoints[request.endpoint].video_demand[request.video] += request.predicted;
    endpoints[request.endpoint].total_demand += request.predicted;
  }

  sort(endpoints.begin(), endpoints.end());

  vector<int> remaining_capacity(C, X);
  solution_t sol;

  for (auto &e : endpoints) {
    sort(e.cache_servers.begin(), e.cache_servers.end(), [&remaining_capacity](pair<int,int> &a, pair<int,int> &b) {
      if (a.second != b.second) return a.second < b.second;
      return remaining_capacity[a.first] > remaining_capacity[a.first];
    });

    set<int> endpoint_videos;
    for (auto &vd : e.video_demand) {
      endpoint_videos.insert(vd.first);
    }

    for (auto &c : e.cache_servers) {
      vector<int> to_erase, items;

      for (int &v : endpoint_videos) if (sol.count(c.first) && sol[c.first].count(v)) {
        to_erase.push_back(v);
      } else {
        items.push_back(v);
      }

      for (int &v : to_erase) endpoint_videos.erase(v);

      int vv = endpoint_videos.size();

      long long dp[vv][remaining_capacity[c.first] + 1];
      int it[vv][remaining_capacity[c.first] + 1];

      int i = 0;
      for (int &v : endpoint_videos) {
        if (sol.count(c.first) && sol[c.first].count(v)) continue;
        for (int j = 0; j <= remaining_capacity[c.first]; ++j) {
          dp[i][j] = i ? dp[i-1][j] : 0;
          if (j - videos[v].size() >= 0) {
            int nn = i ? dp[i-1][j - videos[v].size()] : 0;
            nn += e.video_demand[v];
            if (nn > dp[i][j]) {
              dp[i][j] = nn;
              it[i][j] = v;
            }
          }
        }
        i++;
      }

      while ()

      if (sol.count(c.first) && sol[c.first].count(v)) break;
        if (videos[v].size <= remaining_capacity[c.first]) {
          remaining_capacity[c.first] -= videos[v].size;
          sol[c.first].insert(v);
          break;
        }
      }


  }

  cout << sol.size() << "\n";
  for (auto &cache : sol) {
    cout << cache.first;
    for (auto &videos : cache.second) cout << " " << videos;
    cout << "\n";
  }


  return 0;
}
