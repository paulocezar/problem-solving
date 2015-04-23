#include<stdio.h>
#include<stdlib.h>

#define MAXN 10010

int p[MAXN], o[MAXN], r[MAXN];

int find(int i) 
{
  if (p[i] == i) return i;
  return p[i] = find(p[i]);
}

void link(int i, int j) 
{
  if (r[i] < r[j]) link(j, i);
  else if (i != j) {
    p[j] = i;
    o[i] += o[j];
    if (r[i] == r[j]) ++r[i];
  }
}

int main(){
	
	int tests, i, n, m, x, y, ok=1;  
	
	scanf("%d", &tests );
	while( tests-- ){
		
		scanf("%d %d", &n, &m);
		for( i = 0; i <n; i++ )
			 r[i] = 0, p[i] = i;
		ok = 1;
		
		for (i = 0; i < n; ++i) scanf("%d", &o[i] );
		
		while( m-- ){
			scanf("%d %d", &x, &y);
			link(find(x), find(y));
		}
		for (i = 0; ok && i < n; ++i) ok = !(p[i] == i && o[i]);
		
		printf("%sPOSSIVEL\n", ok ? "" : "IM");

	}
	return 0;
}
