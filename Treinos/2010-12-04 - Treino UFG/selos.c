#include <stdio.h>

int main(){
	int t,i,x,y,z,aux;
	int total,amigos,soma;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Cenario #%d:\n",i);
		scanf("%d %d",&total,&amigos);
		int selos[amigos];
		for(x=0;x<amigos;x++){
			scanf("%d",&aux);
			for(y=0;y<x;y++){
				if(selos[y]<aux){
					for(z=x;z>=y;z--){
						selos[z+1]=selos[z];
					}
					break;
				}
			}
			selos[y]=aux;
		}
		soma=0;
		z=0;
		for(x=0;x<amigos;x++){
			if(soma>=total) break;
			soma+=selos[x];
			z++;
		}
		if(soma<total) printf("Impossivel\n\n");
		else printf("%d\n\n",z);
	}
	return 0;
}
