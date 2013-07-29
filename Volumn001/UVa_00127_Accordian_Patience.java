import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 * 
 */

/**
 * @author antonio081014
 * @since Feb 25, 2012, 4:08:20 PM
 */
class Main {

    public List<List<String>> cards;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.solve();
        System.exit(0);
    }

    public void solve() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strLine = br.readLine();
        while (strLine.compareTo("#") != 0) {
            cards = new ArrayList<List<String>>();
            solveLine(strLine.split("\\s"));
            strLine = br.readLine();
            solveLine(strLine.split("\\s"));
            print();
            strLine = br.readLine();
        }
    }

    public void print() {
        if (cards.size() > 1) {
            System.out.print("" + cards.size() + " piles remaining:");
        }
        else {
            System.out.print("" + cards.size() + " pile remaining:");
        }
        for (int i = 0; i < cards.size(); i++) {
            System.out.print(" " + cards.get(i).size());
        }
        System.out.println();
    }

    public void solveLine(String[] strs) {
        for (int i = 0; i < strs.length; i++) {
            List<String> tmp = new ArrayList<String>();
            tmp.add(strs[i]);
            cards.add(tmp);
            for (int j = cards.size() - 1; j < cards.size();) {
                String s = cards.get(j).get(0);
                if (j >= 3 && match(s, cards.get(j - 3).get(0))) {
                    cards.get(j - 3).add(0, s);
                    if (cards.get(j).size() == 1)
                        cards.remove(j);
                    else
                        cards.get(j).remove(0);
                    j -= 3;
                }
                else if (j >= 1 && match(s, cards.get(j - 1).get(0))) {
                    cards.get(j - 1).add(0, s);
                    if (cards.get(j).size() == 1)
                        cards.remove(j);
                    else
                        cards.get(j).remove(0);
                    j--;
                }
                else
                    j++;
            }
        }
    }

    public boolean match(String a, String b) {
        if (a.charAt(0) == b.charAt(0) || a.charAt(1) == b.charAt(1))
            return true;
        return false;
    }
}
