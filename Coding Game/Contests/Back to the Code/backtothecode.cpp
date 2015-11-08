#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int step[] = {1, 2, 4, 8, 16, 32};

int dx[] = {-1, 0,+1, 0};
int dy[] = { 0,+1, 0,-1};

class player_t {
public:
  int x, y, backInTimeLeft;
  int distance_to(int xa, int ya) {
    return abs(x-xa) + abs(y-ya);
  }
};

inline bool isValid(int x, int y) {
  return (0 <= x) && (x < 35) && (0 <= y) && (y < 20);
}

int main() {

  int opponentCount;
  cin >> opponentCount; cin.ignore();
  stack< pair<int,int> > leadingStack;
  int previousRound = 0;

  map<int, vector<string>> grid_at;
  map<int, vector<player_t>> opponents_at;

  bool know_the_future = false;

  int dir = 0;
  int count = 0;
  int tries = 16;
  int count2 = 0;

  while (1) {
    int gameRound;
    cin >> gameRound; cin.ignore();

    player_t me;
    cin >> me.x >> me.y >> me.backInTimeLeft; cin.ignore();
    
    vector<player_t> opponent(opponentCount);
    for (int i = 0; i < opponentCount; i++) {
      cin >> opponent[i].x >> opponent[i].y >> opponent[i].backInTimeLeft; cin.ignore();
    }

    int score = 0;
    int freeCells = 0;
    vector<int> opponentScore(opponentCount);

    vector<string> grid(20);
    for (int i = 0; i < 20; i++) {
      cin >> grid[i]; cin.ignore();
      for (int j = 0; j < 35; ++j) {
        switch (grid[i][j]) {
          case '0': score++; break;
          case '.': freeCells++; break;
          default: opponentScore[grid[i][j]-'1']++; break;
        }
      }
    }

    if (previousRound >= gameRound) {
      while (!leadingStack.empty() && (leadingStack.top().first >= gameRound)) leadingStack.pop();            
      know_the_future = true;
    }

    previousRound = gameRound;

    int bestOpponent = 0;
    for (int i = 0; i < opponentCount; ++i) {
      if (opponentScore[i] > opponentScore[bestOpponent]) {
        bestOpponent = i;
      }
    }

    int lead = score - opponentScore[bestOpponent];

    if (me.backInTimeLeft) {
      if ((lead < -30) || (opponentScore[bestOpponent] > (freeCells+score))) {
        int roundsToReturn = 25;
        if (!leadingStack.empty()) {
          roundsToReturn = min(gameRound - leadingStack.top().first, roundsToReturn);
        }
        cout << "BACK " << roundsToReturn << endl;
        continue;
      }
    }

    if (lead > 0) {
      if (leadingStack.empty() || leadingStack.top().second <= lead) {
        leadingStack.push(make_pair(gameRound, lead));
      }
    }

    if (count == tries) {
      count = 0;
      count2++;
      if (!(count2 % 4)) {
        random_shuffle(step, step+6);
        tries = step[0];
      }
      dir++;      
      if (dir == 4) dir = 0;
    }

    int goalX = -1, goalY;
    int initdir = dir;
    do {
      int nx = me.x + dx[dir];
      int ny = me.y + dy[dir];
      if (isValid(nx, ny)) {
        if (grid[ny][nx] == '.') {
          goalX = nx, goalY = ny;
        }
      }
      if (goalX == -1) {
        dir++;
        count = 0;
        if (dir == 4) dir = 0;
      } else count++;      
    } while ((goalX == -1) && (initdir != dir));

    if (goalX == -1) {
      random_shuffle(step, step+6);
      for (int cdir = 0; cdir < 4; ++cdir) {
        int nx = me.x + step[0]*dx[cdir];
        int ny = me.y + step[0]*dy[cdir];
        if (isValid(nx, ny)) {
          if (grid[ny][nx] == '.') {
            goalX = nx, goalY = ny;
          }
        }
      }
    }

    vector<pair<int,int>> candidates;
    if (goalX == -1) {
      for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 35; ++j) {
          if (grid[i][j] == '.') {
            candidates.push_back(make_pair(j,i));
            int need = me.distance_to(j,i);
            int beat = 0;
            for (int o = 0; o < opponentCount; ++o) {              
              int oneed = opponent[o].distance_to(j,i);
              if (need < oneed) beat++;
            }
            if (beat == opponentCount) {
              goalX = j;
              goalY = i;
            }
          }
        }
      }
    }

    if (goalX == -1) {
      if (candidates.size()) {
        random_shuffle(candidates.begin(), candidates.end());
        goalX = candidates[0].first;
        goalY = candidates[0].second;
      }
    }

    if (goalX == -1) goalX = me.x, goalY = me.y;

    cout << goalX << ' ' << goalY << endl;
  }
}
