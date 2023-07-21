/**
 * javaBasics
 */
import java.util.*;

public class javaBasics {

    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
    //    Largest of the 3.
    //    int a = sc.nextInt();
    //    int b = sc.nextInt();
    //    int c = sc.nextInt();
    //    if((a >= b) && (a >= c)){
    //     System.out.println("Largest of the 3 is " + a);
    //    } else if(b>=c){
    //     System.out.println("Largest of the 3 is " + b);
    //    } else{
    //     System.out.println("Largest of the 3 is " + c);
    //    }

    // Calculator
    //     int a = sc.nextInt();
    //     int b = sc.nextInt();
    //     char operator = sc.next().charAt(0);
    //     switch(operator){
    //         case '+' : System.out.println(a+b);break;
    //         case '-' : System.out.println(a-b);break;
    //         case '*' : System.out.println(a*b);break;
    //         case '/' : System.out.println(a/b);break;
    //         default : System.out.println("Invalid Operator");
    //     }
    // Reverse of a number
        // int number = sc.nextInt();
        // int unitDigit , rev = 0;
        // while(number > 0){
        //     unitDigit = (number%10);
        //     rev = (rev * 10) + unitDigit;
        //     System.out.println(unitDigit);
        //     number /= 10;
        // }
        // System.out.println("Reverse " + rev);
    // Check Prime number 
        int number = sc.nextInt();
        boolean isPrime = true;
        if(number == 2)System.out.println(number + " is a Prime Number");
        else{
            for(int i = 2 ; i < Math.sqrt(number) ; i++){
                        if(number%i == 0){
                        isPrime = false; 
                        System.out.println(number + " is not a Prime Number");
                        break;
                    }
                }
            if(isPrime){
                System.out.println(number + " is a Prime Number");
            }
        }
        
    }
}