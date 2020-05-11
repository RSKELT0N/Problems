import java.util.Arrays;
import java.util.Scanner;

public class test {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int size = sc.nextInt();
        int[][] print = new int[size][size];
        boolean flip = true;
        int p = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (print[i][j] == 0) {
                    if (i == 0)
                        print[i][j] = j + 1;

                    if (j == size - 1)
                        flip = !flip;
                    if (flip) {
                        for (int k = 0; k < size; k++)
                            print[k][j] = j + k + 1;
                    } else if (!flip)
                        for (int k = size - 1; k >= 0; k--) {
                            if(k == size-1) {
                                print[j][k] = j + p + size;
                                p++;
                            }
                            print[j-1][k] = j + p + size;
                            p++;
                            print[j-2][k] = j + p + size;
                        }
                }
            }
        }
        for (int k = 0; k < size; k++)
            System.out.println(Arrays.toString(print[k]));
    }
}

