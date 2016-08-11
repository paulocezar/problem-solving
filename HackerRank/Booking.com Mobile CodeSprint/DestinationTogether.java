import java.io.*;
import java.util.*;

public class DestinationTogether {

    public static void main(String[] args) {
        int n, m, c;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        c = sc.nextInt();
        n -= c;
        m -= c;
        int t = n + m + c;
        long f = 1;
        for (int i = 1; i < t; ++i) f *= (long)i;
        System.out.println(f);
    }
}
