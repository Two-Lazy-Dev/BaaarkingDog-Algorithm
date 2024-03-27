import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] a = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
        String s = br.readLine();
        for (int i = 0; i < a.length; i++) {
            int cnt = 0;
            for (int j = 0; j < s.length(); j++) {
                if((s.charAt(j) + "").equals(a[i])) {
                    cnt++;
                }
            }
            bw.write(cnt + " ");
        }

        bw.close();
        br.close();
    }
}