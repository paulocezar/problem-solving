#include <fstream>
#include <string>
#include <utility>
#include <queue>

#define MAXN 2010
#define MAXM 2010

using namespace std;

bool burning[MAXN][MAXM];

int main(){

	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int N, M, i, j, k;
	
	fin >> N >> M;
	for( i = 1; i <= N; i++ )
		for( j = 1; j <= M; j++ )
			burning[i][j] = false;
	fin >> k;
	queue< pair< int, int > > q;
	while( k-- ){ 
		fin >> i >> j;
		burning[i][j] = true; q.push( make_pair( i, j ) );
	}	
	
	while( !q.empty() ){
	
		i = q.front().first; j = q.front().second; q.pop();
		
		if( i-1 && !burning[i-1][j] ) { 
			q.push( make_pair( i-1, j ) );
			burning[i-1][j] = true;
		}
		if( i+1<=N && !burning[i+1][j] ) { 
			q.push( make_pair( i+1, j ) );
			burning[i+1][j] = true;
		}
		if( j-1 && !burning[i][j-1] ) { 
			q.push( make_pair( i, j-1 ) );
			burning[i][j-1] = true;
		}
		if( j+1<=M && !burning[i][j+1] ) { 
			q.push( make_pair( i, j+1 ) );
			burning[i][j+1] = true;
		}
		
	}
		
	fout << i << " " << j << endl;
	
	return 0;
}