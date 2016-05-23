import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {

    static BigInteger[] levelPow;
    static List<Integer> decomp;
    static List<BigInteger> decomp2;

    public static void doit(BigInteger l, BigInteger r) {
      //System.out.println("DOIN> " + l + " --- " + r);
      if (l.compareTo(r) > 0) return;
      for (int level = 20; level > 0; --level) {
        if (r.subtract(l.subtract(BigInteger.ONE)).compareTo(levelPow[level]) >= 0) {
            BigInteger hi = r.divide(levelPow[level]);
            BigInteger lo = l.divide(levelPow[level]);
            //System.out.println(level + " >>>> " + lo + " - " + hi);
            BigInteger nhi = lo.multiply(levelPow[level]);
            if (r.compareTo(nhi) != 0) doit(l, nhi);
            decomp.add(level);
            decomp2.add(hi.subtract(lo));
            BigInteger nlo = hi.multiply(levelPow[level]).add(BigInteger.ONE);
            if (l.compareTo(nlo) != 0) doit(nlo, r);
            return;
        }
      }

      decomp.add(0);
      decomp2.add(r.subtract(l));
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger l = cin.nextBigInteger();
        BigInteger r = cin.nextBigInteger();

        levelPow = new BigInteger[21];
        levelPow[0] = BigInteger.ONE;
        levelPow[1] = BigInteger.TEN;

        for (int i = 2; i < 21; ++i) {
          levelPow[i] = levelPow[i-1].multiply(levelPow[i-1]);
        }

        decomp = new ArrayList<Integer>();
        decomp2 = new ArrayList<BigInteger>();

        doit(l, r);

        System.out.println(decomp.size());
        for (int i = 0; i < decomp.size(); ++i) {
         System.out.println(decomp.get(i) + " " + decomp2.get(i));
        }
    }
}
