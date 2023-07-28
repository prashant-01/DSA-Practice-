public class spiralMatrix {
    public static void printSpiral(int matrix[][]){
        int startRow=0,endRow=matrix.length-1,startCol=0,endCol=matrix[0].length-1;
        while(startRow<=endRow && startCol<=endCol){
            //top
            for(int j=startCol;j<=endCol;j++)System.out.print(matrix[startRow][j] + " ");
            //right
            for(int i=startRow+1;i<=endRow;i++)System.out.print(matrix[i][endCol] +  " ");
            //bottom
            for(int j=endCol-1;j>=startCol;j--){
                if(startRow==endRow)break;
                System.out.print(matrix[endRow][j] + " ");
            }
            //left
            for(int i=endRow-1;i>=startRow+1;i--){
                if(startCol==endCol)break;
                System.out.print(matrix[i][startCol] + " ");
            }
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
    }

    public static void printWave(int matrix[][]){
        int n=matrix.length;
        int m=matrix[0].length;
        for(int j=0;j<m;j++){
            if(j%2==0){
                for(int i=0;i<n;i++)System.out.print(matrix[i][j] + " ");
            }else{
                for(int i=n-1;i>=0;i--)System.out.print(matrix[i][j] + " ");
            }
        }
    }
    public static void main(String[] args) {
        int matrix[][]={{1,2,3,4,5},
                        {6,7,8,9,10},
                        {11,12,13,14,15}};
                        // {16,17,18,19,20},
                        // {21,22,23,24,25}};
        //printSpiral(matrix);
        printWave(matrix);
    }
}
