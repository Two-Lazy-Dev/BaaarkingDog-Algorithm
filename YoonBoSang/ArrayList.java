import java.util.*;

public class ArrayList {
    
    public static void main(String[] args) {
        ArrayList<Integer> a1 = new ArrayList<>(5, 5, 5);
        System.out.printf("%d\n", a1.size()); // 3
        a1.add(7); // {5, 5, 5, 7}

        ArrayList<Integer> a2 = new ArrayList<>(0, 0);
        a2.add(1, 3); // {0, 3, 0}

        ArrayList<Integer> a3 = new ArrayList<>(1, 2, 3, 4);
        a3.remove(2); // {1, 2, 4}

        ArrayList<Integer> a4 = a3; // {1, 2, 4}
        System.out.printf("" + a4[0] + a4[1] + a4[2] + "\n"); // 124
        a4.remove(a4.size() - 1); // {1, 2}
        a4.clear(); // {}

        // 1. range-based for loop
        for(int e : a1) {
            System.out.printf(e + " ");
        }

        // 2. not bad
        for (imt i = 0; i < a1.size(); i++) {
            System.out.printf(a1[i] + " ");
        }

        // 3. ***WRONG***
        for(int i = 0; i <= a1.size() - 1; i++) {
            System.out.printf(a1[i] + " ");
        }
    }


}
