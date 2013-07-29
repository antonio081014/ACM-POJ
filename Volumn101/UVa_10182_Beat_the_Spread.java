import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * 
 */

/**
 * @author antonio081014
 * @since Feb 28, 2012, 5:33:42 PM
 */
class Main {

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.run();
    }

    public void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            String[] str = br.readLine().split("\\s");
            int a = Integer.parseInt(str[0]);
            int b = Integer.parseInt(str[1]);
            if ((a + b) % 2 == 0 && (a - b) % 2 == 0 && a >= b) {
                System.out.println("" + ((a + b) / 2) + " " + ((a - b) / 2));
            }
            else
                System.out.println("impossible");
        }
    }
}
