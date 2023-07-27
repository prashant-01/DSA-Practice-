import java.util.Scanner;
public class shrinkString {
    public static void stringCompress(String str){
        StringBuilder sb=new StringBuilder("");
        int n=str.length();
        for(int i=0;i<n;i++){
            int count=1;
            while(i<n-1 && str.charAt(i+1)==str.charAt(i)){
                count++;
                i++;
            }
            if(count>1){
                sb.append(str.charAt(i));
                sb.append(count);
            }else if(count==1)sb.append(str.charAt(i));
        }
        System.out.println(sb);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String str=sc.nextLine();
        stringCompress(str);
    }
}
