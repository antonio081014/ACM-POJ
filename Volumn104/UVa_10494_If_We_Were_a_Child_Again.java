import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 * PS:
 * 1st, remove the extra spaces.
 * 2nd, the first integer is pretty large.
 * 
 */

/**
 * @author antonio081014
 * @since Feb 13, 2012, 9:23:44 PM
 */
class Main {

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.start();
    }

    public void start() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strLine;
        while ((strLine = br.readLine()) != null) {
            strLine = removeSpace(strLine);
            String[] strs = strLine.split(" ");
            BigInteger a = new BigInteger(strs[0]);
            BigInteger b = new BigInteger(strs[2]);
            if (strs[1].compareTo("/") == 0) {
                System.out.println(a.divide(b));
            }
            else
                System.out.println(a.mod(b));
        }
    }

    public String removeSpace(String a) {
        String b = "";
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != ' ') {
                b += a.charAt(i);
                count = 0;
            }
            else {
                count++;
                if (count == 1)
                    b += " ";
            }
        }
        return b.trim();
    }
}
