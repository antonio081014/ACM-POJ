import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * 
 */

/**
 * @author antonio081014
 * @time: Mar 2, 2012, 3:30:59 PM
 */
class Main {

	public int[][] cost;
	public int[][] items;
	public int M;
	public int C;

	public static void main(String[] args) throws Exception {
		Main main = new Main();
		main.run();
		System.exit(0);
	}

	public void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			String[] str = br.readLine().split("\\s");
			M = Integer.parseInt(str[0]);
			C = Integer.parseInt(str[1]);
			cost = new int[C][M + 1];
			items = new int[C][23];
			for (int i = 0; i < C; i++) {
				str = br.readLine().split("\\s");
				for (int j = 0; j < str.length; j++)
					items[i][j] = Integer.parseInt(str[j]);
			}
			solve(0, M);
			if (cost[0][M] > 0)
				System.out.println(cost[0][M]);
			else
				System.out.println("no solution");
		}
	}

	public int solve(int idx, int total) {
		if (total < 0)
			return Integer.MIN_VALUE;
		if (idx == C && total >= 0) {
			return 0;
		}
		if (cost[idx][total] > 0)
			return cost[idx][total];
		int max = Integer.MIN_VALUE;
		for (int i = 1; i <= items[idx][0]; i++) {
			max = Math.max(max, solve(idx + 1, total - items[idx][i])
					+ items[idx][i]);
		}
		return cost[idx][total] = max;
	}
}
