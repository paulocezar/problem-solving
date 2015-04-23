import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		while( n != 0 ){
			BigInteger fat = BigInteger.ONE;
			System.out.println( n + "! --" );
			while( n > 1 ){
				fat = fat.multiply( BigInteger.valueOf(n) );
				n--;
			}
			
			String x = fat.toString();
			int f[] = new int[10];
			
			for( int i = 0; i < 10; i++ ) f[i] = 0;
			for( int i = 0; i < x.length(); i++ ){
				f[ x.charAt(i)-'0' ]++;
			}
			
			for( int i = 0; i < 5; i++ ){
				if( i == 0 ) System.out.print("   ");
				else System.out.print("    ");
				System.out.print( "(" + i + ")" );
				System.out.printf( "%5d", f[i] );
			}
			System.out.println("");
			for( int i = 5; i < 10; i++ ){
				if( i == 5 ) System.out.print("   ");
				else System.out.print("    ");
				System.out.print( "(" + i + ")" );
				System.out.printf( "%5d", f[i] );
			}
			System.out.println("");
			n = cin.nextInt();	
		}		
	}
}