import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Essentially, it's a Longest-Increasing-Subsequence problem, so we could solve
 * it with Dynamic Programming.
 * 
 * 1st, sort the dimensions for each box;(This permutation could be compared
 * more easily, since any permutation is essentially the same.)
 * 2nd, sort the boxes, any two boxes could be compared dim by dim,
 * 3rd, use dynamic programming to solve the problem, list[i].best is the
 * maximum number, while use parent to keep the track.
 * 4th, use the track to backtrack the list of boxes's id;
 * 
 */

/**
 * @author antonio081014
 * @since Jan 24, 2012, 5:29:40 PM
 */
class Main {

    public static List<Box> list;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String strLine;
        while ((strLine = br.readLine()) != null) {
            String[] strs = strLine.split(" ");
            int k = Integer.parseInt(strs[0]);
            int n = Integer.parseInt(strs[1]);
            list = new ArrayList<Box>();
            for (int i = 0; i < k; i++) {
                strs = br.readLine().split(" ");
                list.add(new Box(i, n, strs));
            }
            Collections.sort(list);

            int[] parent = new int[k];
            for (int i = 0; i < k; i++)
                parent[i] = i;
            int best = -1;
            int index = -1;
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < i; j++) {
                    if (list.get(i).compare(list.get(j))
                            && list.get(i).best < list.get(j).best + 1) {
                        list.get(i).best = list.get(j).best + 1;
                        parent[i] = j;
                    }
                }
                if (list.get(i).best > best) {
                    best = list.get(i).best;
                    index = i;
                }
            }
            // for (int i = 0; i < k; i++) {
            // System.out.println(list.get(i).id + " " + parent[i] + " "
            // + list.get(i).best);
            // }

            System.out.println(best);
            List<Integer> nums = new ArrayList<Integer>();

            while (index != parent[index]) {
                nums.add(list.get(index).id + 1);
                index = parent[index];
            }
            nums.add(list.get(index).id + 1);
            String output = "";
            for (int i = nums.size() - 1; i >= 0; i--) {
                output += Integer.toString(nums.get(i)) + " ";
            }
            System.out.println(output.substring(0, output.length() - 1));
        }
    }
}

class Box implements Comparable<Box> {
    public int[] dims;
    public int   id;
    public int   best;

    public Box(int id, int n, String[] strs) {
        this.best = 1;
        this.id = id;

        dims = new int[n];
        for (int i = 0; i < n; i++)
            dims[i] = Integer.parseInt(strs[i]);
        Arrays.sort(dims);
    }

    public boolean compare(Box a) {
        for (int i = 0; i < this.dims.length; i++) {
            if (this.dims[i] <= a.dims[i])
                return false;
        }
        return true;
    }

    @Override
    public int compareTo(Box arg0) {
        for (int i = 0; i < dims.length; i++) {
            if (this.dims[i] < arg0.dims[i])
                return -1;
            else if (this.dims[i] > arg0.dims[i])
                return 1;
        }
        return 0;
    }

    @Override
    public String toString() {
        String ret = "";
        for (int i = 0; i < dims.length; i++)
            ret += dims[i] + " ";
        return ret;
    }
}

