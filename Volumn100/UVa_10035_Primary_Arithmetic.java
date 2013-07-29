import java.util.Scanner;

/**
 * 
 */

/**
 * @author antonio081014
 * @time Sep 12, 2012, 8:33:31 PM
 */
class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
		System.exit(0);
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		long a, b;
		do {
			a = sc.nextInt();
			b = sc.nextInt();
			if (a == 0 && b == 0) {
				break;
			}
			int count = carry(Long.toString(a), Long.toString(b));
			if (count == 0)
				System.out.println("No carry operation.");
			else if (count == 1)
				System.out.println("1 carry operation.");
			else
				System.out.println(Integer.toString(count)
						+ " carry operations.");
		} while (a != 0 || b != 0);
	}

	public int carry(String a, String b) {
		int count = 0;
		int i, j;
		int flag = 0;
		for (i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; i--, j--) {
			int sum = (a.charAt(i) - '0') + (b.charAt(j) - '0') + flag;
			if (sum > 9)
				count++;
			flag = sum / 10;
		}
		for (; i >= 0; i--) {
			int sum = (a.charAt(i) - '0') + flag;
			if (sum > 9)
				count++;
			flag = sum / 10;
		}
		for (; j >= 0; j--) {
			int sum = (b.charAt(j) - '0') + flag;
			if (sum > 9)
				count++;
			flag = sum / 10;
		}
		return count;
	}
}

