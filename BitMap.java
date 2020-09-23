import java.util.ArrayList;
import java.util.Scanner;

class Position {

    int x;
    int y;

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }
    @Override
    public String toString() {
        return "[" + x + ";" + y + "]";
    }
}

public class BitMap {

    static ArrayList<Position> pos;

    static Integer atoi(String s) {
        return Integer.parseInt(s);
    }

    public static void main(String[] agrs) {
        Scanner sc = new Scanner(System.in);
        int numberOfOperations = atoi(sc.nextLine());

        for (int i = 0; i < numberOfOperations; i++) {
            pos = new ArrayList<>();
            String[] parts = sc.nextLine().split(" ");
            int depth = atoi(parts[0]);
            int length = atoi(parts[1]);

            String[] table = new String[depth];
            for (int j = 0; j < depth; j++)
                table[j] = sc.nextLine();

            //temporary print out as an 2D array
            for (int j = 0; j < depth; j++) {
                for (int k = 0; k < length; k++) {
                    if (table[j].charAt(k) == '1') {
                        pos.add(new Position(k, j));
                    }
                }
                //System.out.print(table[j].charAt(k));
                //System.out.println();
            }
            int[][] graph = new int[pos.size()][pos.size()];

            System.out.println(pos);
        }
    }

}
