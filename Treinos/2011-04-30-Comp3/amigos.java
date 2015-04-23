import java.util.Scanner;
import java.math.BigInteger;

public class amigos{

	public static void main( String args[] ){

		Scanner sc = new Scanner( System.in );
		
		int m, n;
		int ans[] = new int[2];
		ans[0] = 13; ans[1] = 65533;
		
		int T = sc.nextInt();
		while( T-- > 0 ){
			m = sc.nextInt();
			n = sc.nextInt();
		
			switch( m ){
				case 0: System.out.println( n+1 ); break;
				case 1: System.out.println( n+2 ); break;
				case 2: System.out.println( 2*n + 3 ); break;
				case 3: System.out.println( BigInteger.valueOf(2).pow( n+3 ).subtract(BigInteger.valueOf(3)) ); break;
				case 4: if( n < 2 ) System.out.println( ans[n] );
						else System.out.println( BigInteger.valueOf(2).pow( 65536 ).subtract(BigInteger.valueOf(3)) );
						break;
			}
			System.out.println("");
		
		}

	}

}
