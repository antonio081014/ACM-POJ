import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Ad-hoc.
 */

/**
 * @author antonio081014
 * @since Feb 28, 2012, 3:36:29 PM
 */
class Main {

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.run();
    }

    public void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strLine;
        while ((strLine = br.readLine()) != null) {
            String[] str = strLine.split("\\s");
            int H = Integer.parseInt(str[0]);
            int U = Integer.parseInt(str[1]);
            int D = Integer.parseInt(str[2]);
            int F = Integer.parseInt(str[3]);
            if (H + U + D + F == 0)
                return;
            solve(H, U, D, F);
        }
    }

    public void solve(int h, int u, int d, int f) {
        h *= 100;
        f *= u;
        u *= 100;
        d *= 100;
        int done = 0;
        int day = 0;
        while (done >= 0 && done <= h) {
            done += u;
            u -= f;
            if (u < 0)
                u = 0;
            if (done <= h)
                done -= d;
            day++;
        }
        if (done > h)
            System.out.print("success on day ");
        else
            System.out.print("failure on day ");
        System.out.println(day);
    }
}

