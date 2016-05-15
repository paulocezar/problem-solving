#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

#ifdef OFFLINE_TEST
  mt19937 _eng(chrono::system_clock::now().time_since_epoch().count());
#else
  mt19937 _eng(1337);
#endif

class StarTraveller {
public:
  int NStars, max_turns, current_turn, unvisited;
  vector<int> visited;
  vector<vector<int>> dist;
  vector<int> star_order;
  vector<int> ship_order;

  int init(vector<int> _stars) {
    NStars = _stars.size() / 2;
    unvisited = NStars;
    dist.resize(NStars, vector<int>(NStars, 0));
    visited.resize(NStars, 0);
    star_order.resize(NStars);
    ship_order.resize(0);

    vector<pair<int,int>> stars(NStars);
    for (int i = 0; i < NStars; ++i) {
      star_order[i] = i;
      stars[i].first = _stars[i<<1];
      stars[i].second = _stars[(i<<1)+1];
    }

    for (int i = 0; i < NStars; ++i) {
      for (int j = i+1; j < NStars; ++j) {
        int dx = stars[i].first - stars[j].first;
        int dy = stars[i].second - stars[j].second;
        dist[i][j] = dist[j][i] = dx*dx + dy*dy;
      }
    }

    current_turn = 0;
    max_turns  = NStars * 4;

    return 0;
  }

