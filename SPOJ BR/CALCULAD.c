#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

double memoria[30];

char pilha[MAX];
char expressao[2*MAX];
char exp_rpn[4*MAX];
double values[MAX];

int topo;

void shuntyard( char* exp ){

	int pos = 0;
	int out = 0;

	char init = 1;
	topo = 0;
	
	while( exp[pos] ){
		
		if( 'a' <= exp[pos] && exp[pos] <= 'z' ){
				exp_rpn[out++] = exp[pos];
			    exp_rpn[out++] = ' ';
				init = 0;
			
		} else if( '0' <= exp[pos] && exp[pos] <= '9' ){

				while( '0' <= exp[pos] && exp[pos] <= '9' ){
					exp_rpn[ out++ ] = exp[pos++];
				}
				exp_rpn[ out++ ] = ' ';
				pos--;
				init = 0;
		
		} else if( exp[pos] == '(' ){
			
			pilha[topo++] = exp[pos];
			init = 1;
		
		} else if( exp[pos] == ')' ){
			
			init = 0;
			while( topo && pilha[topo-1] != '(' ){
				exp_rpn[out++] = pilha[--topo];
				exp_rpn[out++] = ' ';
			}
			if( topo ) topo--; 
		
		 } else {

			if( init ){
				exp_rpn[out++] = '0';
				exp_rpn[out++] = ' ';
				init = 0;
			}
				
			switch( exp[pos] ){
				
				case '+':
				case '-':
						while( topo ){
							topo--;
							if( pilha[topo] != '(' &&  pilha[topo] != ')' ){
								exp_rpn[out++] = pilha[topo];
								exp_rpn[out++] = ' ';
							} else { topo++; break; }
						}
						break;
				case '*':
				case '/':
						while( topo ){
							topo--;
							if( pilha[topo] == '*' || pilha[topo] == '/'  ){
								exp_rpn[out++] = pilha[topo];
								exp_rpn[out++] = ' ';
							} else { topo++; break; }
						}
						break;
			}
			pilha[topo++] = exp[pos];
		 }
		pos++;
	}
	
	while( topo ){
		exp_rpn[out++] = pilha[--topo];
		exp_rpn[out++] = ' ';
	}
	exp_rpn[out] = 0;
}

double resolve(){

	int p = 0;
	double o1, o2, x;
	topo = 0;
	
	while( exp_rpn[p]  ){
		
		if( 'a' <= exp_rpn[p] && exp_rpn[p] <= 'z' ){

			values[topo++] = memoria[ exp_rpn[p]-'a' ];
		}
		else if( '0' <= exp_rpn[p] && exp_rpn[p] <= '9' ){

			sscanf( exp_rpn+p, "%lf", &x );
			values[topo++] = x;

		}
		else {
		
			o2 = values[--topo];
			o1 = values[--topo];

			switch( exp_rpn[p] ){
				case '+': values[topo++] = o1 + o2; break;
				case '-': values[topo++] = o1 - o2; break;
				case '*': values[topo++] = o1 * o2; break;
				case '/': values[topo++] = o1 / o2; break;	
			}
		
		}

		p++;
		while( exp_rpn[p] && exp_rpn[p] != ' ' ) p++;
		if( exp_rpn[p] == ' ' ) p++;
	
	}
	return values[--topo];
}

int main(){

	while( scanf("%s", expressao) != EOF ){
		
		if( !expressao[0] || expressao[0] == '\n') continue;

		if( expressao[1] == '=' ){
			shuntyard( expressao+2 );
			memoria[ expressao[0]-'a' ] = resolve();
		} else {
			shuntyard( expressao );
			printf("%.2lf\n", resolve() );
		}
	}

	return 0;
}
