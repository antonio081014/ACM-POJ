import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Easy dp problem, cost[x][y] represents the minimum characters need to be added here.
 * 
 * PS: don't make the dp solution while constructing the string solution, since the string operation will consume a lot of time.
 */

/**
 * @author antonio081014
 * @time: Mar 16, 2012, 3:47:59 PM
 */
public class Main {

	public int[][] cost;
	public String[][] record;
	public char[] str;
	public int N;

	public static void main(String[] args) throws Exception {
		Main main = new Main();
		main.run();
		System.exit(0);
	}

	public void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String strLine = null;
		while ((strLine = br.readLine()) != null) {
			str = strLine.toCharArray();
			N = str.length;
			if (N == 0) {
				System.out.println("0 ");
				continue;
			}
			cost = new int[N][N];
			record = new String[N][N];

			init();
			solve(0, N - 1);
			// solve2(0, N - 1);
			System.out.println("" + cost[0][N - 1] + " " + backtrack(0, N - 1));
			// System.out.println("" + cost[0][N - 1] + " " + record[0][N - 1]);
		}
	}

	public void init() {
		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				cost[i][j] = Integer.MAX_VALUE;
				record[i][j] = "";
			}
		}
	}

	public int solve(int x, int y) {
		if (x > y)
			return 0;
		if (cost[x][y] != Integer.MAX_VALUE)
			return cost[x][y];
		if (str[x] == str[y]) {
			cost[x][y] = solve(x + 1, y - 1);
			return cost[x][y];
		}
		int a = solve(x + 1, y);
		int b = solve(x, y - 1);
		return cost[x][y] = 1 + Math.min(a, b);
	}

	public int solve2(int x, int y) {
		if (x > y)
			return 0;
		if (cost[x][y] != Integer.MAX_VALUE)
			return cost[x][y];
		if (str[x] == str[y]) {
			if (x == y) {
				record[x][y] = "" + str[x];
				return cost[x][y] = 0;
			}
			cost[x][y] = solve2(x + 1, y - 1);
			record[x][y] = "" + str[x]
					+ ((x + 1 <= y - 1) ? record[x + 1][y - 1] : "") + str[y];
			return cost[x][y];
		}
		int a = solve2(x + 1, y);
		int b = solve2(x, y - 1);
		if (a <= b) {
			cost[x][y] = 1 + a;
			record[x][y] = "" + str[x] + ((x + 1 <= y) ? record[x + 1][y] : "")
					+ str[x];
		} else {
			cost[x][y] = 1 + b;
			record[x][y] = "" + str[y] + ((x <= y - 1) ? record[x][y - 1] : "")
					+ str[y];
		}
		return cost[x][y];
	}

	public String backtrack(int x, int y) {
		if (x > y)
			return "";
		if (str[x] == str[y]) {
			if (x == y)
				return "" + str[x];
			return "" + str[x] + backtrack(x + 1, y - 1) + str[y];
		}
		if (solve(x + 1, y) <= solve(x, y - 1)) {
			return "" + str[x] + backtrack(x + 1, y) + str[x];
		} else
			return "" + str[y] + backtrack(x, y - 1) + str[y];
	}
}
