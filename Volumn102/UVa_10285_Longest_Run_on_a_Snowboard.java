import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * It's actually the first DP problem I ever solved.
 * How can I forgot this one. :)
 */

/**
 * @author antonio081014
 * @since Feb 28, 2012, 11:26:08 AM
 */
class Main {

    public static final int[] xx = { 1, 0, -1, 0 };
    public static final int[] yy = { 0, 1, 0, -1 };

    public int[][]            grid;
    public int[][]            cost;
    public int                h;
    public int                w;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.run();
    }

    public void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            String[] str = br.readLine().split("\\s");
            String name = str[0];
            h = Integer.parseInt(str[1]);
            w = Integer.parseInt(str[2]);
            grid = new int[h][w];
            cost = new int[h][w];
            for (int i = 0; i < h; i++) {
                str = br.readLine().split("\\s");
                for (int j = 0; j < w; j++) {
                    grid[i][j] = Integer.parseInt(str[j]);
                    cost[i][j] = -1;
                }
            }
            int max = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++)
                    max = Math.max(max, calculate(i, j));
            }
            System.out.println(name + ": " + max);
        }
    }

    public int calculate(int x, int y) {
        if (cost[x][y] != -1)
            return cost[x][y];
        int max = 0;
        for (int i = 0; i < 4; i++) {
            if (x + xx[i] >= 0 && x + xx[i] < h && y + yy[i] >= 0
                    && y + yy[i] < w && grid[x][y] > grid[x + xx[i]][y + yy[i]])
                max = Math.max(max, calculate(x + xx[i], y + yy[i]));
        }
        return cost[x][y] = max + 1;
    }
}
