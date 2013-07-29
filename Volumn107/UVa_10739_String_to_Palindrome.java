import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * cost[x][y] represents the unit of operations needed to make the string palindrome.
 * Here, two operations are needed.
 * 1st, remove the character, since add one character at one side is the same as removing one on the other side.
 * 		So here, it could be 1 unit operation + minimum cost of making string from x+1 to j, or x to j-1 as palindrom.
 * 			as Math.min(1 + solve(x+1, j), 1 + solve(x, j-1))
 * 2ne, change the character.
 * 		So here, it could be 1 + solve(x+1, j-1).
 * 
 * So, cost[x][y] could be:
 * 		1st, 0, if y < x;
 * 		2nd, cost[x+1][y-1], if strline[x] == strline[y]
 * 		3rd, 1 + min(cost[x+1][y-1], cost[x+1][y], cost[x][y-1])
 */

/**
 * @author antonio081014
 * @time: Mar 19, 2012, 11:17:56 AM
 */
class Main {

	public int[][] cost;
	public String strLine;
	public int N;

	public static void main(String[] args) throws Exception {
		Main main = new Main();
		main.run();
		System.exit(0);
	}

	public void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		cost = new int[1001][1001];
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			strLine = br.readLine();
			N = strLine.length();
			init();
			System.out.println("Case " + t + ": " + solve(0, N - 1));
		}
	}

	public void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				System.out.print(" " + cost[i][j]);
			System.out.println();
		}
	}

	public void init() {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cost[i][j] = -1;
	}

	public int solve(int x, int y) {
		if (y < x)
			return 0;
		if (cost[x][y] != -1)
			return cost[x][y];
		if (x == y)
			return cost[x][y] = 0;
		if (strLine.charAt(x) == strLine.charAt(y)) {
			return cost[x][y] = solve(x + 1, y - 1);
		} else
			return cost[x][y] = 1 + Math.min(solve(x + 1, y - 1),
					Math.min(solve(x + 1, y), solve(x, y - 1)));
	}
}
