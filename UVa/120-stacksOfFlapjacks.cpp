#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int stack[30], size;

 while( cin >> stack[0] ){

	printf("%d", stack[0]);
	size = 1;

	while( getchar() != '\n' ){

		scanf("%d", &stack[size]);
		printf(" %d", stack[size]);
		size++;
	}

	printf("\n");
	int last = size-1;

	while( 0 < last ){

		int max = max_element( stack, stack+last+1 ) - stack;

		if( max == last ){

			last--;
			continue;
		}
		else {
			if( max != 0 ){

				printf("%d ", size - max);
				reverse( stack, stack+max+1 );
			}

			printf("%d ", size - last);
			reverse( stack, stack+last+1 );
		}
	}

	printf("0\n");
 }

 return 0;
}
