#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 1000000000
typedef long long int64;

void buildg();
int cap[35][35];
int parent[35];
bool seen[35];
bool graph[35][35];
void buildg();
int flow;

bool aug( int u ){
	if( u == 1 ) return true;
	seen[u] = true;

	for( int v = 0; v <= 33; v++ ) if( !seen[v] && cap[u][v] ){
		if( aug(v) ){
			parent[v] = u;
			flow = min( flow, cap[u][v] );
			seen[u] = false;
			return true;
		}
	}
	seen[u] = false;
	return false;
}

int64 maxflow(){
	int64 ans = 0;
	flow = INF;
	for( int i = 0; i < 35; i++ ) seen[i] = false;
	while( aug(0) ){
		ans += flow;
		int u = 1;
		while( u != 0 ){
			cap[parent[u]][u] -= flow;
			cap[u][parent[u]] += flow;
			u = parent[u];
		}
		flow = INF;
	}
	return ans;
}

int main(){
	int t;
	
	cin >> t;
	while( t-- ){
		buildg();
		for( int i = 2; i <= 16; i+=2 ) cin >> cap[i][i+1];
		for( int i = 18; i <= 32; i+=2 ) cin >> cap[i][i+1];
		cout << maxflow() << "\n";
	}

	return 0;
}

void buildg(){
	memset( cap, 0, sizeof(cap) );
	for( int i = 2; i <= 16; i+=2 ) cap[0][i] = INF;
	for( int i = 19; i <= 33; i+=2 ) cap[i][1] = INF;

	cap[3][18] = INF; // O- O-
	cap[3][20] = INF; // O- O+
	cap[5][20] = INF; // O+ O+

	cap[3][22] = INF; // O- A-
	cap[7][22] = INF; // A- A-
	cap[3][24] = INF; // O- A+
	cap[5][24] = INF; // O+ A+
	cap[7][24] = INF; // A- A+
	cap[9][24] = INF; // A+ A+
	

	cap[3][26] = INF; // O- B-
	cap[11][26] = INF; // B- B-
	cap[3][28] = INF; // O- B+
	cap[5][28] = INF; // O+ B+
	cap[11][28] = INF; // B- B+
	cap[13][28] = INF; // B+ B+
	
	cap[3][30] = INF; // O- AB-
	cap[7][30] = INF; // A- AB-
	cap[11][30] = INF; // B- AB-
	cap[15][30] = INF; // AB- AB-
	cap[3][32] = INF; // O- AB+
	cap[5][32] = INF; // O+ AB+
	cap[7][32] = INF; // A- AB+
	cap[9][32] = INF; // A+ AB+
	cap[11][32] = INF; // B- AB+
	cap[13][32] = INF; // B+ AB+
	cap[15][32] = INF; // AB- AB+
	cap[17][32] = INF; // AB+ AB+
}


