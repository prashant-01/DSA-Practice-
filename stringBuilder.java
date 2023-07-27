import java.util.*;

public class stringBuilder {
    public static void toupperCase(String str){
        StringBuilder sb=new StringBuilder("");
        char c=Character.toUpperCase(str.charAt(0));
        sb.append(c);
        for(int i=1;i<str.length();i++){
            if(str.charAt(i)== ' ' && i<str.length()-1){
                sb.append(str.charAt(i));
                i++;
                sb.append(Character.toUpperCase(str.charAt(i)));
            }else sb.append(str.charAt(i));
        }
        System.out.println(sb);
    }
    public static void main(String[] args) {
        //Using string ... each time previous string will be copied to new location O(n) & 
        //then a new character will be added to it & this will be repeated n times
        // hence the time complexity will be O(n2)
        String s="";
        for(char ch='a';ch<='z';ch++)s+=ch;
        System.out.println(s);
        System.out.println(s.length());
        
        //Same operation & output using StringBuilder
        //In case of StringBuilder the Time complexity will be O(n) bcoz there will be no 
        //copying of whole string & then adding new character rather the new character 
        //will be appended at the same location
        StringBuilder sb=new StringBuilder("");
        for(char ch='a';ch<='z';ch++)sb.append(ch);
        System.out.println(sb);
        System.out.println(sb.length());
        
        // Integer a = 10;
        // int b =10;
        // String c=a.toString();
        
        // System.out.println(c.charAt(0));
        // this is possible bcoz 'Integer' here is class and 'a' is it's object
        // b.toString();
        // b.charAt(0);
        System.out.println( sb.charAt(1));

        Scanner sc=new Scanner(System.in);
        String str=sc.nextLine();
        toupperCase(str);
        
    }
}
