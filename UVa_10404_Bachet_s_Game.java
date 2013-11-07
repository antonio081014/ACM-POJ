import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Problem: 10404 - Bachet's Game;
 * Solution: using dynamic programming to solve this problem. cost[x] represents if the user could win with x amount of money.
 * PS: check the strline length of input will avoid the runtime error.
 */

/**
 * @author antonio081014
 * @time: Mar 23, 2012, 5:26:07 PM
 */
class Main {

    private int N;
    private int M;
    private int[] stonesSet;

    private boolean[] cost;

    public static void main(String[] args) throws Exception {
	Main main = new Main();
	main.run();
	System.exit(0);
    }

    public void run() throws Exception {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String strLine;
	cost = new boolean[1000001];
	String[] strs;
	while ((strLine = br.readLine()) != null && strLine.length() > 0) {
	    strs = strLine.split(" ");
	    N = Integer.parseInt(strs[0]);
	    M = Integer.parseInt(strs[1]);
	    stonesSet = new int[M + 1];

	    for (int i = 0; i < M; i++)
		stonesSet[i] = Integer.parseInt(strs[i + 2]);

	    init();

	    for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
		    if (i == stonesSet[j]) {
			cost[i] = true;
			break;
		    } else if (i > stonesSet[j] && !cost[i - stonesSet[j]]) {
			cost[i] = true;
			break;
		    }
		}
	    }

	    if (cost[N])
		System.out.println("Stan wins");
	    else
		System.out.println("Ollie wins");
	}
    }

    public void init() {
	for (int i = 0; i <= N; i++)
	    cost[i] = false;
    }

    public boolean solve(int amount) {
	// if (cost[amount] != )
	// return cost[amount];
	for (int i = 0; i < M; i++) {
	    if (amount == stonesSet[i])
		return cost[amount] = true;
	    if (amount > stonesSet[i] && solve(amount - stonesSet[i]) == false)
		return cost[amount] = true;
	}
	return cost[amount] = false;
    }
}
