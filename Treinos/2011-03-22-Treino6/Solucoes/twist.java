import java.util.*;
import java.io.*;

public class twist {
  static String sort(String s) {
    char[] c = new char[s.length()];
    for (int i = 0; i < s.length(); ++i) c[i] = s.charAt(i);
    Arrays.sort(c);
    return new String(c);
  }

  public static void main(String[] args) { 
    int[] ones = new int[1 << 6];
    for (int i = 0; i < (1 << 6); ++i) {
      int n = i;
      while (n != 0) {
        ones[i] += (n & 1);
        n >>= 1;
      }
    }
    Scanner in = new Scanner(System.in);
    int N = in.nextInt();
    Map<String, Integer> words = new HashMap();
    Map<String, int[]> words_to_num = new HashMap();
    Vector<String> six = new Vector();
    for (int qw = 0; qw < N; ++qw) {
      String s = in.next();
      if(s.length() == 6) six.add(s);
      String toadd = sort(s);
      Integer i = words.get(toadd);
      if (i == null) i = 0;
      words.put(toadd, i + 1);
    }
    while (in.hasNext()) {
      int[] supposed = new int[7];
      char c = in.next().charAt(0);
      for (int i = 3; i < 7; ++i) {
        supposed[i] = in.nextInt();
      }
      boolean found = false;
      outer:
      for(String s : six) {
        boolean cfound = false;
        for (int i = 0; i < s.length(); ++i) {
          if (s.charAt(i) == c) cfound = true;
        }
        if (!cfound) continue;
        int[] num = new int[7];
        if (words_to_num.get(s) != null) {
          num = words_to_num.get(s);
        } else {
          Set<String> check = new HashSet();
          for (int a = 0; a < (1 << 6); ++a) {
            if(ones[a] < 3) continue;
            String tocheck = "";
            for (int b = 0; b < 6; ++b) {
              if (((1 << b) & a) != 0) tocheck += s.charAt(b);
            }
            check.add(sort(tocheck));
          }
          for (String lookup : check) {
            Integer toadd = words.get(lookup);
            if (toadd == null) toadd = 0;
            num[lookup.length()] += toadd;
          }
          words_to_num.put(s, num);
        }
        for (int a = 3; a < 7; ++a) {
          if(num[a] != supposed[a]) continue outer;
        }
        System.out.println(s);
        found = true;
        break;
      }
      if (!found) {
        System.out.println("There must be something wrong with our dictionary!");
      }
    }
  }
}
