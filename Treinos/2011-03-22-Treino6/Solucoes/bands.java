import java.util.*;
import java.io.*;

public class bands {
  static void CAREFULPRINT(double d, int digits) {
    String formatstring = "%1$." + digits + "f";
    String toprint = String.format(formatstring, d);
    double diff = Math.abs(Double.parseDouble(toprint) - d);
    if (diff > .499999 * Math.pow(10, -1 * digits)) {
      System.err.println("WARNING: printing " + d + " to " + digits + " digits: " + toprint);
    }
    System.out.print(toprint);
  }
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    while (in.hasNextDouble()) {
      double x1 = in.nextDouble();
      double y1 = in.nextDouble();
      double r1 = in.nextDouble();
      double x2 = in.nextDouble();
      double y2 = in.nextDouble();
      double r2 = in.nextDouble();
      if (r1 < r2) { double temp = r1; r1 = r2; r2 = temp; }
      double d = Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
      double x = Math.sqrt(d * d - (r1 - r2) * (r1 - r2));  // The straight parts are of length x
      double theta = Math.atan(x / (r1 - r2));
      double around = (2 * Math.PI - 2 * theta) * r1 + (2 * Math.PI - 2 * (Math.PI - theta)) * r2;
      CAREFULPRINT(2 * x + around, 3);
      System.out.print(" ");
      double d1 = Math.sqrt(r1 * r1 * d * d / (r1 + r2) / (r1 + r2) - r1 * r1);
      double d2 = Math.sqrt(r2 * r2 * d * d / (r1 + r2) / (r1 + r2) - r2 * r2);
      double theta2 = Math.atan(d1 / r1);
      double around2 = (2 * Math.PI - 2 * theta2) * (r1 + r2);
      CAREFULPRINT(2 * (d1 + d2) + around2, 3);
      System.out.println();
    }
  }
}
      
