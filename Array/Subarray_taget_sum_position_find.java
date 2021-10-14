public class SubarrayGivenSum {
 
    public static int[] subarraySum(int[] arr, int k) {
 
         //Declare two variable start and end
         int start = 0;
         int end = 1;
 
         //In sum variable, Assign the value present at 0th index
         int sum = arr[0];
         int len = arr.length;
 
          while(end <= len) {
 
              while(sum > k && start < end-1) {
                    sum = sum - arr[start];
                    start++;
               }
 
               if(sum == k) {
                  return new int[] {start, end-1};
                }
 
                if(end < len)
                   sum = sum + arr[end];
 
                 end++;
 
             }
 
         return new int[]{-1};
}
 
  public static void main(String[] args) {
 
 
        int[] arr = { 2,7,11,15 };
        int sum = 9;
 
        int[] result = subarraySum(arr, sum);
 
         for(int val : result) {
              System.out.print(val + " ");
 
         }
    }
}
