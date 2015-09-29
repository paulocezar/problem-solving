#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N;
    while (cin >> N && N) {
    	map<string, string> original;
    	string nome, assinatura;
    	for (int i = 0; i < N; ++i) {
    		cin >> nome >> assinatura;
    		original[nome] = assinatura;
    	}

    	int M, res = 0;
    	cin >> M;
    	while (M--) {
    		cin >> nome >> assinatura;
    		string &ax = original[nome];
    		int dif = 0;
    		for (int i = 0; i < ax.size(); ++i) dif += ((ax[i] != assinatura[i]) ? 1 : 0);
    		if (dif > 1) res++;
    	}
    	cout << res << "\n";
    }

	return 0;
}

















