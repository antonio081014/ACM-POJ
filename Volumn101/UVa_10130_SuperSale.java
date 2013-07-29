import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Classical one, just like the first DP problem I had yrs ago.
 */

/**
 * @author antonio081014
 * @since Feb 28, 2012, 10:50:01 AM
 */
class Main {

    public int[][] cost;
    public int[]   price;
    public int[]   weight;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.run();
    }

    public void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            price = new int[N];
            weight = new int[N];
            cost = new int[N][4000];
            for (int i = 0; i < N; i++) {
                String[] str = br.readLine().split("\\s");
                price[i] = Integer.parseInt(str[0]);
                weight[i] = Integer.parseInt(str[1]);
            }
            int P = Integer.parseInt(br.readLine());
            int sum = 0;
            for (int i = 0; i < P; i++) {
                sum += solve(N, Integer.parseInt(br.readLine()));
            }
            System.out.println(sum);
        }
    }

    /**
     * Calculate the maximum price this memeber could have.
     * 
     * @param int N: number of family member;
     * @param int w: the weight of that member could have.
     * @return int: maximum price.
     * */
    public int solve(int N, int w) {
        return calculate(N - 1, w);
    }

    /**
     * Calculate the maximum price for the first idx items with max weight w;
     * */
    public int calculate(int idx, int w) {
        if (idx < 0)
            return 0;
        if (cost[idx][w] != 0)
            return cost[idx][w];
        int y = calculate(idx - 1, w);
        if (w >= weight[idx]) {
            int x = calculate(idx - 1, w - weight[idx]) + price[idx];
            return cost[idx][w] = Math.max(x, y);
        }
        return cost[idx][w] = y;
    }
}

