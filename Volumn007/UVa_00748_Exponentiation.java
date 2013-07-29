import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;

/**
 * Using BigDecimal will be very helpful.
 * PS: don't forget to remove the trailing zeros and the leading zeros.
 */

/**
 * @author antonio081014
 * @since Feb 13, 2012, 9:38:58 PM
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
            String[] strs = strLine.split("\\s");
            BigDecimal a = new BigDecimal(strs[0]);
            int b = Integer.parseInt(strs[1]);
            String out = a.pow(b).stripTrailingZeros().toPlainString();
            for (int i = 0; i < out.length(); i++) {
                if (out.charAt(i) != '0') {
                    out = out.substring(i);
                    break;
                }
            }
            System.out.println(out);
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
