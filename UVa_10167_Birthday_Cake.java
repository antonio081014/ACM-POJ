import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Pretty brute-force.
 * Iterate every possible values of A and B here. 
 */

/**
 * @author antonio081014
 * @time: Apr 3, 2012, 2:08:52 PM
 */
class Main {

    private int N;
    private int[] xx;
    private int[] yy;

    public static void main(String[] args) throws Exception {
	Main main = new Main();
	main.run();
	System.exit(0);
    }

    public void run() throws Exception {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	N = Integer.parseInt(br.readLine());
	xx = new int[100];
	yy = new int[100];
	while (N != 0) {
	    for (int i = 0; i < 2 * N; i++) {
		String[] str = br.readLine().split("\\s");
		xx[i] = Integer.parseInt(str[0]);
		yy[i] = Integer.parseInt(str[1]);
	    }

	    boolean flags = true;
	    for (int A = -500; A <= 500 && flags; A++) {
		for (int B = -500; B <= 500 && flags; B++) {
		    boolean flag = false;
		    int count = 0;
		    for (int i = 0; i < 2 * N; i++) {
			int tmp = A * xx[i] + B * yy[i];
			if (tmp == 0) {
			    flag = true;
			    break;
			} else if (tmp < 0)
			    count++;
		    }
		    if (flag == false && count == N) {
			flags = false;
			System.out.println(A + " " + B);
		    }
		}
	    }
	    N = Integer.parseInt(br.readLine());
	}
    }
}
