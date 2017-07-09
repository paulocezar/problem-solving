#include <bits/stdc++.h>

using namespace std;

unordered_map<string, set<int>> released, in_use;

regex name_pattern("([a-z]+)\\(([0-9]+)\\)");


string create(string &name) {
  int id = in_use[name].size();
  if (released[name].size()) {
    id = *released[name].begin();
    released[name].erase(id);
  }

  in_use[name].insert(id);
  string actual_name = name;

  if (id) {
    actual_name += "(" + to_string(id) + ")";
  }

  return actual_name;
}

void remove(string &name) {
  int id = 0;
  smatch base_match;
  if (regex_match(name, base_match, name_pattern)) {
    name = base_match[1].str();
    id = stoi(base_match[2].str());
  }
  in_use[name].erase(id);
  released[name].insert(id);
}

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int q;
  cin >> q;

  string cmd, name1, name2;
  while (q--) {
    cin >> cmd >> name1;
    switch (cmd[0]) {
      case 'c':
        cout << "+ " << create(name1) << "\n";
        break;
      case 'd':
        cout << "- " << name1 << "\n";
        remove(name1);
        break;
      case 'r':
        cin >> name2;
        cout << "r " << name1;
        remove(name1);
        cout << " -> "  << create(name2) << "\n";
        break;
    }
  }

  return 0;
}
