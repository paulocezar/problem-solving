#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
#include <list>

#define REP( i, a ) for( int i = 0; i < a; i++ )
#define pb push_back

using namespace std;

struct st { int lin, col, peng, jump; };
st vet[101];

int visited[300];
int path[300];
int vis;
int N;
int mini;

int g[300][300], g2[300][300];

const int INF = 0x3f3f3f3f;
const double EPS = 10e-9;

double dist(int i, int j)
{
	return (vet[i].col - vet[j].col) * (vet[i].col - vet[j].col) +
		(vet[i].lin - vet[j].lin) * (vet[i].lin - vet[j].lin);
}

bool flow(int v, int end, int lvl = 0)
{
	visited[v] = 1;
	path[lvl] = v;
	
	if (v == end) { path[lvl+1] = -1; visited[v] = 0; return true; }
	
	for (int i = 0; i < N; ++i) {
		if (!visited[i] && g2[v][i]) {
			if (flow(i, end, lvl + 1)) { 
				mini = min(mini, g2[v][i]); 
				visited[v] = 0;
				return true;
			}
		}
	}
	
	visited[v] = 0;
	
	return false;	
}

int max_flow(int ini, int fim)
{
	int last;
	int ans = 0;
	
	mini = 0x3f3f3f3f;
	while (flow(ini, fim)) {
		
		last = ini;
		for (int i = 1; path[i] != -1; ++i) {
			g2[last][path[i]] -= mini;
			g2[path[i]][last] += mini;
			
			last = path[i];
		}
		
		ans += mini;
		
		mini = 0x3f3f3f3f;
	}
	
	return ans;
}

int main()
{
	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	
	int n;
	double d;
	int qtd_peng;
	
	memset(visited, 0, sizeof(visited));
	while(t--) {
		cin >> n >> d;
		
		d *= d;
		
		N = 2 * n + 1;
		
		qtd_peng = 0;
		REP( i, N ) REP( j, N ) g[i][j] = 0;
		
		int shit = 0;
		for (int i = 0; i < n; ++i) {
			cin >> vet[i].lin >> vet[i].col >> vet[i].peng >> vet[i].jump;
			if( vet[i].peng > vet[i].jump ) shit++;
			qtd_peng += vet[i].peng;
		}
		
		if( shit >= 2 ) cout << "-1\n";
		else{
		
		
		for (int i = 0; i < n; ++i) {
			//liga os nos i com os imaginarios (n+i)
			g[i][n+i] = vet[i].jump;
			
			for (int j = i + 1; j < n; ++j) {
			
				// se a distancia de i e j é menor que d, liga
				//	os imaginarios de um no original do
				//	outro.
				if (dist(i, j) - d <= EPS) {
					g[n+i][j] = INF;
					g[n+j][i] = INF;
				}
			}
		}
		
		// 2*n é a superorigem, ligando com capacidade nº de pinguins
		for (int i = 0; i < n; ++i) {
			g[2*n][i] = vet[i].peng;
		}
		
		bool imp = true;
		if( shit == 0 ){
			for (int i = 0; i < n; ++i) {
				
				REP( x, N ) REP( y, N ) g2[x][y] = g[x][y];
			
				if (max_flow(2*n, i) == qtd_peng) {
					if (imp) { imp = false; }
					else cout << ' ';
				
					cout << i;
				}
			}
		} else {
			for( int i = 0; i < n; ++i ) if( vet[i].peng > vet[i].jump ){
				REP( x, N ) REP( y, N ) g2[x][y] = g[x][y];
				if (max_flow(2*n, i) == qtd_peng){
					cout << i;
					imp = false;
				}
				break;
			}
		}
		if (imp) cout << "-1\n";
		else cout << "\n";
		}
	}
	
	
	return 0;
}
