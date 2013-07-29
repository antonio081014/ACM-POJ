import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * burger[i]: burgers can be ate in time of i;
 */

/**
 * @author antonio081014
 * @since Feb 28, 2012, 10:09:02 AM
 */
class Main {

    public static final int size = 10000;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.solve();
        System.exit(0);
    }

    public void solve() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strLine;
        while ((strLine = br.readLine()) != null) {
            String[] str = strLine.split("\\s");
            int m = Integer.parseInt(str[0]);
            int n = Integer.parseInt(str[1]);
            int t = Integer.parseInt(str[2]);
            solveCase(m, n, t);
        }
    }

    public void solveCase(int m, int n, int t) {
        // In case m is greater than t, use size + 1 to allocate the new size of
        // array;
        int[] burger = new int[size + 1];
        burger[m] = 1;
        burger[n] = 1;
        for (int i = 1; i <= t; i++) {
            if (i > m && burger[i - m] != 0) {
                burger[i] = Math.max(burger[i], 1 + burger[i - m]);
            }
            if (i > n && burger[i - n] != 0) {
                burger[i] = Math.max(burger[i], 1 + burger[i - n]);
            }
        }

        if (burger[t] > 0) {
            System.out.println("" + burger[t]);
            return;
        }
        for (int i = t; i >= 0; i--) {
            if (burger[i] > 0) {
                System.out.println(String.format("%d %d", burger[i], t - i));
                return;
            }
        }
        System.out.println("0 " + t);
    }

}

