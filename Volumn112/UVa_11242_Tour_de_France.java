import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;

/**
 * 
 */

/**
 * @author antonio081014
 * @time Jan 31, 2013, 10:35:28 PM
 */
public class Main {

	public static void main(String[] args) throws Exception {
		Main main = new Main();
		main.run();
		System.exit(0);
	}

	public void run() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = null;
		while ((line = br.readLine()) != null && line.compareTo("0") != 0) {
			String[] strs = line.split("\\s");
			int[] front = new int[Integer.parseInt(strs[0])];
			int[] rear = new int[Integer.parseInt(strs[1])];
			strs = br.readLine().split("\\s");
			for (int i = 0; i < front.length; i++) {
				front[i] = Integer.parseInt(strs[i]);
			}
			strs = br.readLine().split("\\s");
			for (int i = 0; i < rear.length; i++)
				rear[i] = Integer.parseInt(strs[i]);
			System.out.println(String.format("%.2f",
					getMax(generateRatio(front, rear))));
		}
	}

	private LinkedList<Double> generateRatio(int[] front, int[] rear) {
		LinkedList<Double> list = new LinkedList<Double>();
		for (int i = 0; i < front.length; i++)
			for (int j = 0; j < rear.length; j++) {
				list.add((double) rear[j] / (double) front[i]);
			}
		Collections.sort(list);
		return list;
	}

	private double getMax(LinkedList<Double> list) {
		double max = 0.0;
		for (int i = 0; i < list.size() - 1; i++) {
			max = Math.max(max, list.get(i + 1) / list.get(i));
		}
		return max;
	}

}

