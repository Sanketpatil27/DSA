public class Insertion_in_array_ps {

    static void indInsertion(int arr[], int capacity, int size, int  elem, int ind) {
        if (ind > capacity) {
            System.out.print("Insertion Failed!");
        }
        else {
            for (int i = size; i >= ind; i--) {
                arr[i+1] = arr[i];
            }
            arr[ind] = elem;
        }
    }

    
    static void showArr(int arr[], int size) {
        for (int i = 0; i < size; i++){
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {

        int[] arr = new int[10];
        arr[0] = 2;
        arr[1] = 55;
        arr[2] = 46;
        arr[3] = 67;
        arr[4] = 456;


        int size = 5;
        int elem = 90;
        int ind = 4;
        int capacity = 10;      // array capacity
        
        
        System.out.print("Before Insertion: ");
        showArr(arr, size);
        
        indInsertion(arr, capacity, size, elem, ind);   
        
        System.out.print("\nAfter Insertion:  ");
        showArr(arr, size+1);       // +1 coz we inserted an extra element
    }
}