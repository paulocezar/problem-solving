#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#define INF 0x3f3f3f3f3f3f3f3fll

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	long long n, bl, br, area, barea;
	cin >> t;
	while(t--){
		barea = INF;
		cin >> n;
		n = (n+4)/5;
		
		long long lim = (long long)ceil(sqrt(n));
		
		for(long long l = 1; l <= lim; l++){
			long long r = (n + l - 1)/l;
			
			area = (44*l + 4) * (10*r + 2);
			//cout << l << " " << r << " " << area << endl;
			if(area < barea){
				barea = area;
				bl = l;
				br = r;
			}
			else if(area == barea){
				if( fabs( (44*l + 4) - (10*r + 2) ) < fabs( (44*bl + 4) - (10*br + 2) ) ){
					bl = l;
					br = r;
				} 
			}
			
			//inverte dimensoes
			area = (44*r + 4) * (10*l + 2);
			//cout << r << " " << l << " " << area << endl;
			
			if(area < barea){
				barea = area;
				bl = r;
				br = l;
			}
			else if(area == barea){
				if( fabs( (44*r + 4) - (10*l + 2) ) < fabs( (44*bl + 4) - (10*br + 2) ) ){
					bl = r;
					br = l;
				} 
			}
		}
		long long x = (44*bl + 4);
		long long y = (10*br + 2);
		cout << max(x, y) << " X " << min(x, y) << " = " << barea << "\n";
	}	
	return 0;
}
