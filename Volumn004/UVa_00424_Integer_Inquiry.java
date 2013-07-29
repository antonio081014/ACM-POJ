import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 * It reminds me the first challenge for my road of Accepted.
 */

/**
 * @author antonio081014
 * @since Feb 13, 2012, 12:37:06 AM
 */
class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strLine;
        BigInteger sum = BigInteger.ZERO;
        while ((strLine = br.readLine()) != null) {
            if (strLine.compareTo("0") == 0)
                break;
            sum = sum.add(new BigInteger(strLine));
        }
        System.out.println(sum);
    }
}
