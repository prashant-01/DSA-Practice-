import java.util.*;

public class sortingBasics {
    public static void bubbleSort(int array[]){
        int n=array.length;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(array[j]>array[j+1]){
                    int temp=array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;
                }
            }
        }
        for(int i=0;i<n;i++){
            System.out.print(array[i] + " ");
        }
    }

    public static void selectionSort(int array[]){
        int n=array.length;
        for(int i=0;i<n-1;i++){
            int minPos=i;
            for(int j=i;j<n;j++){
                if(array[j] < array[minPos])minPos=j;
            }
            int temp=array[minPos];
            array[minPos]=array[i];
            array[i]=temp;
        }
        for(int i=0;i<n;i++){
            System.out.print(array[i] + " ");
        }
    }

    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int array[]=new int[5];
        for(int i=0;i<5;i++){
            array[i]=sc.nextInt();
        }
        //bubbleSort(array);
        selectionSort(array);
    }
}
