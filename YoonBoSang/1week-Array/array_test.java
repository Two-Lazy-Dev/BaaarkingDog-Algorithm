public class Main {

    public static void main(String[] args) {
        int[] arr = {1, 52, 48};
        int answer = func2(arr, 3);
    }

    public static int func2(int[] arr, int n) {
        int[] occur = new int[101];
        for(int i = 0; i < n; i++) {
            if(occur[100 - arr[i]] == 1) {
                return 1;
            }
            occur[arr[i]] = 1;
        }
        return 0;
    }
}