import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Problem: uva11151, Longest Palindrome.
 * Here cost[x][y] represents the maximum length of the existing palindrome string.
 * So our decision is made by the equalness of characters at the two ends.
 */

/**
 * @author antonio081014
 * @time: Mar 16, 2012, 11:28:38 AM
 */
class Main {

	private int[][] cost;
	private char[] str;
	private int N;

	public static void main(String[] args) throws Exception {
		Main main = new Main();
		main.run();
		System.exit(0);
	}

	public void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		cost = new int[1000][1000];
		String strLine = null;
		while (T-- > 0) {
			// long start = Calendar.getInstance().getTimeInMillis();
			strLine = br.readLine();
			str = strLine.toCharArray();
			N = str.length;
			if (N == 1 || N == 0) {
				System.out.println(N);
				continue;
			}
			init(N);
			System.out.println(solve(0, N - 1));
			// System.out.println("Time consumed: " + strLine + ", "
			// + (Calendar.getInstance().getTimeInMillis() - start));
		}
	}

	public void init(int N) {
		for (int i = 0; i < N; i++)
			for (int j = i; j < N; j++)
				cost[i][j] = -1;
	}

	public int solve(int x, int y) {
		if (x > y)
			return 0;
		else if (cost[x][y] != -1)
			return cost[x][y];
		else if (x == y)
			return cost[x][y] = 1;
		else {
			if (str[x] == str[y]) {
				return cost[x][y] = 2 + solve(x + 1, y - 1);
			} else
				return cost[x][y] = Math.max(solve(x + 1, y), solve(x, y - 1));
		}
	}
}
