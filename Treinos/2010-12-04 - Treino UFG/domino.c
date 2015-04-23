#include <stdio.h>

int main(){
	int t,a,b,c,d,i;
	int dx,dy;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Cenario #%d:\n",i);
		scanf("%d %d %d %d",&a,&b,&c,&d);
		dx=a-c;
		if(dx<0) dx=-dx;
		dy=b-d;
		if(dy<0) dy=-dy;
		
		if(dx%2 == dy%2) printf("0\n\n");
		else printf("1\n\n");
	}
	return 0;
}
