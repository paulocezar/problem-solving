/*
 *  Problema: Posto de Bombeiros
 *  Tecnica Utilizada:  Find Circumcenter
 *	
 *		 Queremos encontrar o ponto equidistante dos pontos p1, p2 e p3, 
 *		ou seja, o centro da circumferencia que engloba os 3. Se os tres pontos 
 *		forem iguais a resposta e o proprio ponto, se dois pontos forem iguais
 *		existem infinitas solucoes, que os tres forem colineares, nao existe solucao
 *      e caso contrario a solucao e o centro da circuferencia definida pelos 3 pontos.
 *      
 *  Dificuldade: Medio
 *	Complexidade:
 *				O( 1 )
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>

#define MAXP 110
#define EPS 10e-8

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
	
	bool operator == ( Ponto p ){
		return ( !(abs( x - p.x ) > EPS ) && !( abs( y - p.y ) > EPS ) );
	}
	
	double dist(Ponto p){ 
		return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
	}
	
};

Ponto findCC( Ponto p1, Ponto p2, Ponto p3 ){
	Ponto a, b, c; 
	a = p1 - p3; 
	b = p2 - p3; 
	c = Ponto( (a*(p1+p3))/2.0, (b*(p2+p3))/2.0);
	
	return Ponto( c % Ponto(a.y,b.y), Ponto(a.x, b.x) %c ) / (a%b);
}

int main(){

	double x1, y1, x2, y2, x3, y3;
	int n;
	Ponto cc, p1, p2, p3;
	ios::sync_with_stdio( false );
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision( 7 );
	
	cin >> n;
	while( n-- ){
		
		cin >> x1 >> y1  >> x2  >> y2  >> x3  >> y3;
		p1 = Ponto( x1, y1 );
		p2 = Ponto( x2, y2 );
		p3 = Ponto( x3, y3 );
		
		if( p1 == p2 && p2 == p3 )
			cout << "The equidistant location is (" << p1.x << ", " << p1.y << ").\n";
		else if( p1 == p2 || p1 == p3 || p2 == p3 )
			cout << "There is an infinity of possible locations.\n";
		else {
		
			if( !( abs((p1 - p3)%(p2 - p3)) > EPS) ){
				cout << "There is no possible location.\n";				
			} else {
				cc = findCC( p1, p2, p3 );	
				cout << "The equidistant location is (" << cc.x << ", " << cc.y << ").\n";
			}
			
		}
		
	}

	return 0;
}
