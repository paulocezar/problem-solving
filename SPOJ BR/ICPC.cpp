/*
 *  Problema: Final do ICPC
 *  Tecnica Utilizada:  Minimum Spanning Circle
 *	
 *		 O enunciado do problema deixa bem claro que deve ser encontrado
 *		o MSC dos pontos em questao. Sem muitos misterios esse..
 *      
 *  Dificuldade: Medio-Facil
 *	Complexidade:
 *				O( N^3 )
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>

#define MAXP 110

using namespace std;

struct Ponto{
	double x,y;
	Ponto(double x = 0, double y = 0) : x(x), y(y){}

	//produto interno 2D 
	double operator *(Ponto p){
		return x*p.x + y*p.y;
	}
	
	//produto vetorial 2D (lembrar de colocar o 3D) 
	double operator % (Ponto p){
		return x*p.y - y*p.x;
	}
	
	Ponto operator / ( double d ){
		return Ponto( x/d, y/d);
	}
	
	Ponto operator - (Ponto p){ 
		return Ponto(x-p.x, y-p.y);
	}

	Ponto operator + (Ponto p){ 
		return Ponto(x+p.x, y+p.y);
	}
	
	double operator ! (){ 
		return sqrt(x*x + y*y);
	}
	
	double dist(Ponto p){ 
		return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
	}
	
};

struct Circle {
	Ponto centro;
	double raio;
	Circle( Ponto centro = Ponto(), double raio = 0.0 ) : centro(centro), raio(raio){}
	bool pert( Ponto p ){
		if( centro.dist( p ) - raio < 10e-9 ) return true;
		return false;
	}
};

Ponto pontos[MAXP];
int n;

Ponto findCC( Ponto p1, Ponto p2, Ponto p3 ){
	Ponto a, b, c; 
	a = p1 - p3; 
	b = p2 - p3; 
	c = Ponto( (a*(p1+p3))/2.0, (b*(p2+p3))/2.0);
	
	return Ponto( c % Ponto(a.y,b.y), Ponto(a.x, b.x) %c ) / (a%b);
}

Circle MSC(){

	Circle c( Ponto(), -100000000 );
	int i, j, k;
	
	random_shuffle( pontos, pontos + n );
	
	for( i = 0; i < n; i++ ) if( !c.pert(pontos[i]) ){
		
			c = Circle( pontos[i], 0 );
			for( j = 0; j < i; j++ ) if( !c.pert(pontos[j]) ){
					
					c = Circle( (pontos[j] + pontos[i])/2, pontos[j].dist( pontos[i] ) /2 );
					for( k = 0; k < j; k++ ) if( !c.pert( pontos[k] ) ){
							c.centro = findCC( pontos[k], pontos[i], pontos[j] );
							c.raio = c.centro.dist( pontos[k] );
					}
			}
	}
	return c;
}

int main(){

	double x, y;
	int inst = 1;
	
	while( true ){
		scanf("%d", &n );
		if( n == 0 ) return 0;
		
		for( int i = 0; i < n; i++ ){
			scanf("%lf %lf", &x, &y );
			pontos[i] = Ponto( x, y );
		}
		Circle c = MSC();
		
		printf("Instancia %d\n%.02lf %.02lf %.02lf\n\n", inst++, c.centro.x, c.centro.y, c.raio );
		
	}

	return 0;
}
