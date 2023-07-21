import java.util.*;

public class practiceFunctions {
    //Calculate Fcatorial
    public static int clacFactorial(int num){
        int fac=1;
        int i=1;
        while(i<=num){
            fac*=i;
            i++;
        }
        return fac;
    }
    //Check whether number is prime or not
    public static boolean isPrime(int num){
        int i;
        if(num == 2)return true;
        for(i=2;i<=Math.sqrt(num);i++){
            if(num%i==0)return false;
        }
        return true;
    }

    public static void primeInRange(int l , int r){
        System.out.print("Prime numbers between " + l + "-" + r + " : ");
        boolean check = false;
        for(int i=l;i<=r;i++){
            if(isPrime(i)){
                System.out.print(i + " ");
                check=true;
            }
        }
        if(check==false)System.out.print("No Prime number in this range");
    }
    //Binary to Decimal Conversion
    public static void binToDec(int bin){
        int dec=0 , power=0, lastDigit , b=bin;
        while(bin > 0){
            lastDigit = bin%10;
            dec+=lastDigit*Math.pow(2,power);
            bin/=10;
            power++;
        }
        System.out.println("Decimal of " + b + " is " + dec);
    }
    //Decimal to binary Conversion
    public static void decToBin(int dec){
        int bin=0 , power=0 , d=dec , rem;
        while(dec>0){
            rem=dec%2;
            bin+=rem*Math.pow(10, power);
            dec/=2;
            power++;
        }
        System.out.println("Binary of " + d + " is " + bin);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // int dec = sc.nextInt();
        // int bin = sc.nextInt();
        int l = sc.nextInt();
        int r = sc.nextInt();
        // decToBin(dec);
        // binToDec(bin);
        primeInRange(l, r);
    }
}
