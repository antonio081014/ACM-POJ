import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * 尽量避免在经常调用的方法，循环中new对象，
 * 由于系统不仅要花费时间来创建对象，
 * 而且还要花时间对这些对象进行垃圾回收和处理，
 * 在我们可以控制的范围内，最大限度的重用对象，
 * 最好能用基本的数据类型或数组来替代对象。
 */

/**
 * @author antonio081014
 * @time: Mar 13, 2012, 9:10:23 AM
 */
class Main {

	public int[] chopsticks;
	public int K;
	public int N;
	public long[][] cost;

	public static void main(String[] args) throws Exception {
		Main main = new Main();
		main.run();
		System.exit(0);
	}

	public void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		cost = new long[5000][1008 + 1];
		chopsticks = new int[5000];
		while (T-- > 0) {
			String[] str = br.readLine().split("\\s");
			K = Integer.parseInt(str[0]) + 8;
			N = Integer.parseInt(str[1]);

			str = br.readLine().split("\\s");
			for (int i = 0; i < N; i++)
				chopsticks[N - i - 1] = Integer.parseInt(str[i]);
			// for (int i = 0; i < N; i++)
			// System.out.println(chopsticks[i]);
			init();

			solve();
			// print();
		}
	}

	public void print() {
		for (int i = 0; i < N; i++, System.out.println())
			for (int j = 0; j <= K; j++)
				System.out.print(cost[i][j] + " ");
	}

	public void init() {
		for (int i = 0; i < N; i++)
			for (int j = 0; j <= K; j++)
				if (j != 0)
					cost[i][j] = Long.MAX_VALUE;
				else
					cost[i][j] = 0;
	}

	public void solve() {
		for (int i = 0; i < N; i++) {
			for (int j = 1; 3 * j <= i + 1 && j <= K; j++) {
				cost[i][j] = cost[i - 2][j - 1]
						+ (chopsticks[i] - chopsticks[i - 1])
						* (chopsticks[i] - chopsticks[i - 1]);
				if (3 * j < i + 1 && cost[i][j] > cost[i - 1][j])
					cost[i][j] = cost[i - 1][j];
			}
		}
		System.out.println(cost[N - 1][K]);
	}

}
