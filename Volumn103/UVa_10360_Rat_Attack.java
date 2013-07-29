import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * hint: focus on the rat.
 */

/**
 * @author antonio081014
 * @since Mar 3, 2012, 10:33:41 PM
 */
class Main {

    public int[][]          ratsPopulation;
    public static final int SIZE = 1025;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.run();
        System.exit(0);
    }

    public void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int d = Integer.parseInt(br.readLine());
            int N = Integer.parseInt(br.readLine());
            ratsPopulation = new int[SIZE][SIZE];
            for (int i = 0; i < N; i++) {
                String[] str = br.readLine().split("\\s");
                int a = Integer.parseInt(str[0]);
                int b = Integer.parseInt(str[1]);
                int c = Integer.parseInt(str[2]);
                // For each reachable point, increase the Population the bomb at
                // that point could kill.
                for (int x = Math.max(0, a - d); x <= Math.min(SIZE - 1, a + d); x++) {
                    for (int y = Math.max(0, b - d); y <= Math.min(SIZE - 1, b
                            + d); y++) {
                        ratsPopulation[x][y] += c;
                    }
                }
            }
            int x = -1;
            int y = -1;
            int max = -1;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (ratsPopulation[i][j] > max) {
                        max = ratsPopulation[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
            System.out.println("" + x + " " + y + " " + max);
        }
    }
}

