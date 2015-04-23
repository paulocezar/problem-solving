#include <iostream>
#include <cstring>

using namespace std;

bool dp[32][5][5][5][5][5][5];
int cards[7];

void play(){
	int val, rem;
	memset( dp, false, sizeof(dp) );
	for( val = 1; val < 32; val++ )
	for( cards[1] = 0; cards[1] < 5; cards[1]++ )
	for( cards[2] = 0; cards[2] < 5; cards[2]++ )
	for( cards[3] = 0; cards[3] < 5; cards[3]++ )
	for( cards[4] = 0; cards[4] < 5; cards[4]++ )
	for( cards[5] = 0; cards[5] < 5; cards[5]++ )
	for( cards[6] = 0; cards[6] < 5; cards[6]++ )
	for( rem = 1; rem < 7; rem++ ){
		if( cards[rem] && (val-rem) >= 0 ){
			cards[rem]--;
			if( !dp[val-rem][cards[1]][cards[2]][cards[3]][cards[4]][cards[5]][cards[6]] ){
				cards[rem]++;
				dp[val][cards[1]][cards[2]][cards[3]][cards[4]][cards[5]][cards[6]] = true;
				break;
			}
			cards[rem]++;							
		}				
	}
}

int main(){

	ios::sync_with_stdio( false );
	string game;
	bool win;
	int i, sum;
	
	play();
	
	while( cin >> game ){
		
		for( i = 1; i < 7; i++ ) cards[i] = 4;
		sum = 31;
		i = 0;
		
		while( game[i] ){
			sum -= (game[i]-'0');						
			cards[game[i]-'0']--;
			i++;
		}

		win = dp[ sum ][ cards[1] ][ cards[2] ][ cards[3] ][ cards[4] ][ cards[5] ][ cards[6] ];
		
		if( i&1 ) win = !win;
		
		if( win ) cout << game << " A\n";
		else cout << game << " B\n";
		
	}
	
	return 0;
}
