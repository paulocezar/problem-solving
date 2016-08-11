import java.io.*;
import java.util.*;

public class CouplingPassions {

    public static final double PI = 3.14159265359;
    public static final double EARTH_RADIUS = 6371;
    public static final double HALF_C = PI / 180.0;

    public static List<Integer> passions;
    public static List<List<Integer>> good_for = new ArrayList<>(256);


    public static String destination[] = new String[256];
    public static double lat[] = new double[256], lon[] = new double[256];

    static double deg2rad(double x) {
        return x * HALF_C;
    }

    static double distance_between(int p1, int p2) {
        double p1_lat_rad = deg2rad(lat[p1]);
        double p2_lat_rad = deg2rad(lat[p2]);
        double p1_lon_rad = deg2rad(lon[p1]);
        double p2_lon_rad = deg2rad(lon[p2]);

        return Math.acos(Math.sin(p1_lat_rad) * Math.sin(p2_lat_rad) +
                Math.cos(p1_lat_rad) * Math.cos(p2_lat_rad) *
                        Math.cos(p2_lon_rad - p1_lon_rad)) * EARTH_RADIUS;
    }

    public static void main(String[] args) {
        HashMap<String, Integer> passion_to_int = new HashMap<>();
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        passions = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i) {
            int m = sc.nextInt();
            while (m-->0) {
                String ax = sc.next();
                if (!passion_to_int.containsKey(ax)) {
                    passion_to_int.put(ax, passion_to_int.size());
                }
                passions.add(passion_to_int.get(ax));
            }
        }
        passions.sort(Comparator.naturalOrder());

        int d = sc.nextInt();
        for (int i = 0; i < d; ++i) {
            destination[i] = sc.next();
            lat[i] = sc.nextDouble();
            lon[i] = sc.nextDouble();
            int m = sc.nextInt();

            good_for.add(new ArrayList<>(m));
            while (m-->0) {
                String ax = sc.next();
                if (passion_to_int.containsKey(ax)) good_for.get(i).add(passion_to_int.get(ax));
            }
            good_for.get(i).sort(Comparator.naturalOrder());
        }

        int best = -1;
        double best_dis = 0.0;
        String da = "", db = "";

        for (int i = 0; i < d; ++i) {
            for (int j = i+1; j < d; ++j) {
                int score = 0;
                for (int passion : passions) {
                    if (good_for.get(i).contains(passion) || good_for.get(j).contains(passion)) score++;
                }
                if (score > best) {
                    best = score;
                    best_dis = distance_between(i, j);
                    da = destination[i];
                    db = destination[j];
                } else if (score == best) {
                    double ndis = distance_between(i, j);
                    if (ndis < best_dis) {
                        best_dis = ndis;
                        da = destination[i];
                        db = destination[j];
                    }
                }
            }
        }

        if (da.compareTo(db) > 0) { String ax = db; db = da; da = ax; }
        System.out.println(da + " " + db);
    }
}
