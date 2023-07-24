public class transposeMatrix {
    public static void transpose(int matrix[][]){
        int transposedMatrix[][]=new int [matrix[0].length][matrix.length];
        for(int x=0;x<matrix.length;x++){
            for(int y=0;y<matrix[0].length;y++){
                transposedMatrix[y][x]=matrix[x][y];
            }
        }
        for(int x=0;x<matrix[0].length;x++){
            for(int y=0;y<matrix.length;y++){
                System.out.print(transposedMatrix[x][y] + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        int matrix[][]={{5,9,14,15,19},
                        {7,12,15,18,25},
                        {10,18,19,20,27},
                        {13,21,25,27,30}};
        transpose(matrix);
    }
}
