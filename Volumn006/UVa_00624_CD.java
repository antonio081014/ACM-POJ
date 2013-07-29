import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * 
 */

/**
 * @author antonio081014
 * @since Feb 28, 2012, 1:02:33 AM
 */
class Main {

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.solve();
    }

    public void solve() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strLine;
        while ((strLine = br.readLine()) != null) {
            String[] str = strLine.split("\\s");
            int length = Integer.parseInt(str[0]);
            int N = Integer.parseInt(str[1]);
            int[] number = new int[N];
            for (int i = 0; i < N; i++)
                number[i] = Integer.parseInt(str[2 + i]);
            int max = 0;
            int mask = 0;
            for (int i = 0; i < (1 << N); i++) {
                int sum = 0;
                for (int j = 0; j < N; j++) {
                    if (((i >> j) & 1) == 1) {
                        sum += number[j];
                    }
                }
                if (sum > max && sum <= length) {
                    max = sum;
                    mask = i;
                }
            }
            max = 0;
            for (int i = 0; i < N; i++) {
                if (((mask >> i) & 1) == 1) {
                    max += number[i];
                    System.out.print("" + number[i] + " ");
                }
            }
            System.out.println("sum:" + max);
        }
    }
}
