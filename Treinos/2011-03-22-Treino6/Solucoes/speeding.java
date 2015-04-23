import java.util.*;
import java.io.*;

public class speeding {
  static void CAREFULPRINT(double d, int digits) {
    String formatstring = "%1$." + digits + "f";
    String toprint = String.format(formatstring, d);
    double diff = Math.abs(Double.parseDouble(toprint) - d);
    if (diff > .499999 * Math.pow(10, -1 * digits)) {
      System.err.println("WARNING: printing " + d + " to " + digits + " digits: " + toprint);
    }
    System.out.print(toprint);
  }

  static class Range implements Comparable {
    double min, max;
    public Range(double a, double b) {
      min = a;
      max = b;
    }
    public Range intersect(Range r) {
      double maxmin = Math.max(min, r.min);
      double minmax = Math.min(max, r.max);
      // Just to make sure exact answers aren't cut off:
      if (Math.abs(minmax - maxmin) < 1e-9) {
        maxmin = minmax - 1e-9;
      }
      return new Range(maxmin, minmax);
    }
    public double width() {
      if (max < min) return 0;
      return 1;
    }
    public String toString() {
      return min * 3.6 + "-" + max * 3.6;
    }
    public int compareTo(Object o) {
      Range r = (Range)o;
      if (min != r.min) { return (min < r.min) ? 1 : -1; }
      if (max != r.max) { return (max < r.max) ? 1 : -1; }
      return 0;
    }
  }
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    for (int n = in.nextInt(); n != 0; n = in.nextInt()) {
      double[] p = new double[n];
      double[] g = new double[n];
      double[] r = new double[n];
      for (int i = 0; i < n; ++i) {
        p[i] = in.nextDouble();
        g[i] = in.nextDouble();
        r[i] = in.nextDouble();
        if (g[i] > r[i]) g[i] -= 30.0;
      }
      Vector<Range> cur = new Vector();
      cur.add(new Range(50./3.6, 300./3.6));
      for (int k = 0; k < n; ++k) {
        // Restrict via light #k
        Vector<Range> nxt = new Vector();
        double t = 0;
        for (int i = 0; i < cur.size(); ++i) {
          while (p[k] / (t + 60) > (cur.get(i).max)) t += 30.;
          while (p[k] / (Math.max(t - 60, 1e-9)) > (cur.get(i).min)) {
            Range good = cur.get(i).intersect(
              new Range(p[k] / (t + r[k]), p[k] / (Math.max(1e-9, t + g[k]))));
            if (good.width() > 0.0) { nxt.add(good); }
            t += 30.;
          }
          t -= 180.;
        }
        Range[] ra = (Range[])nxt.toArray(new Range[0]);
        Arrays.sort(ra);
        cur = new Vector();
        for (int i = 0; i < ra.length; ++i) {
          if (i == 0 || ra[i].compareTo(ra[i - 1]) != 0) {
            cur.add(ra[i]);
          }
        }
      }
      if (cur.size() == 0) System.out.println("Impossible");
      else { 
        CAREFULPRINT(cur.get(0).max * 3.6, 2); System.out.println(" km/h");
        double speed = cur.get(0).max;
        for (int i = 0; i < n; ++i) {
          double t = p[i] / speed;
          while (t >= g[i] - 1e-9) t -= 30;
          t += 30;
          if (t > r[i] + 1e-9) System.err.println("Warning: speed " + speed + " crossed line " + i + " at t = " + p[i] / speed + " = " + t + ": g[i] = " + g[i] + " r[i] = " + r[i]);
        }
      }
    }
  }
}
