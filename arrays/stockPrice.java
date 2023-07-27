import java.util.Scanner;

public class stockPrice {
    //buy & sell stocks 
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
        buySellStocks(array);
    }
}
