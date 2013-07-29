import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * UVA Problem: 10192, Vacation.
 * 
 */

/**
 * @author antonio081014
 * @since Jan 29, 2012, 2:34:19 PM
 */
class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strA;
        String strB;
        for (int t = 1;; t++) {
            strA = br.readLine();
            if (strA.compareTo("#") == 0)
                break;
            strB = br.readLine();
            System.out.println(String.format(
                    "Case #%d: you can visit at most %d cities.", t,
                    LCS(strA, strB)));
        }
    }

    public static int LCS(String a, String b) {
        int M = b.length();
        int N = a.length();
        int[][] dp = new int[N + 1][M + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    dp[i][j] = Math.max(dp[i][j], 1 + dp[i - 1][j - 1]);
                }
                else {
                    dp[i][j] = Math.max(dp[i][j],
                            Math.max(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[N][M];
    }
}
