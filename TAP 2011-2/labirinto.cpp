#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
#include <utility>
#include <queue>

using namespace std;

#define MXN 1001
#define INF 0x3F3F3F3F
#define DIRS 4

string gr[MXN];
int dist[MXN][MXN];
int ds[][2] = { {1,0},{0,1},{-1,0},{0,-1}  };

int main(){
	ios::sync_with_stdio(false);

	int L, C;
	while( cin >> L >> C && (L+C) ){
		for( int i = 0; i < L; i++ ){
			cin >> gr[i];
			for( int j = 0; j < C; j++ ) dist[i][j] = INF;
		}
		
		
		priority_queue< pair<int,int> > q;
		for( int i = 0; i < C; i++ ) if( gr[0][i] != '*' ){
			dist[0][i] = gr[0][i]-'0';
			q.push( make_pair(-dist[0][i], i) );
		}
		
		bool ok = false;
		while( !q.empty() ){
			int cst = -q.top().first;
			int i = q.top().second; q.pop();
			int j = i%1000;
			i /= 1000;
			if( cst > dist[i][j] ) continue;
			if( i == L-1 ){
				cout << cst << "\n";
				ok = true;
				break;
			}
			for( int dir = 0; dir < DIRS; dir++ ){
				int ni = i+ds[dir][0];
				int nj = j+ds[dir][1];
				if( ni >= 0 && ni < L && nj >= 0 && nj < C ){
					if( gr[ni][nj] != '*' ){
						int ncst = cst+gr[ni][nj]-'0';
						if( ncst < dist[ni][nj] ){
							q.push( make_pair(-ncst, 1000*ni + nj ) );
							dist[ni][nj] = ncst;
						}
					}
				}
			}
		}
		if( !ok ) cout << "impossivel\n";

	}

	return 0;
}

