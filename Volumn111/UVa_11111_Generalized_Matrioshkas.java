import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

/**
 * 算法并不难，是需要用到栈就行了，一个元素记录两个值：自身的大小和剩余的容量。
 * 当遇到一个负数的时候，如果当前栈顶元素可以容纳，直接压入栈中，否则则失败；
 * 当遇到一个正数的时候，和栈顶元素比较，相加为0的话，弹出栈顶元素，同时修改当前栈顶元素的剩余容量，相加不为0，则失败。
 * 注意：最终如果成功的话，栈应该为空。
 */

/**
 * @author antonio081014
 * @since Feb 20, 2012, 11:27:41 PM
 */
class Main {

    public Stack<Matrioshkas> stack;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        main.solve();
        System.exit(0);
    }

    public void solve() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        stack = new Stack<Matrioshkas>();
        String strLine;
        while ((strLine = br.readLine()) != null) {
            stack.clear();
            String[] strs = strLine.split("\\s");
            if (oneCase(stack, strs))
                System.out.println(":-) Matrioshka!");
            else
                System.out.println(":-( Try again.");
        }
    }

    public boolean oneCase(Stack<Matrioshkas> stack, String[] strs) {
        for (int i = 0; i < strs.length; i++) {
            int num = Integer.parseInt(strs[i]);
            if (num < 0) {
                if (stack.empty())
                    stack.push(new Matrioshkas(num, num));
                else {
                    if (((Matrioshkas) stack.peek()).capacity < num) {
                        stack.push(new Matrioshkas(num, num));
                    }
                    else
                        return false;
                }
            }
            else {
                if (stack.empty())
                    return false;
                Matrioshkas m = stack.peek();
                if (num + m.size == 0) {
                    stack.pop();
                    if (stack.empty() == false)
                        stack.peek().capacity += num;
                }
                else
                    return false;
            }
        }
        return stack.empty();
    }
}

class Matrioshkas {
    public int size;
    public int capacity;

    public Matrioshkas(int s, int c) {
        this.size = s;
        this.capacity = c;
    }
}
