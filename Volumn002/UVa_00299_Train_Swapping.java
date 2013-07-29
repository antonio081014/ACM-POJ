import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @author antonio081014
 * @since Oct 23, 2011, 1:05:45 PM
 */
class Main {

	/**
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		solve();
	}

	public static void solve() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer stk = new StringTokenizer(br.readLine());
			int[] nums = new int[n];
			for (int i = 0; i < n; i++) {
				nums[i] = Integer.parseInt(stk.nextToken());
			}
			System.out.println("Optimal train swapping takes "
					+ bubbleSort(nums) + " swaps.");
		}
	}

	public static int bubbleSort(int[] nums) {
		int count = 0;
		for (int i = 0; i < nums.length; i++) {
			for (int j = 0; j < nums.length - 1; j++) {
				if (nums[j] > nums[j + 1]) {
					count++;
					nums[j] ^= nums[j + 1];
					nums[j + 1] ^= nums[j];
					nums[j] ^= nums[j + 1];
				}
			}
		}
		return count;
	}

}

