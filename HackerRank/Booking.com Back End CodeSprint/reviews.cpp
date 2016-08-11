#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

string passions[128];
map<int, int> reviewer_scores[128];

int64 june15 = 1465948800LL;
int64 july15 = 1468540800LL;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> passions[i];
    for (char &c : passions[i]) c = tolower(c);
  }
  for (int i = 0; i < m; ++i) {
    int id; int64 timestamp;
    cin >> id >> timestamp;
    string body;
    cin.ignore(); getline(cin, body);
    for (char &c : body) c = tolower(c);
    int review_score = 0;

    if (june15 <= timestamp && timestamp <= july15) review_score += 20;
    else review_score += 10;

    if (body.size() >= 100) review_score += 20;
    else review_score += 10;

    for (int j = 0; j < n; ++j) {
      if (body.find(passions[j]) != string::npos) reviewer_scores[j][id] += review_score;
    }
  }

  for (int i = 0; i < n; ++i) {
    int best = -1, bid = -1;
    for (auto &ntry : reviewer_scores[i]) {
      if (ntry.second > best) {
        best = ntry.second;
        bid = ntry.first;
      }
    }
    cout << bid << "\n";
  }


  return 0;
}
