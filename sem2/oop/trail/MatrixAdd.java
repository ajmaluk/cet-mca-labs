import java.util.Scanner;

class MatrixAdd{
    public static void main(String[] args) {
        Scanner s;
        s = new Scanner(System.in);
        int m1,n1,m2,n2;
        System.out.println("Enter the Number of Rows in the first Martix : ");
        m1 = s.nextInt();
        System.out.println("Enter the Number of column in the first Martix : ");
        n1 = s.nextInt();
        System.out.println("Enter the Number of Rows in the Second Martix : ");
        m2 = s.nextInt();
        System.out.println("Enter the Number of Column in the Second Martix : ");
        n2 = s.nextInt();

        if(m1 != m2 && n1 != n2){
            System.out.println("Not possible ! ");
            s.close();
            return;
        }

        int[][] mat1 = new int[m1][n1];
        int[][] mat2 = new int[m1][n1];
        int[][] out = new int[m1][n1];

        System.out.println("Eneter the First Matrix : ");
        for(int i=0;i<m1;i++){
            for(int j=0;j<n1;j++){
                mat1[i][j] = s.nextInt();
            }
        }

        System.out.println("Eneter the Second Matrix : ");
        for(int i=0;i<m1;i++){
            for(int j=0;j<n1;j++){
                mat2[i][j] = s.nextInt();
            }
        }

        for(int i=0;i<m1;i++){
            for(int j=0;j<n1;j++){
                out[i][j] = mat1[i][j] + mat2[i][j];
            }
        }

        System.out.println("\n\nOut put Matrix is  : ");

        for(int i=0;i<m1;i++){
            for(int j=0;j<n1;j++){
                System.out.print(out[i][j] + "\t");
            }
            System.out.println("\n");
        }
        s.close();
    }
}