#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int t[1024], s[1024], f[1024], r[1024];

bool intersect(int li, int ri, int lj, int rj) {
	if ((ri < lj) || (li > rj)) return false;
	return true;
}

bool meet(int i, int j) {
	int diri = (s[i] < f[i]) ? +1 : -1;
	int dirj = (s[j] < f[j]) ? +1 : -1;

	if (diri == dirj) {
		int sgn = -1;
		int disti = f[i]-s[i];
		int distj = f[j]-s[j];
		if (diri == -1) sgn *= -1, disti *= -1, distj *= -1;
		return ((s[i]+sgn*t[i]) == (s[j]+sgn*t[j])) && intersect(t[i], t[i]+disti, t[j], t[j]+distj);	
		
	} else {
		if (diri == -1) { swap(i, j); }
		int tt = (s[j]+t[j]-s[i]+t[i])/2;
		int pos = s[i] + (tt-t[i]);
		return ((tt > 0) && (s[i] <= pos && pos <= f[i]) && (f[j] <= pos && pos <= s[j]));
	}

	return false;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
    	cin >> t[i] >> s[i] >> f[i];
    	t[i] <<= 1;
    	s[i] = (s[i]<<1) - 1;
    	f[i] = (f[i]<<1) - 1;
    }

    for (int i = 0; i < n; ++i) {
    	for (int j = i+1; j < n; ++j) {
    		if (meet(i, j)) r[i]++, r[j]++;
    	}
    }

    cout << r[0];
    for (int i = 1; i < n; ++i) {
    	cout << " " << r[i];
    }
    cout << "\n";




	return 0;
}
