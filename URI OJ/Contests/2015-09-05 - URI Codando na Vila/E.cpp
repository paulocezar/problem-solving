#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


map<string, int> ctv = {{"VERMELHO", 0}, {"LARANJA", 1}, {"VERDE", 2}, {"AZUL", 3}};
int bad[4] = {1, 3, 0, 2};

class cilindro_t
{
public:
	cilindro_t() {}
	cilindro_t(int &hh, int &rr, string &cc) {
		h = hh;
		r = rr;
		c = ctv[cc];
	}

	int h, r, c;

	bool check(const cilindro_t &other) {
		return (r < other.r) && (other.c != bad[c]);
	}

	bool operator < (const cilindro_t &other) const {
		if (r != other.r) return r > other.r;
		if (h != other.h) return h > other.h;
		return c < other.c;
	}
};

cilindro_t cilindro[1024];
int best[1024];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, hh, rr;
    string cc;
    while (cin >> N && N) {

    	for(int i = 0; i < N; ++i) {
    		cin >> hh >> rr >> cc;
    		cilindro[i] = cilindro_t(hh,rr,cc);
    	}

    	sort(cilindro, cilindro + N);

    	memset(best, 0, sizeof(best));
    	int res = 0;
    	for (int i = 0; i < N; ++i) {
    		int mx = 0;
    		for (int j = i-1; j >= 0; --j) {
    			if (cilindro[i].check(cilindro[j])) mx = max(mx, best[j]);
    		}
    		mx += cilindro[i].h;
    		best[i] = mx;
    		res = max(res, best[i]);
    	}
    	cout << res << " centimetro(s)\n";
    }

	return 0;
}

















