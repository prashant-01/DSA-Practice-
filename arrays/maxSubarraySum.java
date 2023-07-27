import java.util.*;
public class maxSubarraySum {
    //Maximum Sub-array sum - Brute Force 
    public static void maxsubArraysSum(int array[]){
        int maxSum=Integer.MIN_VALUE , currSum;
        int n=array.length;
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                currSum=0;
                for(int k=i;k<=j;k++){
                    currSum+=array[k];
                }
                if(currSum>maxSum){
                    maxSum=currSum;
                    l=i;
                    r=j;
                }
            }
        }
        System.out.println("Maximum sum is " + maxSum);
        //for(int k=l;k<=r;k++)System.out.print(array[k] + " , ");
    }

    //Maximum Subarray Sum - Optimised Approach - Prefix sum array
    public static void maxsubArraysSum1(int array[]){
        int n=array.length;
        int prefixSum[] =new int [n];
        prefixSum[0]=array[0];
        int maxSum=Integer.MIN_VALUE, currSum;
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+array[i];
        }
        for(int i=0;i<n;i++){
            int start = i;
            for(int j=i;j<n;j++){
                int end=j;
                currSum= start==0?prefixSum[end]:prefixSum[end]-prefixSum[start-1];
                if(currSum > maxSum)maxSum=currSum;
            }
        }
        System.out.println("Maximum Subarray Sum " + maxSum);
    }

    //Maximum Subarray sum - Best approach Kadane's Algorithm
    public static void maxsubArraysSum2(int array[]){
        boolean checkNonZero=false;
        for(int i=0;i<array.length;i++){
            if(array[i] >= 0){
                checkNonZero=true;
                break;
            }
        }
        if(!checkNonZero){
            int maxNum=Integer.MIN_VALUE;
            for(int i=0;i<array.length;i++){
                if(array[i] > maxNum)maxNum=array[i];
            }
            System.out.println("Maximum sub-array sum " + maxNum);
            return;
        }else{
            int maxSum=array[0] , n=array.length , currSum=0;
            int prefixSumArray[]= new int [n];
            if(array[0] >= 0)prefixSumArray[0]=array[0];
            else prefixSumArray[0]=0;
            for(int i=1;i<n;i++){
                currSum=prefixSumArray[i-1]+array[i];
                if(currSum>=0){
                    prefixSumArray[i]=currSum;
                    if(prefixSumArray[i] > maxSum)maxSum=prefixSumArray[i];
                }else prefixSumArray[i]=0;
        }
            System.out.print("Maximum sub-array sum " + maxSum);
        }
    }
    public static void main(String[] args) {
        int array[]={3,8,-2,-4,4,1,4,2,-1,-6};
        maxsubArraysSum(array);
        maxsubArraysSum1(array);
        maxsubArraysSum2(array);
    }
}
