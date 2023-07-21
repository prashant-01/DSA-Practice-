import java.util.Scanner;

public class arrayPractice {
    //Linear search
    public static void linearSearch(int array[] , int key){
        for(int i =0;i<array.length ;i++){
            if(array[i] == key){
                System.out.println("Index of " + key + " is " + i);
                return;
            }
        }
        return;
    }

    //Largest Element
    public static int largestElement(int array[]){
        int max=array[0] ; //int max=Integer.MIN_VALUE; -infinity
        int j = 0,i;
        for(i =0;i<array.length ;i++){
            if(array[i] > max){
                max=array[i];
                j=i;
            }
        }
        return j;
    }

    //Binary Search
    public static int binarySearch(int array[] , int key){
        int l=0 , r=array.length , mid;
        while(l<=r){
            mid=(l+r)/2;
            if(array[mid] == key)return mid;
            else if(array[mid] > key)r=mid-1;
            else l=mid+1;
        }
        return -1;
    }

    //Reversing an Array with swapping (by swapping technique we optimised space complexity from O(n) to O(1))
    //If we would have done by using another array then the space complexity would be O(n)
    public static void reverseArray(int array[]){
        for(int i=0;i<(array.length)/2;i++){
            array[i]+=array[array.length-1-i];
            array[array.length-1-i]=array[i]-array[array.length-1-i];
            array[i]-=array[array.length-1-i];
        }
    }

    //Print all sub-arrays of an Array
    public static void subArrays(int array[]){
        int n=array.length;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=i;k<=j;k++){
                    System.out.print(array[k] + " ");
                }
                System.out.println();
            }
        }
    }

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
        for(int k=l;k<=r;k++)System.out.print(array[k] + " , ");
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

    //Trapping Rainwater Problem
    public static void trappingRainwater(int height[]){
        int n=height.length , totWater=0;
        int leftmaxHeight[] = new int [n];
        int rightmaxHeight[] = new int [n];
        leftmaxHeight[0]=height[0];
        rightmaxHeight[n-1]=height[n-1];
        for(int i=1;i<n;i++){//Calc max height from left for each building
            if(height[i] > leftmaxHeight[i-1])leftmaxHeight[i]=height[i];
            else leftmaxHeight[i]=leftmaxHeight[i-1];
        }
        for(int i=n-2;i>=0;i--){//Calc max height from right for each building
            if(height[i] > rightmaxHeight[i+1])rightmaxHeight[i]=height[i];
            else rightmaxHeight[i]=rightmaxHeight[i+1];
        }
        for(int i=0;i<n;i++){
           int j=leftmaxHeight[i] <rightmaxHeight[i] ?leftmaxHeight[i]-height[i] : rightmaxHeight[i] - height[i];
           if(j>0)totWater+=j;
        }//taking min of the two max height for each building , subtracting it from building's own height
        System.out.println("Total volume of water " + totWater);
    }
    
    public static void buySellStocks(int price[]){
        int n=price.length ;
        int maxPrice=Integer.MIN_VALUE;
        int maxrightPrice[] = new int [n]; 
        int currPrice=0;
        maxrightPrice[n-1]=price[n-1];
        for(int i=n-2;i>=0;i--){
            if(price[i]>maxrightPrice[i+1])maxrightPrice[i]=price[i];
            else{
                maxrightPrice[i]= maxrightPrice[i+1];
            } 
        }
        for(int i=0;i<n;i++){
            currPrice=maxrightPrice[i]-price[i];
            if(currPrice>maxPrice)maxPrice=currPrice;
        }
        System.out.print("Maximum profit is " + maxPrice);
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int array[] = new int [6];
        System.out.println("Enter elements");
        for(int i=0;i<6;i++){
            array[i]=sc.nextInt();
        }
        // System.out.println("Enter key to search");
        // int key=sc.nextInt();
        // linearSearch(array , key);
        // int pos=largestElement(array);
        // System.out.println("Largest Element is " + array[pos]);
        //System.out.print(array[binarySearch(array, key)]);
        // reverseArray(array);
        // for(int i=0;i<10;i++){
        //     System.out.print(array[i] + " ");
        // }
        //subArrays(array);
        //maxsubArraysSum1(array);
        //maxsubArraysSum2(array);
        //trappingRainwater(array);
        buySellStocks(array);
    }
}
