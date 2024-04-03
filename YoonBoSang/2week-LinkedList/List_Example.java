import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> L = new LinkedList<>();
        L.addLast(1);
        L.addLast(2);
        ListIterator<Integer> t = L.listIterator(); // t는 1의 앞에서 커서로 가르키는중
        L.addFirst(10); // 10 1 2
        L.addLast(5); // 10 1 2 5
        L.add(t.next(), 6); // t가 가르키는 곳 앞에 6을 샆입, 10 6 1 2 5
        // t.next()로인해 t가 한칸 전진, 현재 t가 가르키는 값은 2
        L.remove(t.next()); // t의 커서 뒤의 값을 제거
                    // 10 6 1 5, t의 커서 위치는 5의 앞
        for (int i : L) {
            System.out.println(i + " ");
        }
        System.out.println();
    }
}