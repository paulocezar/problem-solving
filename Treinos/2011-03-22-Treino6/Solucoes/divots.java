import java.util.*;
import java.io.*;

public class divots {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    for (long n = in.nextLong(); n != 0; n = in.nextLong()) {
      System.out.println((n * n + 1) + ", " + (n * n) + ", " + (n * n + 1));
    }
  }
}
