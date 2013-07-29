import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Classic Longest Common Subsequence problem.
 * Problem: UVA 10066.
 */

/**
 * @author antonio081014
 * @since Feb 3, 2012, 3:08:02 PM
 */
class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strLine;
        int ncase = 0;
        while ((strLine = br.readLine()) != null) {
            ncase++;
            String[] str = strLine.split(" ");
            int N = Integer.parseInt(str[0]);
            int M = Integer.parseInt(str[1]);
            if (N == 0 && M == 0)
                break;
            String[] strsA = br.readLine().split(" ");
            String[] strsB = br.readLine().split(" ");

            int[][] dp = new int[N + 1][M + 1];
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    if (strsA[i - 1].compareTo(strsB[j - 1]) == 0) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            System.out.println("Twin Towers #" + Integer.toString(ncase));
            System.out.println("Number of Tiles : " + dp[N][M]);
            System.out.println();
        }

    }
}
