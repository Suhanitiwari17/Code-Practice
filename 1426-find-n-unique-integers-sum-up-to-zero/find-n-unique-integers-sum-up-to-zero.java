class Solution {
    public int[] sumZero(int n) {
        int[] arr=new int[n];
        int index=0;
        for(int i=1;i<=n/2;i++){
            arr[index]=i;
            index++;
            arr[index]=-i;
            index++;
        }
         if (n % 2 != 0) {
            arr[index] = 0;
        }

        return arr;
    }
}