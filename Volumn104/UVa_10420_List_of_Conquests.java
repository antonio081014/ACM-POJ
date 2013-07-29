import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.TreeMap;

/**
 * ad-hoc
 */

/**
 * @author antonio081014
 * @since Feb 28, 2012, 5:20:42 PM
 */
class Main {

    public TreeMap<String, Integer> map;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.run();
    }

    public void run() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        map = new TreeMap<String, Integer>();
        for (int i = 0; i < N; i++) {
            String[] str = br.readLine().split("\\s");
            if (map.get(str[0]) == null) {
                map.put(str[0], 1);
            }
            else
                map.put(str[0], map.get(str[0]) + 1);
        }
        Iterator<String> it = map.keySet().iterator();
        while (it.hasNext()) {
            String s = it.next();
            System.out.println(s + " " + map.get(s));
        }
    }
}
