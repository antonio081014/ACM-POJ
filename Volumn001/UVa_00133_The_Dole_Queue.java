import java.util.Scanner;

/**
 * Simulation;
 */

/**
 * @author antonio081014
 * @since Feb 24, 2012, 12:24:12 PM
 */
class Main {

    public boolean[] mark;

    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
        System.exit(0);
    }

    public int next(int start, int N, int k) {
        int count = 0;
        while (count < k) {
            if (!mark[start])
                count++;
            start = (start + 1) % N;
        }
        return (start - 1 + N) % N;
    }

    public int prev(int start, int N, int m) {
        int count = 0;
        while (count < m) {
            if (!mark[start])
                count++;
            start = (start - 1 + N) % N;
        }
        return (start + 1) % N;
    }

    public void solve() {
        Scanner sc = new Scanner(System.in);
        int N;
        int k;
        int m;
        while (true) {
            N = sc.nextInt();
            k = sc.nextInt();
            m = sc.nextInt();
            if (N + m + k == 0)
                break;
            // k %= N;
            // m %= N;
            mark = new boolean[N];
            String str = "";
            for (int i = 0, j = N - 1, count = 0; count < N;) {
                i = next(i, N, k);
                j = prev(j, N, m);
                if (i == j) {
                    str += String.format("%3d,", i + 1);
                    mark[i] = true;
                    count++;
                }
                else {
                    str += String.format("%3d%3d,", i + 1, j + 1);
                    mark[i] = true;
                    mark[j] = true;
                    count += 2;
                }
            }
            System.out.println(str.substring(0, str.length() - 1));
        }
    }
}
