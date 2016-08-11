import java.io.*;
import java.util.*;

public class GoodMemories {

    static List<List<Integer>> gr = new ArrayList<>(1024);
    static char stat[] = new char[1024];

    static boolean find_cycle(int u) {
        stat[u] = 1;
        for (int v : gr.get(u)) {
            if (stat[v] == 1) return true;
            if (stat[v] == 2) continue;
            if (find_cycle(v)) return true;
        }
        stat[u] = 2;
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-->0) {

            for (int i = 0; i < 1024; ++i) gr.add(i, new ArrayList<>());
            HashMap<String, Integer> attractions = new HashMap<>();

            int n = sc.nextInt(); sc.nextLine();
            while (n-->0) {
                String line = sc.nextLine();
                String[] attrs = line.split(",");
                int prev = -1;
                for (String attr : attrs) {
                    if (!attractions.containsKey(attr)) attractions.put(attr, attractions.size());
                    if (prev != -1) gr.get(prev).add(attractions.get(attr));
                    prev = attractions.get(attr);
                }
            }

            n = attractions.size();
            boolean ok = true;
            for (int i = 0; i < n; ++i) stat[i] = 0;

            for (int i = 0; i < n; ++i) {
                if (stat[i] != 0) continue;
                if (find_cycle(i)) {
                    ok = false;
                    break;
                }
            }

            if (ok) System.out.println("ORDER EXISTS");
            else System.out.println("ORDER VIOLATION");
        }
    }
}
