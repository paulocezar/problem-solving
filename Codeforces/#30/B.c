#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int d, m, a;
} data_t;

int isValid( data_t data ){
	
	if( data.m > 12 ) return 0;
	
	if( data.m == 1 || data.m == 3 || data.m == 5 || data.m == 7 || data.m == 8 || data.m == 10 || data.m == 12 )
	{
			if( data.d > 31 ) return 0;
	}
	else if( data.m == 2 ){
		
		if( data.a % 4 ){
			if( data.d > 28 ) return 0;
		} else if( data.d > 29 ) return 0;
	
	} else if( data.d > 30 ) return 0;
	
	return 1;
}

int age( data_t nasc, data_t cur ){
	
	if( cur.a < nasc.a ) return 0;
	
	int age = ( cur.a - nasc.a );
	
	if( nasc.m < cur.m ) return age;
	else if( nasc.m > cur.m ) return age - 1;
	else {
		
		if( nasc.d <= cur.d ) return age;
		else return age-1;
	}

}

int main(){
	
	data_t cont, d1, d2, d3, d4, d5, d6;
	
	scanf("%d.%d.%d", &cont.d, &cont.m, &cont.a ); 
	scanf("%d.%d.%d", &d1.d, &d1.m, &d1.a ); 
	
	d2.d = d1.m; d2.m = d1.d; d2.a = d1.a;
	d3.d = d1.a; d3.m = d1.d; d3.a = d1.m;
	
	d4.d = d1.d; d4.m = d1.a; d4.a = d1.m;
	d5.d = d1.m; d5.m = d1.a; d5.a = d1.d;
	d6.d = d1.a; d6.m = d1.m; d6.a = d1.d;
	
	if( isValid( d1 ) && age( d1, cont ) >= 18 ){ puts("YES");
	} else if( isValid( d2 ) && age( d2, cont ) >= 18 ){ puts("YES");
	} else if( isValid( d3 ) && age( d3, cont ) >= 18 ){ puts("YES");
	} else if( isValid( d4 ) && age( d4, cont ) >= 18 ){ puts("YES");
	} else if( isValid( d5 ) && age( d5, cont ) >= 18 ){ puts("YES");
	} else if( isValid( d6 ) && age( d6, cont ) >= 18 ){ puts("YES");
	} else puts("NO");
	
	
	return 0;
}

