import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * The notes from algorithmist is very important;
 * Plus, the essential part of this problem is very easy, just Longest Common
 * Subsequence.
 */

/**
 * @author antonio081014
 * @since Jan 28, 2012, 7:42:17 PM
 */
class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] inorder = br.readLine().split(" ");
        inorder = reorder(inorder);
        String strLine;
        while ((strLine = br.readLine()) != null) {
            String[] outorder = strLine.split(" ");
            outorder = reorder(outorder);
            System.out.println(LCS(inorder, outorder, N));
        }
    }

    public static String[] reorder(String[] list) {
        String[] ret = new String[list.length];
        for (int i = 0; i < list.length; i++) {
            ret[Integer.parseInt(list[i]) - 1] = Integer.toString(i + 1);
        }
        return ret;
    }

    public static int LCS(String[] a, String[] b, int N) {
        int cnt = 0;
        int[][] dp = new int[N + 1][N + 1];
        // int[][] count = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            if (a[i - 1].compareTo(b[i - 1]) == 0)
                cnt++;
            for (int j = 1; j <= N; j++) {
                if (a[i - 1].compareTo(b[j - 1]) == 0) {
                    // if (dp[i][j] * count[i][j] < (1 + dp[i - 1][j - 1])
                    // * count[i - 1][j - 1]) {
                    // dp[i][j] = 1 + dp[i - 1][j - 1];
                    // count[i][j] = count[i - 1][j - 1];
                    // }
                    // else if (dp[i][j] * count[i][j] == (1 + dp[i - 1][j - 1])
                    // * count[i - 1][j - 1]) {
                    // count[i][j]++;
                    // }
                    dp[i][j] = Math.max(dp[i][j], 1 + dp[i - 1][j - 1]);
                }
                else {
                    // if (dp[i][j] * count[i][j] < (dp[i - 1][j])
                    // * count[i - 1][j]) {
                    // dp[i][j] = dp[i - 1][j];
                    // count[i][j] = count[i - 1][j];
                    // }
                    // if (dp[i][j] * count[i][j] < (dp[i][j - 1])
                    // * count[i][j - 1]) {
                    // dp[i][j] = dp[i][j - 1];
                    // count[i][j] = count[i][j - 1];
                    // }
                    dp[i][j] = Math.max(dp[i][j],
                            Math.max(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[N][N];
    }
}
