import java.io.*;
import java.util.*;

public class EventRaffle {

    public static final int MAXN = 128;

    static List<List<String>> person = new ArrayList<>(MAXN);
    static List<List<String>> event = new ArrayList<>(MAXN);

    static List<List<Integer>> gr = new ArrayList<>(MAXN);
    static boolean seen[] = new boolean[MAXN];
    static int m[] = new int[MAXN], m1[] = new int[MAXN];

    static int N;

    static int dfs(int u) {
        if (u < 0) return 1;
        if (seen[u]) return 0;
        seen[u] = true;
        for (int v : gr.get(u)) {
            if (dfs(m1[v]) != 0) {
                m[u] = v;
                m1[v] = u;
                return 1;
            }
        }
        return 0;
    }

    static int dfsExp(int u) {
        for (int i = 0; i < N; ++i) seen[i] = false;
        return dfs(u);
    }

    static int bipMatch() {
        for (int i = 0; i < N; ++i) { m[i] = -1; m1[i] = -1; }
        int aug, ans = 0;
        do {
            aug = 0;
            boolean first = true;
            for (int i = 0; i < N; ++i) if (m[i] < 0) {
                if (first) aug += dfsExp(i);
                else aug += dfs(i);
                first = false;
            }
            ans += aug;
        } while (aug > 0);
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        for (int i = 0; i < N; ++i) {
            int ax = sc.nextInt(), m = sc.nextInt();
            person.add(i, new ArrayList<>(m));
            while (m-->0) {
                person.get(i).add(sc.next());
            }
            person.get(i).sort(String::compareTo);
        }

        for (int i = 0; i < N; ++i) {
            gr.add(new ArrayList<>());
            int m = sc.nextInt();
            event.add(i, new ArrayList<>(m));
            while (m-->0) {
                event.get(i).add(sc.next());
            }
            event.get(i).sort(String::compareTo);
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int ii = 0, jj = 0, si = person.get(i).size(), sj = event.get(j).size();
                while (ii < si && jj < sj) {
                    int cc = person.get(i).get(ii).compareTo(event.get(j).get(jj));
                    if (cc == 0) {
                        gr.get(i).add(j);
                        break;
                    } else if (cc < 0) {
                        ii++;
                    } else jj++;
                }
            }
        }
        System.out.println(bipMatch());
    }
}
