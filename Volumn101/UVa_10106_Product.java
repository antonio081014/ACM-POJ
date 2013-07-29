import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 * 
 */

/**
 * @author antonio081014
 * @since Feb 13, 2012, 12:48:05 AM
 */
class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strLine;
        while ((strLine = br.readLine()) != null) {
            BigInteger number = new BigInteger(strLine);
            System.out.println(number.multiply(new BigInteger(br.readLine())));
        }
    }
}
