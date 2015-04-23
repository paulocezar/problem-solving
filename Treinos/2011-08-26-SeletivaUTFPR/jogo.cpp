#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

string board[3];

char ganha()
{
	if (board[0][0] != '.' && board[0][0] == board[0][1] && board[0][0] == board[0][2]) {
		return board[0][0];
	}
	if (board[1][0] != '.' && board[1][0] == board[1][1] && board[1][0] == board[1][2]) {
		return board[1][0];
	}
	if (board[2][0] != '.' && board[2][0] == board[2][1] && board[2][0] == board[2][2]) {
		return board[2][0];
	}
	if (board[0][0] != '.' && board[0][0] == board[1][0] && board[0][0] == board[2][0]) {
		return board[0][0];
	}
	if (board[0][1] != '.' && board[0][1] == board[1][1] && board[0][1] == board[2][1]) {
		return board[0][1];
	}
	if (board[0][2] != '.' && board[0][2] == board[1][2] && board[0][2] == board[2][2]) {
		return board[0][0];
	}
	
	if (board[0][0] != '.' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
		return board[0][0];
	}
	
	if (board[2][0] != '.' && board[1][1] == board[2][0] && board[2][0] == board[0][2]) {
		return board[2][0];
	}
	
	return -1;
}

int main(){
	
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	
	while( t-- ){
		cin >> board[0] >> board[1] >> board[2];
		
		int o = 0, x = 0;
		
		for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
			if (board[i][j] == 'X') x++;
			else if (board[i][j] == 'O') o++;
		}
		
		char who = ganha();
		
		if (who == 'X') {
			if (x == o + 1) cout << "sim\n";
			else cout << "nao\n";
		}
		else if (who == 'O') {
			if (x == o) cout << "sim\n";
			else cout << "nao\n";
		}
		else {
			if (x == o || x == o + 1) cout << "sim\n";
			else cout << "nao\n";
		}
	}
	
	return 0;
}
