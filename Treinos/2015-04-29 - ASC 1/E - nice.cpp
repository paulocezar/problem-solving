#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

void divbytwo(string &num) {
    int c = 0;
    for (auto ch = num.rbegin(); ch != num.rend(); ++ch) {
        int v = 10*c + (*ch - '0');
        *ch = (v/2) + '0';
        c = v % 2;
    }
    while (num.back() == '0') num.pop_back();
}

void minusone(string &num) {
    for (auto &ch : num) {
        if (ch >= '1') { ch--; break; }
        ch = '9';
    }
    while (num.back() == '0') num.pop_back();
}

#define MAXD 32

int64 MOD;
int64 aux[MAXD][MAXD], ans[MAXD][MAXD], pot[MAXD][MAXD];
int dim;

void mult(int64 a[][MAXD], int64 b[][MAXD]) {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            aux[i][j] = 0LL;
            for (int x = 0; x < dim; ++x) {
                aux[i][j] = (aux[i][j] + ((a[i][x] * b[x][j])% MOD ))%MOD;
            }
        }
    }
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            a[i][j] = aux[i][j];
        }
    }
}

int match(int i, int j, int len) {
    for (int bit = 0; bit+1 < len; ++bit) {
        int sum = ((i>>bit) & 1) + ((j>>bit)&1) + ((i>>(bit+1))&1) + ((j>>(bit+1))&1);
        if (sum == 0 || sum == 4) return 0; 
    }
    return 1;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    ifstream fin("nice.in");
    ofstream fout("nice.out");
    
    string N;
    int M;
    
    fin >> N >> M >> MOD;
    dim = 1<<M;
    reverse(N.begin(), N.end());
    minusone(N);
    
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            ans[i][j] = (i==j) ? 1 : 0;
            pot[i][j] = match(i, j, M);
        }
    }
    
    while (N.size()) {
        if (int(N[0]-'0') & 1) mult(ans, pot);
		mult(pot, pot);
        divbytwo(N);    
    }
    
    int64 res = 0;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            res += ans[i][j];
            res %= MOD;
        } 
    }
    fout << res << endl;

	return 0;
}

















