import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * UVa 12398 - NumPuzz I
 * Solution:
 * Ad-hoc, implementation.
 */

/**
 * @author antonio081014
 * @since Dec 31, 2011, 3:23:51 PM
 */
public class Main {

    public static final int   N  = 3;
    public static final int[] dx = { 0, 1, 0, -1 };
    public static final int[] dy = { 1, 0, -1, 0 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strLine;
        for (int t = 1; (strLine = br.readLine()) != null; t++) {
            int[][] matrix = new int[N][N];
            for (int i = strLine.length() - 1; i >= 0; i--) {
                int x = (strLine.charAt(i) - 'a') / 3;
                int y = (strLine.charAt(i) - 'a') % 3;
                matrix[x][y] = (matrix[x][y] + 1) % 10;
                for (int j = 0; j < dx.length; j++) {
                    int xx = x + dx[j];
                    int yy = y + dy[j];
                    if (checkBoundary(xx, yy)) {
                        matrix[xx][yy] = (matrix[xx][yy] + 1) % 10;
                    }
                }
            }
            print(t, matrix);
        }
    }

    public static void print(int t, int[][] matrix) {
        System.out.println("Case #" + Integer.toString(t) + ":");
        for (int i = 0; i < N; i++) {
            System.out.print(matrix[i][0]);
            for (int j = 1; j < N; j++) {
                System.out.print(" ");
                System.out.print(matrix[i][j]);
            }
            System.out.println();
        }
    }

    public static boolean checkBoundary(int x, int y) {
        return (x >= 0 && x < N && y >= 0 && y < N);
    }
}
