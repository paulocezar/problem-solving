#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int mat[22][22][2];
int chg[16];

char res[4] = {'.', '!', 'X', '#'};

int main(){
	ios::sync_with_stdio(false);
	int t, days;
	bool first = true;
	memset(mat, 0, sizeof(mat));
	cin >> t;
	while(t--){
		cin >> days;
		for(int i = 0; i < 16; i++){
			cin >> chg[i];
		}
		
		for(int i = 0; i < 20; i++){
			for(int j = 0; j < 20; j++){
				cin >> mat[i+1][j+1][0];
			}
		}
		
		int act = 0, oth = 1;
		while(days--){
			for(int i = 1; i <= 20; i++){
				for(int j = 1; j <= 20; j++){
					int sum = mat[i-1][j][act] + mat[i+1][j][act] + mat[i][j][act] + mat[i][j+1][act] + mat[i][j-1][act];
					mat[i][j][oth] = mat[i][j][act] + chg[sum];
					if(mat[i][j][oth] < 0) mat[i][j][oth] = 0;
					if(mat[i][j][oth] > 3) mat[i][j][oth] = 3;
				}
			}
			
			act = 1 - act;
			oth = 1 - oth;
		}
		
		if(first) first = false;
		else{
			cout << "\n";
		}
		
		for(int i = 1; i <= 20; i++ ){
			for(int j = 1; j <= 20; j++){
				cout << res[mat[i][j][act]];
			}
			cout << "\n";
		}
	}
	
	return 0;
}