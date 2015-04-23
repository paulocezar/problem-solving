import java.util.*;
import java.io.*;

public class walks {
  static int[] dx = {0, 1, 0, -1};
  static int[] dy = {-1, 0, 1, 0};
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    for (int r = in.nextInt(), c = in.nextInt(); r * c != 0; r = in.nextInt(), c = in.nextInt()) {
      in.nextLine();
      boolean[][] block = new boolean[r + 2][c + 2];
      for (int i = 0; i < r + 2; ++i) Arrays.fill(block[i], true);
      int sx = 0, sy = 0, ex = 0, ey = 0;
      for (int i = 0; i < r; ++i) {
        String s = in.nextLine();
        for (int j = 0; j < c; ++j) {
          block[i + 1][j + 1] = s.charAt(j) == 'p';
          if (s.charAt(j) == 'b') { sy = i + 1; sx = j + 1; }
          if (s.charAt(j) == 'w') { ey = i + 1; ex = j + 1; }
        }
      }
      long[][][] ways = new long[2][r + 2][c + 2];
      ways[0][sy][sx] = 1;
      long total = 0;
      for (int t = 1; t <= 20; ++t) {
        for (int i = 0; i < r + 2; ++i) {
          for (int j = 0; j < c + 2; ++j) {
            ways[t % 2][i][j] = 0;
          }
        }
        for (int i = 1; i <= r; ++i) {
          for (int j = 1; j <= c; ++j) {
            for (int k = 0; k < 4; ++k) if (!block[i + dy[k]][j + dx[k]]) {
              ways[t % 2][i + dy[k]][j + dx[k]] += ways[(t + 1) % 2][i][j];
            }
          }
        }
        total += ways[t % 2][ey][ex];
   /*   for (int i = 0; i < r + 2; ++i) {
          for (int j = 0; j < c + 2; ++j) {
            System.out.print(ways[t % 2][i][j] + " ");
          }
          System.out.println();
        }
        System.out.println();
   */ }
      System.out.println(total);
    }
  }
}
        
