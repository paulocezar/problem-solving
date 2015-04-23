#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

	ios::sync_with_stdio( false );

	int n;
	string result;
	map< string, int >goal;
	map< string, int >::iterator it;
	
	goal.clear();

	cin >> n;
	for( int j = 0; j < n; j++ ){
		cin >> result;
		goal[result]++;
	}

	int max = -1;	
	it = goal.begin();
	while( it != goal.end() ){
		if( it->second > max ) { max = it->second; result = it->first; }
		it++;
	}
	
	cout << result << "\n";


	return 0;
}

