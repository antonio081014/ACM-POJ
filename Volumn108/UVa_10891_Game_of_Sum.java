import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * cost[x][y][z] represents the maximum sum of array from x to y for user z(0
 * for user A, 1 for user B).(y>=x)
 * 
 * cost[x][y][z] = sum from x to y (inclusive) subtract the cost[x][index][z^1]
 * or cost[index][y][z^1];
 */

/**
 * @author antonio081014
 * @time: Mar 14, 2012, 3:35:03 PM
 */
class Main {

    public static final int SIZE = 110;

    // Mark if (x,y,z) is visited or not;
    public boolean[][][]    mark;
    // The maximum sum of array from x to y for user z. (y>=x)
    public int[][][]        cost;
    public int[]            data;
    public int              N;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.run();
        System.exit(0);
    }

    public void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        cost = new int[SIZE + 1][SIZE + 1][2];
        mark = new boolean[SIZE + 1][SIZE + 1][2];
        data = new int[SIZE + 1];
        while ((N = Integer.parseInt(br.readLine())) != 0) {
            StringTokenizer tz = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                data[i] = data[i - 1] + Integer.parseInt(tz.nextToken());
            }

            init();
            System.out.println(2 * solve(1, N, 0) - data[N]);
        }
    }

    public void init() {
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                for (int z = 0; z < 2; z++) {
                    cost[i][j][z] = Integer.MIN_VALUE;
                    mark[i][j][z] = false;
                }
    }

    public int solve(int x, int y, int z) {
        if (mark[x][y][z])
            return cost[x][y][z];
        if (x > y || x == 0 || y == 0) {
            mark[x][y][z] = true;
            return cost[x][y][z] = 0;
        }

        // The most remarkable part of this solution;
        for (int tmp = 1; tmp <= y - x + 1; tmp++) {
            cost[x][y][z] = Math.max(cost[x][y][z], data[y] - data[x - 1]
                    - solve(x + tmp, y, z ^ 1));
            cost[x][y][z] = Math.max(cost[x][y][z], data[y] - data[x - 1]
                    - solve(x, y - tmp, z ^ 1));
        }
        mark[x][y][z] = true;
        return cost[x][y][z];
    }
}
