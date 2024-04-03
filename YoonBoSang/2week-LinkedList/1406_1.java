import java.util.*;
import java.io.*;

public class Main{
    static int unused = 1;
    static final int MX = 1000005;
    static String[] dat = new String[MX];
    static int[] pre = new int[MX];
    static int[] nxt = new int[MX];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Arrays.fill(pre, -1);
        Arrays.fill(nxt, -1);

        String init = br.readLine();
        int cursor = 0;
        for (String c : init.split("")) {
            insert(cursor, c);
            cursor++;
        }

        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            String op = br.readLine();
            if(op.equals("L")) {
                if(pre[cursor] != -1) {
                    cursor = pre[cursor];
                }
            } else if(op.equals("D")) {
                if(nxt[cursor] != -1) {
                    cursor = nxt[cursor];
                }
            } else if(op.equals("B")) {
                if(pre[cursor] != -1) {
                    erase(cursor);
                    cursor = pre[cursor];
                }
            } else {
                String add = op.substring(2,3);
                insert(cursor, add);
                cursor = nxt[cursor];

            }
        }

        traverse();
    }

    static void insert(int addr, String num) {
        dat[unused] = num;
        pre[unused] = addr;
        nxt[unused] = nxt[addr];
        if(nxt[unused] != -1) {
            pre[nxt[unused]] = unused;
        }
        nxt[addr] = unused;
        unused++;
    }

    static void erase(int addr) {
        nxt[pre[addr]] = nxt[addr];
        if(nxt[addr] != -1) {
            pre[nxt[addr]] = pre[addr];
        }
    } 

    static void traverse() throws Exception {
        int cur = nxt[0]; 
        String answer = "";
        while (cur != -1) {
            answer += dat[cur];
            cur = nxt[cur];
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(answer);
    }

    // public static void main(String[] args) throws Exception {
    //     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    //     BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    //     final int MX = 100000;
    //     String[] dat = new String[MX];
    //     int[] nxt = new int[MX];
    //     int[] pre = new int[MX];

    //     Arrays.fill(pre, -1);
    //     Arrays.fill(nxt, -1);

    //     String[] arr = br.readLine().split("");
    //     int len = arr.length;
    //     int cur = len - 1;

    //     for(String s : arr) {
    //         int i = 0;
    //         dat[i] = s;
    //         if(i != 0) {
    //             pre[i] = i - 1;
    //         }
    //         if(i + 1 != len) {
    //             nxt[i] = i + 1;
    //         }
    //         i++;
    //     }
        
    //     int len2 = Integer.parseInt(br.readLine());
    //     int f = 0;
    //     for(int i = 0; i < len2; i++) {
    //         String s = br.readLine();
    //         if(s.equals("L")) {
    //             if(cur != 0) {
    //                 cur--;
    //             }
    //         } else if(s.equals("D")) {
    //             if(cur != len -1) {
    //                 cur++;
    //             }
    //         } else if(s.equals("B")) {
    //             if(cur != 0) {
    //                 nxt[cur-1] = nxt[cur];
    //             }
    //             if(nxt[cur] != -1) {
    //                 pre[cur+1] = pre[cur];
    //             }
    //         } else {
    //             dat[len] = s.substring(2,3);
    //             if(cur != 0) {
    //                 pre[len] = cur;
    //             } else {
    //                 f = len;
    //             }
    //             nxt[len] = nxt[cur];
    //             nxt[cur] = len;
    //             if(nxt[cur] != -1) {
    //                 pre[nxt[cur]] = len;
    //             }
    //             len++;
    //         }
    //     }
    //     String answer = dat[f];
    //     while(f != -1) {
    //         answer += dat[nxt[f]];
    //         f = nxt[f];
    //     }
    //     bw.write(answer);
    // }
}