#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define MAXDIM 1001
#define INF 0x3F3F3F3F

struct pos {
	int x, y;
	pos( int xx = 0, int yy = 0 ) : x(xx), y(yy) {}
};

int N, X, Y;
int xs, ys, xt, yt;

int dist[MAXDIM][MAXDIM];
int cost[MAXDIM][MAXDIM];


int ds[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool good( int i, int j ){ return ( (i>=0) && (i<X) && (j>=0) && (j<Y) ); }


bool ok( int allow ){
	
	if( dist[xs][ys] < allow ) return false;
	
	queue< pos > q;
	int xx, yy, nx, ny;
	
	for( xx = 0; xx < X; xx++ ) for( yy = 0; yy < Y; yy++ ) cost[xx][yy] = INF;
	
	q.push( pos( xs, ys ) );
	cost[xs][ys] = 0;
	
	while( !q.empty() ){
		
		xx = q.front().x;
		yy = q.front().y; q.pop();
		
		if( (xx == xt) && (yy == yt) ){ return true; }
			
		for( int i = 0; i < 4; i++ ){
			nx = xx+ds[i][0];
			ny = yy+ds[i][1];
			if( good( nx, ny ) && (cost[nx][ny] > cost[xx][yy]+1) && (dist[nx][ny] >= allow) ){
				cost[nx][ny] = cost[xx][yy]+1;
				q.push( pos(nx,ny) );
			} 
		}
	
	}
	
	return false;
}

int main(){

	ios::sync_with_stdio( false );
	
	int t, xx, yy;
		
	cin >> t;
	while( t-- ){
	
		cin >> N >> X >> Y;	
		cin >> xs >> ys >> xt >> yt;
		
		for( int i = 0; i < X; i++ ) for( int j = 0; j < Y; j++ ) dist[i][j] = INF;

		queue< pos > q;
		while( N-- ){
			cin >> xx >> yy;
			dist[xx][yy] = 0;
			q.push( pos( xx, yy ) );
		}		
		
		int HI = 1;
		
		while( !q.empty() ){
			xx = q.front().x;
			yy = q.front().y; q.pop();
			
			HI = max( HI, dist[xx][yy] );
				
			for( int i = 0; i < 4; i++ ){
				int nx = xx+ds[i][0];
				int ny = yy+ds[i][1];
				if( good( nx, ny ) && (dist[nx][ny] > dist[xx][yy]+1) ){
					dist[nx][ny] = dist[xx][yy] + 1;
					q.push( pos(nx,ny) );
				} 
			}	
		}
		
		int aans = -1, ans = -1;
		
		int LO = 0;

		while( LO <= HI ){
			int mid = (LO+HI)/2;
			if( ok( mid ) ){
				ans = mid;
				aans = cost[xt][yt];
				LO = mid+1;
			} else HI = mid-1;
		}
		
		cout << ans << " " << aans << "\n";
	}
	return 0;
	
}

