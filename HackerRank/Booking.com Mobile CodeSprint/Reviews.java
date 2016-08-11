import java.io.*;
import java.util.*;

public class Reviews {

    static String passions[] = new String[128];
    static List<HashMap<Integer, Integer>> reviewer_scores = new ArrayList<>(128);

    static final long june15 = 1465948800L;
    static final long july15 = 1468540800L;


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(); sc.nextLine();
        for (int i = 0; i < n; ++i) {
            passions[i] = sc.nextLine();
            passions[i] = passions[i].toLowerCase();
            reviewer_scores.add(i, new HashMap<>());
        }

        for (int i = 0; i < m; ++i) {
            int id; Long timestamp;
            id = sc.nextInt(); timestamp = sc.nextLong(); sc.nextLine();
            String body = sc.nextLine();
            body = body.toLowerCase();

            int review_score = 0;

            if (june15 <= timestamp && timestamp <= july15) review_score += 20;
            else review_score += 10;

            if (body.length() >= 100) review_score += 20;
            else review_score += 10;

            for (int j = 0; j < n; ++j) {
                if (body.contains(passions[j])) {
                    int reviewer_score = review_score;
                    if (reviewer_scores.get(j).containsKey(id)) reviewer_score += reviewer_scores.get(j).get(id);
                    reviewer_scores.get(j).put(id, reviewer_score);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            int best = -1, bid = -1;
            for (Map.Entry<Integer, Integer> entry : reviewer_scores.get(i).entrySet()) {
                if (entry.getValue() > best || (entry.getValue() == best && entry.getKey() < bid)) {
                    best = entry.getValue();
                    bid = entry.getKey();
                }
            }
            System.out.println(bid);
        }
    }
}
