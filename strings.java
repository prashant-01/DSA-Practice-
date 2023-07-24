import java.util.*;

public class strings {
    //Palindrome 
    public static void checkPalindrome(String str){
        int n=str.length();
        boolean check =false;
        for(int i=0;i<n/2;i++){
            if(str.charAt(i) != str.charAt(n-i-1)){
                check=true;
                System.out.println("Not a Palindrome!");
                return;
            }
        }
        if(check==false)System.out.println("Palindrome!");
    }
    //Calc the shortest distance
    public static void shortestDistance(String str){
        int x=0,y=0;
        for(int i=0;i<str.length();i++){
            char c=str.charAt(i);
            switch(c){
                case'N': y++;
                break;
                case'S': y--;
                break;
                case'E': x++;
                break;
                case'W': x--;
                break;
                default:break;
            }
        }
        double minDistance=Math.sqrt(Math.pow(x, 2)+Math.pow(y, 2));
        System.out.println(minDistance);
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        String str=sc.nextLine();
        //checkPalindrome(str);
        shortestDistance(str);
    }
}
