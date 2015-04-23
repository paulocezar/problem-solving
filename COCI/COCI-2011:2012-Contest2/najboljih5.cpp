#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdlib>

using namespace std;

int val[8];
int id[8];

int comp2( const void* a, const void* b ){
	return  *(int*)a  -  *(int*)b;
}
int comp( const void* a, const void* b ){
	return val[ *(int*)b ] - val[ *(int*)a ];
}

int main(){
	ios::sync_with_stdio(false);
	for( int i = 0; i < 8; i++ ){
		cin >> val[i];
		id[i] = i;
	}
	qsort( id, 8, sizeof(int), comp );
	int score = 0;
	for( int i = 0; i < 5; i++ ) score += val[id[i]];
	cout << score << "\n";
	qsort( id, 5, sizeof(int), comp2 );
	for( int i = 0; i < 5; i++ ){
		if( i ) cout << " ";
		cout << id[i]+1;
	}
	cout << "\n";
	return 0;
}

