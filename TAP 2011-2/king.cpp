#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int hand[3];
	
play:

	for( int i = 0; i < 3; i++ ) cin >> hand[i];
	if( hand[0]+hand[1]+hand[2] ){
		sort( hand, hand+3 );
		
		int matched = 1;
		if( hand[0] == hand[1] ) matched++;
		if( hand[1] == hand[2] ) matched++;
		
		if( matched == 1 ) cout << "1 1 2\n";
		else if( matched == 2 ){
			
			int same = (hand[0]==hand[1])?(hand[0]):(hand[1]);
			int unmatched = (hand[0]==hand[1])?(hand[2]):(hand[0]);
			
			if( unmatched == 13 ){
				hand[0] = hand[1] = same+1;
				hand[2] = 1;
			} else {
				if( unmatched+1 == same ){
					if( unmatched+2 <= 13 ){
						hand[0] = hand[1] = same;
						hand[2] = unmatched+2;
					} else {
						hand[0] = hand[1] = hand[2] = 1;
					}
				} else {
					hand[0] = hand[1] = same;
					hand[2] = unmatched+1;
				}
			}
			
			sort( hand, hand+3 );
			cout << hand[0] << " " << hand[1] << " " << hand[2] << "\n";
		
		} else {
			if( hand[0] == 13 ) cout << "*\n";
			else cout << hand[0]+1 << " " << hand[0]+1 << " " << hand[0]+1 << "\n";
		}
		
		goto play;
	}
	
	return 0;
}
