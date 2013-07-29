import java.util.Scanner;

/**
 * 
 */

/**
 * @author antonio081014
 * @time Feb 10, 2013, 2:43:55 PM <br>
 * 
 *       Problem: 10684 - The jackpot
 */
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Main main = new Main();
		main.run();
		System.exit(0);
	}

	private void run() {
		Scanner sc = new Scanner(System.in);
		int N;
		while ((N = sc.nextInt()) != 0) {
			int sum = 0;
			int max = 0;
			while (N-- > 0) {
				sum += sc.nextInt();
				if (sum < 0) {
					sum = 0;
				}
				max = Math.max(sum, max);
			}
			if (max <= 0) {
				System.out.println("Losing streak.");
			} else {
				System.out.println(String.format(
						"The maximum winning streak is %d.", max));
			}
		}
	}

}

