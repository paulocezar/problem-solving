#include <map>
#include <set>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof( (X).begin() )
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for( int i = a; i <= b; ++i)
#define RFOR(i, b, a) for( int i = b; i >= a; --i)
#define REP(i, N) for( int i = 0; i < N; ++i)
#define RREP(i, N) for( int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int lin, col;

string board[20];
map<char, pair<int, int> > pos;
char vet[30];

int mat[30][30];
int visited[30][30];
double cost[30][30], c2[30][30];
int paths[30][30];

int main( int argc, char* argv[] ){
	
	//ios::sync_with_stdio( false );
	
	while (cin >> col >> lin) {
		int qtd = 0;
		pos.clear();
		
		for (int i = 0; i < lin; ++i) {
			cin >> board[i];
			
			for (int j = 0; j < col; ++j) {
				if (board[i][j] <= 'O' && board[i][j] >= 'A') {
					pos[board[i][j]] = MP(i, j);
					vet[qtd++] = board[i][j];
				}
				
				cost[i][j] = .0;
			}
		}
		
		char orig, dest;
		int num;
		
		cin >> orig >> dest >> num;
		while (orig != 'X' || dest != 'X') {
			memset(mat, -1, sizeof(mat));
			
			// custo, x, y
			queue< pair<int, pair<int, int> > > q;
			q.push(MP(0, MP(pos[orig].first, pos[orig].second)));
			
			//mat[pos[orig].first][pos[orig].second] = 0;
			
			int x, y, c;
			while (!q.empty()) {
				x = q.front().second.first;
				y = q.front().second.second;
				c = q.front().first;
				q.pop();
				
				if (mat[x][y] == -1) {
					mat[x][y] = c;
				}
				else continue;
				
				if (x == pos[dest].first && y == pos[dest].second) break;
				
				if (x > 0 && board[x-1][y] != 'X') {
					q.push(MP(c+1, MP(x-1, y)));
				}
				
				if (y > 0 && board[x][y-1] != 'X') {
					q.push(MP(c+1, MP(x, y-1)));
				}
				
				if (y < col-1 && board[x][y+1] != 'X') {
					q.push(MP(c+1, MP(x, y+1)));
				}
				
				if (x < lin-1 && board[x+1][y] != 'X') {
					q.push(MP(c+1, MP(x+1, y)));
				}
			}
			
			//for (int i = 0; i < lin; ++i) {
			//	for (int j = 0; j < col;++j) cout << mat[i][j] << " ";
			//	cout << endl;
			//}
			//cout << endl;
			
			memset(paths, 0, sizeof(paths));
			
			queue<pair<int, int> > qq;
			qq.push(MP(pos[dest].first, pos[dest].second));
			
			paths[pos[dest].first][pos[dest].second] = 1;
			while (!qq.empty()) {
				x = qq.front().first;
				y = qq.front().second;
				qq.pop();
				
				if (x == pos[orig].first && y == pos[orig].second) continue;
				
				if (x > 0 && mat[x-1][y] == mat[x][y] - 1) {
					if (paths[x-1][y] == 0) qq.push(MP(x-1, y));
					paths[x-1][y] += paths[x][y];
				}
				
				if (y > 0 && mat[x][y-1] == mat[x][y] - 1) {
					if (paths[x][y-1] == 0) qq.push(MP(x, y-1));
					paths[x][y-1] += paths[x][y];
				}
				
				if (y < col-1 && mat[x][y+1] == mat[x][y] - 1) {
					if (paths[x][y+1] == 0) qq.push(MP(x, y+1));
					paths[x][y+1] += paths[x][y];
				}
				
				if (x < lin-1 && mat[x+1][y] == mat[x][y] - 1) {
					if (paths[x+1][y] == 0) qq.push(MP(x+1, y));
					paths[x+1][y] += paths[x][y];
				}
			}
			
			x = pos[orig].first;
			y = pos[orig].second;
			
			qq.push(MP(x, y));
			
			for (int i = 0; i < lin; ++i) for (int j = 0; j < col; ++j) c2[i][j] = .0;
			
			c2[x][y] = num;
			
			while (!qq.empty()) {
				x = qq.front().first;
				y = qq.front().second;
				qq.pop();
				
				//cout << "c2[" << x << "][" << y << "] = " << c2[x][y] << endl;
				
				if (x > 0 && mat[x-1][y] == mat[x][y] + 1) {
					if (paths[x-1][y] > 0) { qq.push(MP(x-1, y)); paths[x-1][y] *= -1; }
					
					c2[x-1][y] += ((ABS(paths[x-1][y]) / ABS(double(paths[x][y])))) * c2[x][y];
				}
				
				if (y > 0 && mat[x][y-1] == mat[x][y] + 1) {
					if (paths[x][y-1] > 0) { qq.push(MP(x, y-1)); paths[x][y-1] *= -1; }
					
					
					c2[x][y-1] += ((ABS(paths[x][y-1]) / ABS(double(paths[x][y])))) * c2[x][y];
				}
				
				if (y < col-1 && mat[x][y+1] == mat[x][y] + 1) {
					if (paths[x][y+1] > 0) { qq.push(MP(x, y+1)); paths[x][y+1] *= -1; }
					
					c2[x][y+1] += ((ABS(paths[x][y+1]) / ABS(double(paths[x][y])))) * c2[x][y];
				}
				
				if (x < lin-1 && mat[x+1][y] == mat[x][y] + 1) {
					if (paths[x+1][y] > 0) { qq.push(MP(x+1, y)); paths[x+1][y] *= -1; }
					
					c2[x+1][y] += ((ABS(paths[x+1][y]) / ABS(double(paths[x][y])))) * c2[x][y];
				}
			}
			
			c2[pos[orig].first][pos[orig].second] = c2[pos[dest].first][pos[dest].second] = .0;
			
			for (int i = 0; i < lin; ++i) for (int j = 0; j < col; ++j) cost[i][j] += c2[i][j];
			
			cin >> orig >> dest >> num;
		}
		
		for (int i = 0; i < lin; ++i) { 
			for (int j = 0; j < col; ++j) { printf(" %6.2lf", cost[i][j]); }
			cout << '\n';
		}
		
	}
	
	return 0;
}











