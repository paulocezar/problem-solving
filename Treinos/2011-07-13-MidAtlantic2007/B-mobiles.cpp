#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<pair<int, double> > ans;

char next(){
	char c;
	c = cin.get();
	while( c != '(' && c != ')' && c != 'D' && c != 'B' ) c = cin.get();
	return c;
}
double solve(char op)
{

	if (op == 'B') {
		int num;
		double len;
		double w1, w2;
		char c;
		cin >> num >> len;
		
		c = next(); c = next();
		w1 = solve( c );
		c = next(); c = next();
		w2 = solve( c );
		c = next();
		double b = (len*w1)/(w1+w2);
		double a = len-b;
		ans.push_back( make_pair( num, min(a,b)) );
		return w1+w2;
	} else {
		char c;
		double w1;
		cin >> w1;
		c = next();
		return w1;
	}
}

int main(){
	
	char c;
	c = next(); c = next();
	
	while( c != ')' ){
		ans.clear();
		
		solve( c );
		sort( ans.begin(), ans.end() );
		
		for( size_t i = 0, s = ans.size(); i < s; i++ ) 
			cout << "Bar " << ans[i].first << " must be tied " << fixed << setprecision(1) << ans[i].second << " from one end.\n"; 

		c = next();
		c = next();
	}

	return 0;
}

