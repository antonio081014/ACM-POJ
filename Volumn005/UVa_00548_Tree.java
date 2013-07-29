import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Building the tree based on the inorder and postorder traverse.
 * Classic and easy;
 */

/**
 * @author antonio081014
 * @since Feb 26, 2012, 8:58:12 PM
 */
class Main {

    public int min;
    public int sum;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.solve();
        // System.exit(0);
    }

    public void solve() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String inOrder;
        String postOrder;
        while ((inOrder = br.readLine()) != null
                && (postOrder = br.readLine()) != null) {
            // Node node = buildTree(inOrder, postOrder);
            Node node = build(inOrder.split("\\s"), postOrder.split("\\s"));
            min = Integer.MAX_VALUE;
            sum = Integer.MAX_VALUE;
            // printByLevel(node);
            // printByIn(node);
            // System.out.println();
            // printByPost(node);
            // System.out.println();
            calculate(node, 0);
            System.out.println(min);
        }
    }

    public void calculate(Node root, int s) {
        if (root.left == null && root.right == null) {
            if (s + root.data < sum) {
                sum = s + root.data;
                min = root.data;
            }
            else if (s + root.data == sum) {
                min = Math.min(min, root.data);
            }
            return;
        }
        if (root.left != null) {
            calculate(root.left, s + root.data);
        }
        if (root.right != null) {
            calculate(root.right, s + root.data);
        }
    }

    public void printByIn(Node root) {
        if (root == null)
            return;
        printByIn(root.left);
        System.out.print(" " + root.data);
        printByIn(root.right);
    }

    public void printByPost(Node root) {
        if (root == null)
            return;
        printByPost(root.left);
        printByPost(root.right);
        System.out.print(" " + root.data);
    }

    public void printByLevel(Node root) {
        List<Node> q = new ArrayList<Node>();
        q.add(root);
        for (int i = 0; i < q.size(); i++) {
            Node tmp = q.get(i);
            if (tmp.left != null) {
                q.add(tmp.left);
                q.add(tmp.right);
            }
            if (tmp.right != null)
                q.add(tmp.right);
        }
        for (int i = 0; i < q.size(); i++)
            System.out.print(" " + q.get(i).data);
        System.out.println();
    }

    public Node buildTree(String inOrder, String postOrder) {
        int idx = postOrder.lastIndexOf(" ");
        if (idx == -1 && inOrder.length() <= 0)
            return null;
        if (idx == -1 && inOrder.compareTo(postOrder) == 0)
            return new Node(Integer.parseInt(postOrder));
        String s = postOrder.substring(idx + 1);
        Node node = new Node(Integer.parseInt(s));
        String[] strs = inOrder.split(s + "\\W+");
        String inOrder1 = (strs[0].length() == 0 ? " " : strs[0]).trim();
        String inOrder2 = (strs.length == 1 ? " " : strs[1].substring(1))
                .trim();
        String postOrder1 = postOrder.substring(0, inOrder1.length()).trim();
        String postOrder2 = postOrder.substring(
                (inOrder1.length() == 0 ? -1 : inOrder1.length()) + 1,
                postOrder.length() - s.length()).trim();
        // System.out.println(s);
        // System.out.println(inOrder1 + ", " + postOrder1);
        // System.out.println(inOrder2 + ", " + postOrder2);
        node.left = buildTree(inOrder1, postOrder1);
        node.right = buildTree(inOrder2, postOrder2);
        return node;
    }

    public Node build(String[] inOrder, String[] postOrder) {
        if (inOrder == null || inOrder.length == 0)
            return null;
        int N = inOrder.length;
        String s = postOrder[N - 1];
        Node node = new Node(Integer.parseInt(s));
        if (N == 1) {
            return node;
        }
        int idx;
        for (idx = 0; idx < N; idx++) {
            if (inOrder[idx].compareTo(s) == 0) {
                break;
            }
        }

        String[] inorder1 = Arrays.copyOfRange(inOrder, 0, idx);
        String[] inorder2 = Arrays.copyOfRange(inOrder, idx + 1, N);
        String[] postorder1 = Arrays.copyOfRange(postOrder, 0, idx);
        String[] postorder2 = Arrays.copyOfRange(postOrder, idx, N - 1);

        // System.out.println(s);
        // System.out.println("idx: " + idx);
        // System.out.print(inorder1.length);
        // System.out.println(", " + inorder2.length);
        // System.out.print(postorder1.length);
        // System.out.println(", " + postorder2.length);

        node.left = build(inorder1, postorder1);
        node.right = build(inorder2, postorder2);
        return node;
    }
}

class Node {
    public int  data;
    public Node left;
    public Node right;

    public Node(int d) {
        this.data = d;
        this.left = null;
        this.right = null;
    }
}

