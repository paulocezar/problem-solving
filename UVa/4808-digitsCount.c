/*
 *  Problema: 
 *  Tecnica Utilizada: 
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long countDigits(int digit, int num){
       long long count = 0;
       int pot = 1;
       int numDigit;

       if(digit == 0){
               while(num > pot){
                       numDigit = (num/pot)%10;
                       if(numDigit == digit){
                               count += (num/(pot*10) - 1)*pot + num%pot + 1;
                       }
                       else{
                               count += num/(pot*10)*pot;
                       }
                       pot *= 10;
               }
       }
       else{
               while(num >= pot){
                       numDigit = (num/pot)%10;
                       if(numDigit == digit){
                               count += (num/(pot*10))*pot + num%pot + 1;
                       }
                       else if(numDigit < digit){
                               count += (num/(pot*10))*pot;
                       }
                       else{
                               count += (num/(pot*10) + 1)*pot;
                       }
                       pot *= 10;
               }
       }

       return count;
}

int main(){

       int a, b;
       int digitsA, digitsB;
       int i;

       while(1){
               scanf("%d %d", &a, &b);
               if(a + b == 0) break;

		   
			   printf("%d", countDigits(0, b) - countDigits(0, a-1));
               for(i = 1; i < 10; i++){
                       digitsA = countDigits(i, a-1);
                       digitsB = countDigits(i, b);
                       printf(" %d", digitsB - digitsA);
               }
               printf("\n");
       }

       return 0;
}
