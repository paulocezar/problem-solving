#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    ifstream in("alex.in");
    ofstream out("alex.out");

    double h, w;
    in >> h >> w;

    double ans = min(h, w / 3.0);
    ans = max(ans, min(w, h / 3.0));
    ans = max(ans, min(w / 2.0, h / 2.0));

    out << fixed << setprecision(6) << ans << "\n"; 
	return 0;
}
