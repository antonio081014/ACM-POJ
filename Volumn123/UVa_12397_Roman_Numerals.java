/*
 * UVa 12397, Roman Numerals.
 * Solution: 
 * 		Ad-hoc implementation.
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {

    private static int[] nums = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9,
            5, 4, 1          };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strLine;
        while ((strLine = br.readLine()) != null) {
            int N = Integer.parseInt(strLine);
            int count = 0;
            for (int i = 0; i < nums.length; i++) {
                while (N >= nums[i]) {
                    N -= nums[i];
                    count += getMatches(nums[i]);
                }
            }
            System.out.println(count);
        }
    }

	/**
	 * @return the number of corresponding matches required for the number.
	 *
	 * */
    public static int getMatches(int number) {
        switch (number) {
        case 1000:
            return 4;
        case 900:
            return 6;
        case 500:
            return 3;
        case 400:
            return 5;
        case 100:
            return 2;
        case 90:
            return 4;
        case 50:
            return 2;
        case 40:
            return 4;
        case 10:
            return 2;
        case 9:
            return 3;
        case 5:
            return 2;
        case 4:
            return 3;
        case 1:
            return 1;
        default:
            return 1;
        }
    }

}
