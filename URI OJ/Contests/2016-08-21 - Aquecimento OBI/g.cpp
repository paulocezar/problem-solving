#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int SQMP = 1<<9;
const int MAXP = 1<<18;

bitset< MAXP > bs;
vector<int> primes;

void sieve(){
  for (int i = 1; i < MAXP; ++i) bs[i] = i & 1;
  bs[1] = false;
  bs[2] = true;

  for (int i = 3; i <= SQMP; i+=2) if (bs[i]) {
    for (int j = i*i; j <= MAXP; j+=i) {
      bs[j] = false;
    }
  }

  for (int i = 1; i <= MAXP; ++i) if (bs[i]) {
    primes.push_back(i);
  }
}



int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);

  int w;
  cin >> w;

  sieve();
  auto it = lower_bound(primes.begin(), primes.end(), w);
  int speed = 0;
  int need = 10;
  while (need--) {
    speed += *it;
    it++;
  }

  int dist = 6e7;
  cout << speed << " km/h\n";

  int hours = dist / speed;
  cout << hours << " h / " << (hours/24) << " d\n";

  return 0;
}
