import java.util.*;

public class javaPatterns {
    public static void hollowRec(int l , int b){
        for(int i=1;i<=b;i++){
            for(int j=1;j<=l;j++){
                if(i==1 || i==b || j==1 || j==l)System.out.print("*");
                else System.out.print(" ");
            }
            System.out.print("\n");
        }
    }

    public static void halfInvertedPyramid(int r){
        for(int i=1;i<=r;i++){
            for(int j=1;j<=r;j++){
                if(i+j <= r+1){
                    System.out.print("*");
                }else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }

    public static void halfNumberPyramid(int r){
        for(int i=1;i<=r;i++){
            for(int j=1;j<=(r+1-i);j++){
                System.out.print(j);
            }
            System.out.println();
        }
    }

    public static void floydPyramid(int r){
        int i,j,k=1;
        for(i=1;i<=r;i++){
            for(j=1;j<=i;j++){
                System.out.print(k + " ");
                k++;
            }
            System.out.println();
        }
    }
    public static void zeroOneTri(int r){
        for(int i=1;i<=r;i++){
            if(i%2!=0){
                for(int j=1;j<=i;j++){
                    if(j%2!=0)System.out.print("1");
                    else System.out.print("0");
                }
                System.out.println();
            }else{
                for(int j=1;j<=i;j++){
                    if(j%2!=0)System.out.print("0");
                    else System.out.print("1");
                }
                System.out.println();
            }
        }
    }

    public static void solidRhombus(int r){
        for(int i=1;i<=r;i++){
            for(int j=1;j<=r-i+1;j++)System.out.print(" ");
            for(int j=1;j<=r;j++)System.out.print("*");
            System.out.println();
        }
    }

    public static void hollowRhombus(int r){
        for(int i=1;i<=r;i++){
            for(int j=1;j<=r-i+1;j++)System.out.print(" ");
            for(int j=1;j<=r;j++){
                if(i==1 || i==r || j==1 || j==r)System.out.print("*");
                else System.out.print(" ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // int lines = sc.nextInt();
        // int counter = 1;
        // while(counter <=lines){
        //     for(int i=0;i<counter;i++){
        //         System.out.print("*");
        //     }
        //     for(int i=0;i<((lines-counter)*2);i++){
        //         System.out.print(" ");
        //     }
        //     for(int i=0;i<counter;i++){
        //         System.out.print("*");
        //     }
        //     System.out.print("\n");
        //     counter++;
        // }
        // int i;
        // int j=97;
        // while(counter <=lines){
        //     for(i=j;i<j+counter;i++){
        //         char c=(char)i;
        //         System.out.print(c);
        //     }
        //     System.out.print("\n");
        //     j=i;
        //     counter++;
        // }
        // int l=sc.nextInt();
        // int b=sc.nextInt();
        // hollowRec(l, b); 
        int r=sc.nextInt();
        //halfInvertedPyramid(r);   
        //halfNumberPyramid(r);    
        //floydPyramid(r);
        //zeroOneTri(r);
        hollowRhombus(r);
    }

}
