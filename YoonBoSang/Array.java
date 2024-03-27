// 배열의 성질
// 1. O(1)에 K번째 원소를 확인/변경 가능
// 2. 추가적으로 소모되는 메모리의 양(=OVERHEAD)가 거의 없음
// 3. Cache hit rate가 높음
// 4. 메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸림

public class Array {

  static int[] arr = { 10, 50, 40, 30, 70, 20, 0, 0, 0, 0 };

  public static main(String[] args) {
    int len = 6;
    len = insert(3, 60, arr, len); // 10 50 40 60 30 70 20
    len = erase(4, arr, len); // 10 50 40 60 70 20
  }

  public static int insert(int idx, int num, int[] arr, int len){
    for (int i = len; i > idx; i--) {
            arr[i] = arr[i - 1];
    }
    arr[idx] = num;
    len++;
    return len;
  }

  public static int erase(int idx, int[] arr, int len) {
    for (int i = idx; i < len; i--) {
      arr[i] = arr[i + 1];
    }
    arr[len] = 0;
    len--;
    return len;
  }

  void printArr(int[] arr, int len) {
    for (int i = 0; i < len; i++) {
      System.out.printf(arr[i] + " ");
    }
    System.out.printf("\n");
  }

  void insert_test() {
    int[] arr = { 10, 20, 30, 0, 0, 0, 0, 0, 0, 0 };
    int len = 3;
    len = insert(3, 40, arr, len); // 10 20 30 40
    printArr(arr, len);
    len = insert(1, 50, arr, len); // 10 50 20 30 40
    printArr(arr, len);
    len = insert(0, 15, arr, len); // 15 10 50 20 30 40
    printArr(arr, len);
  }

  void erase_test() {
    int[] arr = { 10, 50, 40, 30, 70, 20, 0, 0, 0, 0 };
    int len = 6;
    len = erase(4, arr, len); // 10 50 40 30 20
    printArr(arr, len);
    len = erase(1, arr, len); // 10 40 30 20
    printArr(arr, len);
    len = erase(3, arr, len); // 10 40 30
    printArr(arr, len);
  }

  void main() {
    insert_test();
    erase_test();
  }
}