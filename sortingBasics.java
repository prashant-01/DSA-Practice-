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

    public static void insertionSort(int array[]){
        int n=array.length,j;
        for(int i=1;i<n;i++){
            j=i-1;
            int key=array[i];
            while(j>=0 && array[j]>key){
                array[j+1]=array[j];//all elements greater than key , are moved one position ahead 
                j--;
            }
            array[j+1]=key;
        }
        for(int i=0;i<n;i++){
            System.out.print(array[i] + " ");
        }
    }

    public static void countSort(int array[]){
        int n=array.length;
        int  maxV=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            if(array[i]>maxV)maxV=array[i];
        }
        int counts[] = new int[maxV+1];
        int sortedArray[]=new int [n];
        for(int i=0;i<n;i++){
            counts[array[i]]++;
        }
        int k=0;
        for(int i=0;i<counts.length;i++){
            for(int j=0;j<counts[i];j++){
                sortedArray[k]=i;
                k++;
            }
        }
        for(int i=0;i<n;i++){
            System.out.print(sortedArray[i] + " ");
        }
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int array[]=new int[5];
        for(int i=0;i<5;i++){
            array[i]=sc.nextInt();
        }
        //bubbleSort(array);
        //selectionSort(array);
        insertionSort(array);
        //countSort(array);
    }
}
