#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>

#define MAXP 128

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

int main() {
    ios::sync_with_stdio(false);


    while (cin >> n && n) {
        
        for (int i = 0; i < n; ++i) {
            cin >> pontos[i].x >> pontos[i].y;
        }
        
        double R;
        cin >> R;
        
        Circle mec = MSC();
        
        if (mec.raio <= R) cout << "The polygon can be packed in the circle.\n";
        else cout << "There is no way of packing that polygon.\n";
    }
    return 0;
}