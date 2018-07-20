#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  set<pair<string,string>> outcomes;
  outcomes.emplace("scissors", "paper");
  outcomes.emplace("paper", "rock");
  outcomes.emplace("rock", "moon");
  outcomes.emplace("moon", "sun");
  outcomes.emplace("sun", "scissors");
  outcomes.emplace("scissors", "moon");
  outcomes.emplace("moon", "paper");
  outcomes.emplace("paper", "sun");
  outcomes.emplace("sun", "rock");
  outcomes.emplace("rock", "scissors");

  int t;
  cin >> t;
  while (t--) {
    string akira, hideki;
    cin >> akira >> hideki;

    if (outcomes.count({akira, hideki})) cout << "akira\n";
    else if (outcomes.count({hideki, akira})) cout << "hideki\n";
    else cout << "drew\n";
  }

  return 0;
}
