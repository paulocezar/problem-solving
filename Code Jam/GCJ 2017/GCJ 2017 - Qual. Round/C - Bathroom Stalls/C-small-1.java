import java.util.*;

public class C {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    int T = in.nextInt();
    for (int tc = 1; tc <= T; ++tc) {
      long N, K;
      N = in.nextLong();
      K = in.nextLong();

      TreeMap<Long,Long> free = new TreeMap<>();
      free.put(N, 1l);

      long mn, mx, cnt;

      while (true) {
        Map.Entry<Long, Long> cur = free.pollLastEntry();
        mn = (cur.getKey() - 1l) / 2l;
        mx = cur.getKey() - 1l - mn;
        cnt = cur.getValue();

        if (cnt >= K) break;
        K -= cnt;
        free.put(mn, cnt + (free.containsKey(mn) ? free.get(mn) : 0));
        free.put(mx, cnt + (free.containsKey(mx) ? free.get(mx) : 0));
      }

      System.out.println("Case #" + tc + ": " + mx + " " + mn);
    }
  }
}
