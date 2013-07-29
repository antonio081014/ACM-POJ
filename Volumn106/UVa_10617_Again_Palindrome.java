import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Problem: UVa 10671.
 * 
 * cost[x][y] represents the ways to construct palindrome string by using the substring from x to y, inclusive.
 * so, if strLine.charAt(x) == strLine.charAt(y),
 * 		cost[x][y] = cost[x+1][y] + cost[x][y-1] - cost[x+1][y-1] + 1 + cost[x+1][y-1];
 * 		since, cost[x+1][y] + cost[x][y-1] will calcuate the cost from x+1 to y-1 twice, we need to remove one.
 * 	   else
 * 		just add cost from x to y-1 and cost from x+1 to y;
 * 
 * PS: 1, the length of string could be up to 60, so there are 2^60 ways at most, we need to use long instead of int.
 * 	   2, the allocation of cost's memory consumes a lot of time. Don't allocate it for each test case.
 */

/**
 * @author antonio081014
 * @time: Mar 16, 2012, 6:01:05 PM
 */
class Main {

	public long[][] cost;
	public String strLine;
	public int N;

	public static void main(String[] args) throws Exception {
		Main main = new Main();
		main.run();
		System.exit(0);
	}

	public void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		cost = new long[100][100];
		while (T-- > 0) {
			strLine = br.readLine();
			N = strLine.length();
			init();
			System.out.println(solve(0, N - 1));
		}
	}

	public void init() {
		// cost = new int[N][N];
		for (int i = 0; i < N; i++) {
			// Manually assignment is faster than the STL
			for (int j = i; j < N; j++)
				cost[i][j] = -1L;
			// Arrays.fill(cost[i], -1);
		}
	}

	public long solve(int x, int y) {
		if (x > y)
			return 0;
		if (cost[x][y] != -1)
			return cost[x][y];
		if (x == y) {
			return cost[x][y] = 1;
		}

		// cost[x][y] = 0;

		if (strLine.charAt(x) == strLine.charAt(y))
			return cost[x][y] = 1 + solve(x + 1, y) + solve(x, y - 1);
		else
			return cost[x][y] = solve(x, y - 1) + solve(x + 1, y)
					- solve(x + 1, y - 1);
	}
}
