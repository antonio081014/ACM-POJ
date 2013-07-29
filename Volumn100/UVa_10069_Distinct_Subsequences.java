import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 * 
 */

/**
 * @author antonio081014
 * @since Feb 12, 2012, 11:56:28 AM
 */
class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(in.readLine());
        while (tc-- > 0) {
            String a = in.readLine();
            String b = in.readLine();
            BigInteger[][] res = new BigInteger[a.length() + 1][b.length() + 1];
            for (int i = 0; i <= a.length(); i++) {
                for (int j = 0; j < b.length(); j++)
                    res[i][j] = BigInteger.ZERO;
                res[i][b.length()] = BigInteger.ONE;
            }
            for (int i = a.length() - 1; i >= 0; i--)
                for (int j = b.length() - 1; j >= 0; j--) {
                    res[i][j] = res[i + 1][j];
                    if (a.charAt(i) == b.charAt(j))
                        res[i][j] = res[i][j].add(res[i + 1][j + 1]);
                }
            System.out.println(res[0][0]);
        }
    }
}