  vector<int> makeMoves(vector<int> ufos, vector<int> ships) {
    current_turn++;
    int remaining_turns = max_turns - current_turn;

    int NShips = ships.size();
    int ships_sent = 0;

    vector<int> moves = ships;

    if (ship_order.size() == 0) {
      ship_order.resize(NShips);
      for (int i = 0; i < NShips; ++i) {
        ship_order[i] = i;
        if (visited[ships[i]]) continue;
        #ifdef OFFLINE_TEST_DEBUG
          cerr << "SHIP " << i << "(" << ships[i] << ") STAYS" << endl;
        #endif
        visited[ships[i]] = 1;
        unvisited--;
        ships[i] = -1;
        ships_sent++;
      }
    }

    shuffle(star_order.begin(), star_order.end(), _eng);
    shuffle(ship_order.begin(), ship_order.end(), _eng);

    int local_explorers = 0.4774 * (NShips - ships_sent);
    vector<pair<int,pair<int,int>>> closest_star;

    for (int j : ship_order) {
      if (ships_sent == NShips) break;
      if (ships[j] != moves[j]) continue;

      int choose = -1;
      for (int i : star_order) {
        if (visited[i]) continue;
        if ((choose == -1) || (dist[ships[j]][i] < dist[ships[j]][choose])) choose = i;
      }
      if (choose == -1) continue;
      closest_star.push_back(make_pair(dist[ships[j]][choose], make_pair(j, choose)));
    }

    sort(closest_star.begin(), closest_star.end());

    for (auto &local : closest_star) {
      if (ships_sent == NShips) break;
      if (!local_explorers) break;
      int ship = local.second.first, star = local.second.second;
      if (visited[star]) continue;
      visited[star] = 1;
      unvisited--;
      moves[ship] = star;
      ships_sent++;
      local_explorers--;
      #ifdef OFFLINE_TEST_DEBUG
        cerr << "~~ SHIP " << ship << "(" << ships[ship] << ") goes to " << star << endl;
      #endif
    }

    int NUfos = ufos.size() / 3;
    vector<int> ufo_goin(NStars, 0);

    shuffle(ship_order.begin(), ship_order.end(), _eng);

    for (int i = 0; i < NUfos; ++i) {
      ufo_goin[ufos[3*i+1]] = 1;
      ufo_goin[ufos[3*i+2]] = 1;
      if (ships_sent == NShips) continue;

      int goin = ufos[3*i+1];
      if (visited[goin]) continue;

      for (int j : ship_order) {
        if (moves[j] != ships[j]) continue;
        if (ships[j] != ufos[3*i]) continue;

        visited[goin] = 1;
        unvisited--;
        moves[j] = goin;
        ships_sent++;
        #ifdef OFFLINE_TEST_DEBUG
          cerr << ":: SHIP " << j << "(" << ships[j] << ") goes to " << goin << endl;
        #endif
        break;
      }
    }

    if (unvisited < (remaining_turns * NShips)) {
      shuffle(ship_order.begin(), ship_order.end(), _eng);

      int allowed_followers = 0.7337 * (NShips - ships_sent);
      for (int i = 0; i < NUfos; ++i) {
        if (ships_sent == NShips) break;
        if (!allowed_followers) break;

        int next = ufos[3*i+2];
        if (visited[next]) continue;

        for (int j : ship_order) {
          if (moves[j] != ships[j]) continue;
          if (ships[j] != ufos[3*i]) continue;

          moves[j] = ufos[3*i+1];
          ships_sent++;
          allowed_followers--;
          #ifdef OFFLINE_TEST_DEBUG
            cerr << ">> SHIP " << j << "(" << ships[j] << ") goes to " << ufos[3*i+1] << endl;
          #endif
          break;
        }
      }
    }

    shuffle(star_order.begin(), star_order.end(), _eng);
    shuffle(ship_order.begin(), ship_order.end(), _eng);

    int explorers = 0.5 * (NShips - ships_sent);
exploration:
    for (int i : star_order) {
      if (ships_sent == NShips) break;
      if (!explorers) break;
      if (visited[i]) continue;

      int choose = -1;
      for (int j : ship_order) {
        if (ships[j] != moves[j]) continue;
        if ((choose == -1) || (dist[ships[j]][i] < dist[ships[choose]][i])) choose = j;
      }

      visited[i] = 1;
      unvisited--;
      moves[choose] = i;
      ships_sent++;
      explorers--;
      #ifdef OFFLINE_TEST_DEBUG
        cerr << "!! SHIP " << choose << "(" << ships[choose] << ") goes to " << i << endl;
      #endif
    }
    if (unvisited > (remaining_turns * NShips)) {
      explorers = max(1.0, 0.5 * (NShips - ships_sent));
      if (ships_sent < NShips) goto exploration;
    }

    shuffle(ship_order.begin(), ship_order.end(), _eng);
    closest_star.resize(0);

    for (int j : ship_order) {
      if (ships_sent == NShips) break;
      if (ships[j] != moves[j]) continue;

      int choose = -1;
      for (int i : star_order) {
        if (visited[i] && !ufo_goin[i]) continue;
        if ((choose == -1) || (dist[ships[j]][i] < dist[ships[j]][choose])) choose = i;
      }
      if (choose == -1) continue;
      closest_star.push_back(make_pair(dist[ships[j]][choose], make_pair(j, choose)));
    }

    sort(closest_star.begin(), closest_star.end());

    for (auto &local : closest_star) {
      if (ships_sent == NShips) break;
      int ship = local.second.first, star = local.second.second;
      if (visited[star]) continue;
      visited[star] = 1;
      unvisited--;
      moves[ship] = star;
      ships_sent++;
      #ifdef OFFLINE_TEST_DEBUG
        cerr << "== SHIP " << ship << "(" << ships[ship] << ") goes to " << star << endl;
      #endif
    }

    return moves;
  }
};
// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
  for (auto &el : v) {
    cin >> el;
  }
}

int main(int argc, char* argv[]) {
  int NStars;
  cin >> NStars;
  vector<int> stars(NStars);
  getVector(stars);

  StarTraveller algo;
  int ignore = algo.init(stars);
  cout << ignore << endl;
  cout.flush();

  while (true) {
    int NUfo;
    cin >> NUfo;
    if (NUfo<0) break;
    vector<int> ufos(NUfo);
    getVector(ufos);
    int NShips;
    cin >> NShips;
    vector<int> ships(NShips);
    getVector(ships);
    vector<int> ret = algo.makeMoves(ufos, ships);
    cout << ret.size() << endl;
    for (int &val : ret) {
      cout << val << endl;
    }
    cout.flush();
  }

  return 0;
}
