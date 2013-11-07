import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * 
 */

/**
 * @author antonio081014
 * @since Feb 21, 2012, 10:55:26 PM
 */
class Main {

    public HashMap<Integer, Integer> map;
    public int[]                     teams;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.solve();
        System.exit(0);
    }

    public void solve() throws Exception {
        Scanner sc = new Scanner(System.in);
        map = new HashMap<Integer, Integer>();
        int N;
        int ncase = 0;
        while ((N = sc.nextInt()) != 0) {
            System.out.println("Scenario #" + (++ncase));
            LinkedList<Integer> q = new LinkedList<Integer>();
            teams = new int[N];
            Arrays.fill(teams, -1);
            for (int i = 0; i < N; i++) {
                int m = sc.nextInt();
                for (int j = 0; j < m; j++)
                    map.put(sc.nextInt(), i);
            }

            oneCase(q, sc, N);
            System.out.println();
        }
    }

    public void oneCase(LinkedList<Integer> q, Scanner sc, int N) {
        String strLine;
        int start = 0;
        while ((strLine = sc.next()) != null) {
            if (strLine.compareTo("STOP") == 0)
                return;
            if (strLine.compareTo("ENQUEUE") == 0) {
                int a = sc.nextInt();
                int group = map.get(a);
                if (teams[group] == -1) {
                    q.add(a);
                    teams[group] = q.size() - 1;
                }
                else {
                    q.add(teams[group] + 1, a);
                    teams[group]++;
                    // This is the part consume my time;
                    // but I don't know how to improve it without pointers.
                    for (int i = 0; i < N; i++) {
                        if (i != group && teams[group] <= teams[i]) {
                            teams[i]++;
                        }
                    }
                }
            }
            else {
                int a = q.get(start);
                if (teams[map.get(a)] <= start)
                    teams[map.get(a)] = -1;
                start++;
                System.out.println(a);
            }
        }
    }
}

