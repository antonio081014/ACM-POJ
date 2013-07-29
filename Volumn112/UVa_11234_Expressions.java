import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 * No matter how I tried, it still TLE.
 */

/**
 * @author antonio081014
 * @since Feb 14, 2012, 7:53:41 PM
 */
public class Main {

    public List<Node> stack;
    public List<Node> q;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.solve();
        System.exit(0);
    }

    public void solve() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        stack = new ArrayList<Node>();
        q = new ArrayList<Node>();
        int T = Integer.parseInt(br.readLine());
        while ((T--) > 0) {
            String strLine = br.readLine();
            int N = strLine.length();
            // Node root = build(br.readLine(););
            // printByLevel(root);
            // printByLevel(build(br.readLine()));
            printByLevel(buildTree(strLine, N), N);
            // printByPostorder(root);
            // System.out.println();
        }
    }

    public Node build(String s) {
        Node node = new Node(s.charAt(s.length() - 1));

        if (s.length() <= 1) {
            return node;
        }
        if (s.length() == 3) {
            node.left = new Node(s.charAt(0));
            node.right = new Node(s.charAt(1));
            return node;
        }

        int i;
        int count = 2;
        for (i = 2; i < s.length() - 1; i++) {
            if (s.charAt(i) <= 'Z') {
                count -= 2;
                // if left child is a subtree;
                if (count == 0) {
                    // System.out.print(s.substring(0, i + 1) + ", "
                    // + s.substring(i + 1, s.length() - 1));
                    // System.out.println();
                    node.left = build(s.substring(0, i + 1));
                    node.right = build(s.substring(i + 1, s.length() - 1));
                    break;
                }
                count++;
            }
            else
                count++;

        }
        // if the left child is just a number.
        if (count == 2) {
            node.left = build("" + s.charAt(0));
            node.right = build(s.substring(1, s.length() - 1));
        }
        return node;
    }

    public Node buildTree(String s, int N) {
        long start = System.currentTimeMillis();
        stack.clear();
        for (int i = 0; i < N; i++) {
            char c = s.charAt(i);
            Node tmp = new Node(c);
            if (c <= 'Z') {
                tmp.right = stack.remove(0);
                tmp.left = stack.remove(0);
            }
            stack.add(0, tmp);
        }
        long end = System.currentTimeMillis();
        System.out.println(end - start);
        return stack.get(0);
    }

    public void printByPostorder(Node root) {
        if (root == null) {
            return;
        }
        printByPostorder(root.left);
        printByPostorder(root.right);
        System.out.print(root.data);
    }

    public void printByLevel(Node root, int N) {
        // long start = System.currentTimeMillis();
        String strLine = "";
        q.clear();
        q.add(root);
        for (int i = 0; i < N; i++) {
            Node tmp = q.get(i);
            strLine = "" + tmp.data + strLine;
            if (tmp.left != null) {
                q.add(tmp.left);
                q.add(tmp.right);
            }
        }
        System.out.println(strLine);
        // long end = System.currentTimeMillis();
        // System.out.println(end - start);
    }
}

class Node {
    public char data;
    public Node left;
    public Node right;

    public Node(char c) {
        this.data = c;
        this.left = null;
        this.right = null;
    }
}
// aaAaaAAaaAaaAAAaaAaaAAaaAaaAAAAaaAaaAAaaAaaAAAaaAaaAAaaAaaAAAAAaaAaaAAaaAaaAAAaaAaaAAaaAaaAAAAaaAaaAAaaAaaAAAaaAaaAAaaAaaAAAAAA
