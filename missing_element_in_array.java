public class missing_element_in_array {
    static int MissingNumber(int array[], int n) {
        
        int sum = 0;
        for (int i = 0; i <= n; i++){
            sum += i;
        }                               // to sum total numbers we have to iterate

        for (int i = 0; i < n-1; i++){
            sum -= array[i];
        } 
        return sum;     
    }

    public static void main(String[] arr){
        int[] ar = {1,3,4,5};
        int N = ar.length+1;  // coz length is 4 , we need + 1 to find number
        int a = MissingNumber(ar,N);
        System.out.print("Missing number in array is: " + a);
    }
}