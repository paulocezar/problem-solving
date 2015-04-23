#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

const double PI  = acos(-1);
const double EPS = 1e-9;


struct PT{
	double x, y;
	double length(){return x*x + y*y;}
	
	PT operator - (PT a){
		PT r;
		r.x = x - a.x;
		r.y = y - a.y;
		return r;
	}
	
	PT operator + (PT a){
		PT r;
		r.x = x + a.x;
		r.y = y + a.y;
		return r;
	}
	
	
	PT operator * (double sc){
		PT r;
		r.x = x * sc;
		r.y = y * sc;
		return r;
	}
	
};

double trap(PT a, PT b){
	return (0.5 *(b.x - a.x)*(b.y + a.y));
}

double area(vector<PT> &vin){
	int n = vin.size();
	double ret = 0.0;
	for(int i = 0; i < n; i++){
		ret += trap(vin[i], vin[(i+1)%n]);
		//cout << ret << endl;
	}
	return fabs(ret);
}

int main(){
	ios::sync_with_stdio(false);
	
	int k;
	for(cin >> k; k ; cin >> k){
		vector<PT> pts(k);
		for(int i = 0; i < k; i++){
			cin >> pts[i].x >> pts[i].y;
		}
		if(k < 3){
			cout << "0\n";
		}
		else{
			cout << (int)(area(pts) + 0.5) << "\n";
		}
	}
	return 0;
}