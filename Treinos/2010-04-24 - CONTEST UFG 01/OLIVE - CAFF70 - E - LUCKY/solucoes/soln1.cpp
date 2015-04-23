// First submission of the contest by https://www.spoj.pl/KOPC09/users/yazhini/
#include <iostream>
using namespace std;
#define GI ({int t;scanf("%d",&t);t;})
int main() {
  int t = GI;
  while (t--) {
    int N = GI;
    long long p = 5;
    long long sum = 0;
    while (N) {
      sum += (N&1)?p:0;
      N >>= 1;
      p *= 5;
    }
    cout << sum << endl;
  }
}
