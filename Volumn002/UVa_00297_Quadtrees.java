import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;

/**
 * Building two 5-level full quadtrees based on the two given strings.
 * Then, compare each leaf node pair of two trees.
 */

/**
 * @author antonio081014
 * @since Feb 27, 2012, 2:00:50 PM
 */
class Main {

    public static int Levels = 5;

    public String     str;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.solve();
    }

    public void solve() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            str = br.readLine();
            Node one = build(0);
            str = br.readLine();
            Node two = build(0);
            // printByPost(one);
            blacks(one, two);
        }
    }

    public void blacks(Node a, Node b) {
        int sum = 0;
        LinkedList<Node> q = new LinkedList<Node>();
        q.add(a);
        q.add(b);
        while (q.size() > 0) {
            a = q.poll();
            b = q.poll();
            if (a.level >= Levels)
                sum += a.color || b.color ? 1 : 0;
            else {
                q.add(a.child1);
                q.add(b.child1);
                q.add(a.child2);
                q.add(b.child2);
                q.add(a.child3);
                q.add(b.child3);
                q.add(a.child4);
                q.add(b.child4);
            }
        }
        System.out.println("There are " + sum + " black pixels.");
    }

    public void printByPost(Node root) {
        if (root == null)
            return;
        printByPost(root.child1);
        printByPost(root.child2);
        printByPost(root.child3);
        printByPost(root.child4);
        System.out.println("Level" + root.level + ": " + root.color);
    }

    /**
     * Build a Level-level full quadtree based on the given string.
     * 
     * @return Node;
     * */
    public Node build(int level) {
        Node node;
        if (level == Levels) {
            node = new Node(level, str.charAt(0) == 'f' ? true : false);
            // This is where I made two WAs before I added this string update
            // statement.
            if (str.length() > 1)
                str = str.substring(1);
            return node;
        }
        if (str.charAt(0) == 'p') {
            node = new Node(level, false);
            str = str.substring(1);
            node.child1 = build(level + 1);
            node.child2 = build(level + 1);
            node.child3 = build(level + 1);
            node.child4 = build(level + 1);
        }
        else {
            node = new Node(level, str.charAt(0) == 'f');
            node.child1 = build(level + 1, str.charAt(0) == 'f');
            node.child2 = build(level + 1, str.charAt(0) == 'f');
            node.child3 = build(level + 1, str.charAt(0) == 'f');
            node.child4 = build(level + 1, str.charAt(0) == 'f');
            str = str.substring(1);
        }
        return node;
    }

    /**
     * This function is called when all of the sub-leaf nodes are in the same
     * color.
     * This simply generate all the subtrees with the same color.
     * */
    public Node build(int level, boolean color) {
        Node node = new Node(level, color);
        if (level >= Levels)
            return node;
        node.child1 = build(level + 1, color);
        node.child2 = build(level + 1, color);
        node.child3 = build(level + 1, color);
        node.child4 = build(level + 1, color);
        return node;
    }

    public boolean isLeaf(Node root) {
        if (root.child1 == null && root.child2 == null && root.child3 == null
                && root.child4 == null)
            return true;
        return false;
    }
}

class Node {
    public int     level;
    public boolean color;
    public Node    child1;
    public Node    child2;
    public Node    child3;
    public Node    child4;

    public Node(int l, boolean c) {
        this.level = l;
        this.color = c;
        this.child1 = null;
        this.child2 = null;
        this.child3 = null;
        this.child4 = null;
    }
}

