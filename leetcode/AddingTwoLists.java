import java.util.*;

public class Main {

    static String num = "";
    static String numHolder = "";
    static StringBuilder build = new StringBuilder();
    int[] num1 = {1,2};
    int[] num2 = {3,4};
    LinkedList<int[]> list = new LinkedList<>();



    public static void print(int numberOne, int numberTwo) {
        String sum = numberOne + numberTwo + "";
        for (int i = sum.length() - 1; i >= 0; i--) {
            System.out.print(sum.charAt(i));
            if (i == 0) {
                continue;
            }
            System.out.print(" -> ");
        }
        build.append("\nExplanation: ");
        build.append(numberTwo + " + ");
        build.append(numberOne + " = " + sum);
        System.out.println(build);
    }

    public static void main(String[] args) {

        int numberOne = 0;
        int numberTwo = 0;

        Scanner sc = new Scanner(System.in);
        String[] line = sc.nextLine().split(" ");
        for (int i = 0; i < line.length; i++) {
            for (int j = 0; j < line[i].length(); j++) {
                if (!Character.isDigit((line[i].charAt(j))))
                    continue;
                else {
                    num += line[i].charAt(j) + "";
                }
            }
        }
        //
        numHolder = num;
        num = "";
        for (int i = numHolder.length() - 1; i >= 0; i--) {
            num += numHolder.charAt(i);
        }
        int mid = num.length() / 2;
        String[] parts = {num.substring(0, mid), num.substring(mid)};
        numberOne = Integer.parseInt(parts[0]);
        numberTwo = Integer.parseInt(parts[1]);

        print(numberOne, numberTwo);
    }

}
