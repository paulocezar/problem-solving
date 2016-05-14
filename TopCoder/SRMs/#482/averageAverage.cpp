#include <vector>

using namespace std;

struct AverageAverage{
	
	
	double average(vector <int> numList){
		
		int n = numList.size();
		int i, act, sum, mask = 0;
		double totalSum = 0.0;
		
		for( mask = 1; mask < (1<<n); mask++ ){
			sum = 0; act = 0;
			for( i = 0; i < n; i++ ){
				if( mask & (1<<i) ) { sum += numList[i]; act++; }
			}
			totalSum += (double)sum/(double)act;
		}
		
		return totalSum/(double)((1<<n) - 1);
	}
	
};