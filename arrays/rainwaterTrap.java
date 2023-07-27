import java.util.*;
public class rainwaterTrap {
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
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int array[] = new int [6];
        System.out.println("Enter elements");
        for(int i=0;i<6;i++){
            array[i]=sc.nextInt();
        }
        trappingRainwater(array);
    }
}
