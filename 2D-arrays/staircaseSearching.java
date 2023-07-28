public class staircaseSearching {//prerequisite in staircase searching is that matrixc should be  
                                //rows & column wise sorted .
    public static void searchMatrix(int matrix[][], int key){
        int i=0,j=matrix[0].length-1;
        boolean check=false;
        while(i>=0 && j>=0 && i<matrix.length && j<matrix[0].length){
            if(matrix[i][j] == key){
                System.out.println("Key found at position [" + i +","+j+"]");
                check=true;
                return;
            }
            else if(key>matrix[i][j])i++;
            else j--;
        }
        if(check==false)System.out.print("Key not found");
    }
    public static void main(String[] args) {
        int matrix[][]={{5,9,14,15,19},
                        {7,12,15,18,25},
                        {10,18,19,20,27},
                        {13,21,25,27,30}};
        int key=30;
        searchMatrix(matrix, key);
    }
}
