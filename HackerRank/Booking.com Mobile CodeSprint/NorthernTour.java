import java.io.*;
import java.util.*;

public class NorthernTour {

    static int must_stay[] = new int[32];
    static List<List<Integer>> gr = new ArrayList<>(32);
    static List<List<Integer>> ws = new ArrayList<>(32);
    static String cname[] = new String[32];

    static List<List<List<HashMap<Integer, Integer>>>> cache;
    static {
        cache = new ArrayList<>(21);
        for (int i = 0; i < 21; ++i) {
            cache.add(new ArrayList<>(6));
            for (int j = 0; j < 6; ++j) {
                cache.get(i).add(new ArrayList<>(17));
                for (int k = 0; k < 17; ++k) {
                    cache.get(i).get(j).add(new HashMap<>());
                }
            }
        }
    }

    static int doit(int seen, int at, int day, int rem) {
        if (day > 5) return 0;
        if (cache.get(at).get(day).get(rem).containsKey(seen)) return cache.get(at).get(day).get(rem).get(seen);

        int best = 0, sz = gr.get(at).size();
        for (int i = 0; i < sz; ++i) {
            int v = gr.get(at).get(i), w = ws.get(at).get(i);
            if ((seen & (1<<v)) != 0) continue;
            int nd = day;
            int nr = rem;
            if (w > nr) { nd++; nr = 16; }
            nr -= w;
            if (nr == 0) { nd++; nr = 16; }
            int ms = must_stay[v];
            while ((ms > nr) && (nd < 5)) {
                ms -= nr;
                nd++;
                nr = 16;
            }
            if ((ms > nr) || (nd > 5)) {
                continue;
            }
            nr -= ms;
            if (nr == 0) { nd++; nr = 16; }
            best = Math.max(best, 1 + doit(seen | (1<<v), v, nd, nr));
        }

        cache.get(at).get(day).get(rem).put(seen, best);
        return best;
    }

    static void build(int seen, int at, int day, int rem) {
        if (day > 5) return;
        int best = cache.get(at).get(day).get(rem).get(seen);
        if (best == 0) return;

        int sz = gr.get(at).size();
        for (int i = 0; i < sz; ++i) {
            int v = gr.get(at).get(i), w = ws.get(at).get(i);
            if ((seen & (1<<v)) != 0) continue;
            int nd = day;
            int nr = rem;
            if (w > nr) { nd++; nr = 16; }
            nr -= w;
            if (nr == 0) { nd++; nr = 16; }
            int ms = must_stay[v];
            while ((ms > nr) && (nd < 5)) {
                ms -= nr;
                nd++;
                nr = 16;
            }
            if ((ms > nr) || (nd > 5)) {
                continue;
            }
            nr -= ms;
            if (nr == 0) { nd++; nr = 16; }
            if (best == (1 + doit(seen | (1<<v), v, nd, nr))) {
                System.out.println(cname[v]);
                build(seen | (1<<v), v, nd, nr);
                return;
            }
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); sc.nextLine();
        n++;

        HashMap<String, Integer> name_to_i = new HashMap<>();
        name_to_i.put("Bevagna", 0);
        gr.add(new ArrayList<>());
        ws.add(new ArrayList<>());

        for (int i = 1; i < n; ++i) {
            gr.add(new ArrayList<>());
            ws.add(new ArrayList<>());
            String line = sc.nextLine();
            String[] tokens = line.split(",");
            cname[i] = tokens[0];
            name_to_i.put(cname[i], i);
            must_stay[i] = Integer.parseInt(tokens[1]);
        }

        int e = sc.nextInt(); sc.nextLine();
        for (int i = 0; i < e; ++i) {
            String line = sc.nextLine();
            String[] tokens = line.split(",");
            int h = Integer.parseInt(tokens[2]);
            if (h > 16) continue;
            int c1 = name_to_i.get(tokens[0]);
            int c2 = name_to_i.get(tokens[1]);
            gr.get(c1).add(c2);
            ws.get(c1).add(h);

            gr.get(c2).add(c1);
            ws.get(c2).add(h);
        }

        int ans = doit(1, 0, 0, 16);
        if (ans != 0) build(1, 0, 0, 16);
        else System.out.println("NONE");
    }
}
