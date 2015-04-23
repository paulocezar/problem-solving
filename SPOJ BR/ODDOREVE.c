#include <stdio.h>
#include <stdlib.h>

int main(){

 int parM, imparM, nums, in, i;

 while( 1 ){
	scanf("%d", &nums );
	if( nums == 0 ) return 0;

	parM = imparM = 0;

	for( i = 0; i < nums; i++ ){
	   scanf("%d", &in );
	   in % 2 ? imparM++ : parM++ ;
	}

	for( i = 0; i < nums; i++ ){
	  scanf("%d", &in );
	  in % 2 ? parM-- : imparM--;
	}

	if( parM < 0 )
		parM *= -1;

	printf("%d\n", parM );
 } 

 return 0;

}
