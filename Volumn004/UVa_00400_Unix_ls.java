import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * @author antonio081014
 * @since Oct 23, 2011, 1:42:53 PM
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
		String strLine;
		while ((strLine = br.readLine()) != null) {
			int N = Integer.parseInt(strLine);
			List<String> list = new ArrayList<String>();
			int maxlen = 0;
			for (int i = 0; i < N; i++) {
				list.add(br.readLine());
				maxlen = Math.max(maxlen, list.get(i).length());
			}
			Collections.sort(list);
			display(list, 60, maxlen, 2);
		}
	}

	public static void display(List<String> list, int length, int maxLength,
			int offset) {
		int cols = (length + offset) / (maxLength + offset);
		int rows = (int) Math.ceil(1.0 * list.size() / cols);
		for (int i = 0; i < length; i++)
			System.out.print("-");
		System.out.println();
		for (int i = 0; i < rows; i++) {
			for (int j = i; j < list.size(); j += rows) {
				System.out.print(list.get(j));
				if (j + rows < list.size()) {
					for (int k = list.get(j).length(); k < maxLength + offset; k++)
						System.out.print(" ");
				}
			}
			System.out.println();
		}
	}
}
