#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

#define MAXN 100000

using namespace std;

int tree[MAXN+1];
int vet[MAXN+1];
int MAX, k;

typedef pair< int, int > par;

long long read( int idx ){
	long long sum = 0;
	idx++;
	while( idx > 0 ){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update( int idx ){
	idx++;
	while (idx <= MAX ){
		tree[idx]++;
		idx += (idx & -idx);
	}
}

int main(){
    
    int t;
    int n;
    int i, j, s, l;
    long long swap;
    int ind, el, dist;
    
	priority_queue< par > heap;
	
    scanf("%d", &t );
    while( t-- ){
		
		scanf("%d %d", &n, &k );
		
		for( i = 0; i < n; i++ )
			scanf("%d", vet+i );
		
		swap = 0;

		for( i = 0; i < k; i++ ){
			
			l = 0;
			for( j = i; j < n; j+= k, l++ ){
				heap.push( make_pair( -vet[j], -l ) );
			}
			
			for( j = 0; j <= l; j++ ) tree[j] = 0;
			MAX = l;
			
			s = 0;
			while( !heap.empty() ){
				
				el = -heap.top().first;
				ind = -heap.top().second;
				
				heap.pop();
				update( ind );
				s++;
				dist = s - read( ind );
				
				swap += ( ind + dist - s + 1 );
				vet[(s-1)*k + i] = el;
			}
			
		}
		
		for( i = 1; i < n; i++ ) if( vet[i] < vet[i-1] ){
			
			swap = -1;
			break;
		}
		
		if( swap < 0 ) printf("impossivel\n");
		else  printf("%lld\n", swap );
              
    }    

    return 0;
}
