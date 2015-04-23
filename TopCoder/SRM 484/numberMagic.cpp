#include <string>

using namespace std;

struct NumberMagicEasy {
	
	int theNumber(string answer){
		int number = 0;
		if( answer[0] == 'N' ) number += 8;
		if( answer[1] == 'N' ) number += 4;
		if( answer[2] == 'N' ) number += 2;
		if( answer[3] == 'N' ) number += 1;
		return number+1;
	}
	
};