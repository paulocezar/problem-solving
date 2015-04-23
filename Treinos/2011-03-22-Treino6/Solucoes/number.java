import java.util.*;
import java.io.*;

public class number {
  static int[] equiv = {0, 1, 2, 3, 4, 2, 6, 7, 8, 6};

  static String maximize(int[] have, int len) {
    int num = 0;
    for (int i : have) num += i;
    char[] got = new char[num];
    int where = 0;
    for (int i = 0; i < have.length; ++i) {
      for (int j = 0; j < have[i]; ++j) {
        got[where++] = (char)(i + '0');
      }
    }
    for (int i = 0; i < got.length; ++i) {
      if (got[i] == '2') got[i] = '5';
      if (got[i] == '6') got[i] = '9';
    }
    Arrays.sort(got);
    String ans = "";
    for (int i = got.length - 1; ans.length() < len; --i) {
      ans += got[i];
    }
    return ans;
  }
  static String minimize(int[] have, int len) {
    int num = 0;
    for (int i : have) num += i;
    char[] got = new char[num];
    int where = 0;
    for (int i = 0; i < have.length; ++i) {
      for (int j = 0; j < have[i]; ++j) {
        got[where++] = (char)(i + '0');
      }
    }
    for (int i = 0; i < got.length; ++i) {
      if (got[i] == '5') got[i] = '2';
      if (got[i] == '9') got[i] = '6';
    }
    Arrays.sort(got);
    String ans = "";
    for (int i = 0; ans.length() < len; ++i) {
      ans += got[i];
    }
    return ans;
  }


  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for (int qw = 0; qw < n; ++qw) {
      String wants = in.next();
      int wanti = Integer.parseInt(wants);
      String input = in.next();
      int[] have = new int[10];
      for (int i = 0; i < input.length(); ++i) {
        ++have[equiv[input.charAt(i) - '0']];
      }
      // Three cases: longer, shorter, same length.
      if (input.length() < wants.length()) {
        System.out.println(maximize(have, input.length()));
      } else {
        Vector<String> poss = new Vector();
        // Try length 1 longer
        if (have[1] > 0 && input.length() > wants.length()) {
          --have[1];
          poss.add("1" + minimize(have, wants.length()));
          ++have[1];
        }
        // Try length 1 shorter
        poss.add(maximize(have, wants.length() - 1));
        // Same length:
        for (int i = 0; i < wants.length(); ++i) {
          for (int j = 0; j < 10; ++j) if (have[equiv[j]] > 0) {
            if (j < wants.charAt(i) - '0') {
              --have[equiv[j]];
              poss.add(wants.substring(0, i) + j + maximize(have, wants.length() - i - 1));
              ++have[equiv[j]];
            } else if (j > wants.charAt(i) - '0') {
              --have[equiv[j]];
              poss.add(wants.substring(0, i) + j + minimize(have, wants.length() - i - 1));
              ++have[equiv[j]];
            }
          }
          if (have[equiv[wants.charAt(i) - '0']] == 0) break;
          --have[equiv[wants.charAt(i) - '0']];
          if (i == wants.length() - 1) {
            poss.add(wants);
          }
        }
        int best = Integer.MAX_VALUE;
        for (String guess : poss) {
          int guessi = Integer.parseInt(guess);
          if (Math.abs(guessi - wanti) < Math.abs(best - wanti) ||
             (Math.abs(guessi - wanti) == Math.abs(best - wanti) && guessi > best)) {
            best = guessi;
          }
        }
        System.out.println(best);
      }
    }
  }
}

