import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 * Problem: 531, Compromise.
 * Using Longest Common Subsequence.
 */

/**
 * @author antonio081014
 * @since Jan 29, 2012, 4:55:25 PM
 */
class Main {

    public static List<String> listA;
    public static List<String> listB;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strLine;
        for (int t = 0;; t++) {
            strLine = br.readLine();
            if (strLine == null || strLine.length() == 0
                    || strLine.compareTo("#") == 0)
                break;
            listA = new ArrayList<String>();
            listB = new ArrayList<String>();

            while (strLine.compareTo("#") != 0) {
                String[] strs = strLine.split("\\s");
                for (int i = 0; i < strs.length; i++)
                    listB.add(strs[i]);
                strLine = br.readLine();
            }
            do {
                strLine = br.readLine();
                String[] strs = strLine.split("\\s");
                for (int i = 0; i < strs.length; i++)
                    listA.add(strs[i]);
            } while (strLine.compareTo("#") != 0);
            print(LCS());
        }
    }

    public static int[][] LCS() {
        int N = listA.size();
        int M = listB.size();
        int[][] dp = new int[N + 1][M + 1];
        int[][] parent = new int[N + 1][M + 1];

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (listA.get(i - 1).compareTo(listB.get(j - 1)) == 0) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    parent[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                    parent[i][j] = 2;
                    if (dp[i][j - 1] > dp[i - 1][j]) {
                        dp[i][j] = dp[i][j - 1];
                        parent[i][j] = 3;
                    }
                }
            }
        }
        return parent;
    }

    public static void print(int[][] parent) {
        List<String> list = new ArrayList<String>();
        for (int i = listA.size(), j = listB.size(); i > 0 && j > 0;) {
            if (parent[i][j] == 1) {
                list.add(listA.get(i - 1));
                i--;
                j--;
            }
            else {
                if (parent[i][j] == 2)
                    i--;
                else if (parent[i][j] == 3)
                    j--;
            }
        }
        for (int i = list.size() - 1; i > 0; i--)
            System.out.print(list.get(i) + " ");
        System.out.println(list.get(0));
    }
}

