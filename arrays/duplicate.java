import java.util.*;
import java.lang.Math;
    //visited index
public class duplicate {
    public static int searchDuplicate(int nums[]){
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(nums[Math.abs(nums[i])]<0)return Math.abs(nums[i]);
            else{
                nums[Math.abs(nums[i])]*=-1;
            }
        }
        return-1;
    }

    //Positioning index
    public static int searchDuplicate1(int nums[]){
        while(nums[nums[0]] != nums[0]){
            int temp=nums[nums[0]];
            nums[nums[0]]=nums[0];
            nums[0]=temp;
        }
        return nums[0];
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int array[] = new int [6];
        System.out.println("Enter elements");
        for(int i=0;i<6;i++){
            array[i]=sc.nextInt();
        }
        System.out.println("Visiting Index Method " + searchDuplicate(array));
        //System.out.println("Positioning Index Method " + searchDuplicate1(array));
    }
}
