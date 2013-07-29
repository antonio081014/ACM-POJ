mport java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * http://poj.org/problem?id=1513
 * 
 */

/**
 * @author antonio081014
 * @time: Apr 2, 2012, 10:38:41 AM
 */
class Main {

    private int N;
    private int C;
    private int L;
    // The number of lecture needed for the first i topics.
    private int[] leccost;
    // The minimum dissatisfication for the first i topics with corresponding number of lecture above.
    private int[] dicost;
    // The time consumed for the first i topics in total.
    private int[] timecost;

    public static void main(String[] args) throws Exception {
	Main main = new Main();
	main.run();
	System.exit(0);
    }

    public void run() throws Exception {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	leccost = new int[1000 + 10];
	dicost = new int[1000 + 10];
	timecost = new int[1000 + 10];
	for (int t = 1;; t++) {
	    N = Integer.parseInt(br.readLine());
	    if (N == 0)
		break;
	    String[] str = br.readLine().split("\\s");
	    L = Integer.parseInt(str[0]);
	    C = Integer.parseInt(str[1]);
	    timecost[0] = 0;
	    for (int i = 1; i <= N; i++) {
		timecost[i] = timecost[i - 1] + Integer.parseInt(br.readLine());
	    }

	    init();

	    for (int i = 1; i <= N; i++) {
		for (int j = i - 1; j >= 0 && timecost[i] - timecost[j] <= L; j--) {
		    int dis = DI(L - timecost[i] + timecost[j]);
		    if (leccost[i] == -1 || leccost[i] > leccost[j] + 1) {
			leccost[i] = leccost[j] + 1;
			dicost[i] = dis + dicost[j];
		    }

		    if ((leccost[i] == leccost[j] + 1)
			    && (dicost[i] == -1 || dicost[i] > dis + dicost[j])) {
			dicost[i] = dis + dicost[j];
		    }
		}
	    }
	    print(t);
	}
    }

    private void init() {
	for (int i = 0; i <= N; i++) {
	    leccost[i] = -1;
	    dicost[i] = -1;
	}
	leccost[0] = 0;
	dicost[0] = 0;
    }

    private void print(int t) {
	if (t != 1)
	    System.out.println();
	System.out.println("Case " + t + ":");
	// System.out.println();
	System.out.println("Minimum number of lectures: " + leccost[N]);
	System.out.println("Total dissatisfaction index: " + dicost[N]);
    }

    public int DI(int t) {
	if (t == 0)
	    return 0;
	else if (t <= 10 && t > 0)
	    return -C;
	else
	    return (t - 10) * (t - 10);
    }
}
