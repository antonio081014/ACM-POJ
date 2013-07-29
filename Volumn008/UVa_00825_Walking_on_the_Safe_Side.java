import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Easy DP problem;
 * cost[x][y] is the total number of ways to reach (x,y)
 * cost[x][y] could be reached by one step left or one step up.
 * so, cost[x][y] = cost[x-1][y-1];
 * 
 * Test Input:
 * 10
 * 
 * 10 9
 * 1 1 3 5 7 9
 * 2
 * 3 1 3 5 7 9
 * 4
 * 5 1 3 5 7 9
 * 6
 * 7 1 3 5 7 9
 * 8
 * 9 1 3 5 7 9
 * 10
 * 
 * 4 5
 * 1
 * 2 2
 * 3 3 5
 * 4
 * 
 * 1 1
 * 1
 * 
 * 1 8
 * 1
 * 
 * 1 8
 * 1 4
 * 
 * 8 1
 * 1
 * 2
 * 3
 * 4
 * 5
 * 6
 * 7
 * 8
 * 
 * 8 1
 * 1
 * 2
 * 3
 * 4 1
 * 5
 * 6
 * 7
 * 8
 * 
 * 4 4
 * 1
 * 2
 * 3
 * 4
 * 
 * 8 8
 * 1
 * 2
 * 3 5
 * 4 1 4
 * 5 3 6
 * 6 2 7
 * 7 8
 * 8
 * 
 * 8 8
 * 1
 * 2 6
 * 3 2
 * 4 5
 * 5 1
 * 6 3
 * 7 5 8
 * 8 5
 * 
 * Test Output:
 * 0
 * 
 * 4
 * 
 * 1
 * 
 * 1
 * 
 * 0
 * 
 * 1
 * 
 * 0
 * 
 * 20
 * 
 * 0
 * 
 * 233
 */

/**
 * @author antonio081014
 * @since Feb 28, 2012, 12:01:37 PM
 */
class Main {

    public boolean[][] unsafe;
    public long[][]    cost;
    public int         h;
    public int         w;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.run();
    }

    public void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            br.readLine();
            String[] str = br.readLine().split("\\s");
            h = Integer.parseInt(str[0]);
            w = Integer.parseInt(str[1]);
            unsafe = new boolean[h][w];
            cost = new long[h][w];
            for (int i = 0; i < h; i++) {
                str = br.readLine().split("\\s");
                int a = Integer.parseInt(str[0]);
                for (int j = 1; j < str.length; j++)
                    unsafe[a - 1][Integer.parseInt(str[j]) - 1] = true;
            }
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++)
                    cost[i][j] = 0L;
                // cost[i][j] = (i == 0 ? 1L : -1L);
                // cost[i][0] = 1L;
            }
            cost[0][0] = 1L;
            // print();
            System.out.println(calculate(h - 1, w - 1));
            if (T >= 1)
                System.out.println();
        }
    }

    public void print() {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                System.out.print(" " + cost[i][j]);
            }
            System.out.println();
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                System.out.print(" " + unsafe[i][j]);
            }
            System.out.println();
        }
    }

    public long calculate(int x, int y) {
        if (unsafe[x][y])
            return cost[x][y] = 0L;
        if (cost[x][y] > 0L)
            return cost[x][y];
        long max = 0L;
        if (x > 0 && !unsafe[x - 1][y])
            max += calculate(x - 1, y);
        if (y > 0 && !unsafe[x][y - 1])
            max += calculate(x, y - 1);
        return cost[x][y] = max;
    }
}

