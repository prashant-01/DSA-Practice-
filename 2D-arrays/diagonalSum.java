public class diagonalSum {
    public static void sumD(int matrix[][]){
        int i=0,j=0,sumPrimary=0,sumSecondary=0,n=matrix.length;
        while(i<=n-1 && j<=n-1){
            sumPrimary+=matrix[i][j];
            i++;
            j++;
        }
        int x=0 , y=n-1;
        while(x<=n-1 && y>=0){
            sumSecondary+=matrix[x][y];
            x++;
            y--;
        }
        if(n%2!=0)sumSecondary-=matrix[n/2][n/2];
        int sum=sumPrimary+sumSecondary;
        System.out.println("Total sum = " + sum);
        System.out.println("Primary diagonal sum - " + sumPrimary);
        System.out.print("Secondary diagonal sum - " + sumSecondary);
    }
    public static void main(String[] args) {
        // int matrix[][]={{1,2,3,4,5},
        //                 {6,7,8,9,10},
        //                 {11,12,13,14,15},
        //                 {16,17,18,19,20},
        //                 {21,22,23,24,25}};
        int matrix[][]={{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};
        sumD(matrix);
    }
}
