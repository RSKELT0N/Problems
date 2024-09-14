import java.util.Scanner;

class Matrix {

    static long MOD = 1000000007;
    long[][] values;

    public Matrix(int m) {
        values = new long[m][m];
    }

    Matrix multiply(Matrix b) {
        Matrix c = new Matrix(values.length);
        for (int i = 0; i < values.length; i++)
            for (int j = 0; j < values.length; j++) {
                c.values[i][j] = 0;
                for (int k = 0; k < values.length; k++) {
                    c.values[i][j] += values[i][k] * b.values[k][j];
                    c.values[i][j] %= MOD;
                }
            }
        return c;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < values.length; i++) {
            for (int j = 0; j < values.length; j++) {
                sb.append(values[i][j]);
                if (j != values.length - 1)
                    sb.append(" ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }
}

public class Main {

    static Matrix power(Matrix a, int n) {
        if (n == 1)
            return a;
        Matrix b = power(a, n / 2);
        b = b.multiply(b);
        if (n % 2 != 0)
            b = b.multiply(a);
        return b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int m = sc.nextInt();
            int n = sc.nextInt();

            Matrix a = new Matrix(m);
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    a.values[i][j] = sc.nextInt();

            System.out.print(power(a, n));
        }
    }
}
