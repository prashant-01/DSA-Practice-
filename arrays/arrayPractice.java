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
    }
}
