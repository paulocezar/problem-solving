#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b){
	if(a.size() != b.size()) return a.size() < b.size();
	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i])
			return a[i] < b[i];
	}
	return false;
}

bool seen[100][100];

int main(){
	ios::sync_with_stdio(false);
	vector<vector<int> > vet;
	
	int tt, t, p;
	int u, v;
	
	cin >> tt;
	while(tt--){
		cin >> p >> t;
		vet.resize(p);
		
		for( int i = 0; i < p; i++ )
			for( int j = 0; j < t; j++ )
				seen[i][j] = false;
			
		while(cin >> u >> v && u+v){
			if( !seen[u-1][v-1] )
				vet[u-1].push_back(v-1);
			seen[u-1][v-1] = true;
		}
		
		for(int i = 0; i < p; i++)
			sort(vet[i].begin(), vet[i].end());
		
		
		sort(vet.begin(), vet.end() );
		vector<vector<int> >::iterator it = unique(vet.begin(), vet.end() );
		
		cout << (int)(it - vet.begin()) << "\n";
		
		vet.clear();
	}
	
	return 0;
}
