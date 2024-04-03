// 첫번째 원소의 주소만 알고있기에 k번째 원소를 확인/변경하기 위해 O(k)가 필요함
// 임의의 위치의 전원소의 주소를 알고있다면 임의의 위치에 원소를 추가/제거는 O(1) 모른다면 O(N)
// 원소들이 메모리 상에 연속해있지 않아 Cache hit rate가 낮지만 할당이 다소 쉬움

// 단일 연결  리스트(Singly Linked List)
// 각 원소가 자신의 다음 원소의 주소를 가지고 있는 연결 리스트

// 이중 연결 리스트(Doubly Linked List)
// 각 원소가 이전/다음 원소의 주소를 가지고 있는 연결 리스트

// 원형 연결 리스트(Circular Linked List)
// 원소의 끝이 처음의 주소를 가지고 있는 연결 리스트(단일,이중 둘다 가능)

// 첫번째 원소의 주소만 알고있기에

import java.util.*;

public class LinkedList {
    private int unused = 1;

    public static void main(String[] args) {
        final int MX = 1000005;
        int[] dat = new int[MX];
        int[] pre = new int[MX];
        int[] nxt = new int[MX];

        Arrays.fill(pre, -1);
        Arrays.fill(nxt, -1);

    }

    void insert(int addr, int num) {
        dat[unused] = num;
        pre[unused] = addr;
        nxt[unused] = nxt[addr];
        nxt[addr] = unused;
        if(nxt[unused] != -1) {
            pre[nxt[unused]] = unused;
        }
        unused++;
    }

    void erase(int addr) {
        nxt[pre[addr]] = nxt[addr];
        if(nxt[addr] != -1) {
            pre[nxt[addr]] = pre[addr];
        }
    } 

    void traverse() {
        int cur = nxt[0];
        while (cur != -1) {
            System.out.println(dat[cur] + " ");
            cur = nxt[cur];
        }
        System.out.printf("\n\n");
    }

    void insert_test() {
        System.out.println("****** insert_test *****");
        insert(0, 10); // 10(address=1)
        traverse();
        insert(0, 30); // 30(address=2) 10
        traverse();
        insert(2, 40); // 30 40(address=3) 10
        traverse();
        insert(1, 20); // 30 40 10 20(address=4)
        traverse();
        insert(4, 70); // 30 40 10 20 70(address=5)
        traverse();
    }

    void erase_test() {
        System.out.println("****** erase_test *****");
        erase(1); // 30 40 20 70
        traverse();
        erase(2); // 40 20 70
        traverse();
        erase(4); // 40 70
        traverse();
        erase(5); // 40
        traverse();
    }
}