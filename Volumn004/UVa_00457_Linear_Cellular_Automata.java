import java.util.Scanner;

/**
 * @author antonio081014
 * @since Oct 27, 2011, 4:19:36 PM
 */
class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		final char[] den = { ' ', '.', 'x', 'W' };
		int[] DNA = new int[10];
		int[] current, next;
		int tests = sc.nextInt();
		int i, j, k;
		for (int test = 0; test < tests; test++) {
			for (i = 0; i < 10; i++) {
				DNA[i] = sc.nextInt();
			}

			current = new int[40];
			current[19] = 1;

			for (i = 0; i < 50; i++) {
				next = new int[40];

				for (j = 0; j < 40; j++) {
					System.out.print(den[current[j]]);
				}
				System.out.println();
				for (j = 1; j < 39; j++) {
					k = current[j] + current[j - 1] + current[j + 1];
					next[j] = DNA[k];
				}
				next[0] = DNA[current[0] + current[1]];
				next[39] = DNA[current[38] + current[39]];
				current = next.clone();
			}
			if (test < tests - 1) {
				System.out.println();
			}
		}
	}
}

