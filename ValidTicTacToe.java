    import java.util.Scanner;

    public class xo {

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int games = Integer.parseInt(sc.nextLine());
            String[] xo = new String[3];
            String line = "";


            for (int k = 0; k < games; k++) {
                int x = 0;
                int o = 0;
                for (int i = 0; i < 3; i++) {
                    xo[i] = sc.nextLine();
                    for (int j = 0; j < xo.length; j++) {
                        if (xo[i].charAt(j) == 'X') {
                            x++;
                        } else if (xo[i].charAt(j) == 'O') {
                            o++;
                        }
                    }
                }
                boolean possible = true;
                if (o > x || x - o > 1) {
                    possible = false;
                }
                else {
                    boolean xwins = checkWinHorizontally(xo, "XXX") || checkWinVertically(xo, "XXX") || checkWinDiagonally(xo, "XXX");
                    if (xwins && (x-o) != 1)
                        possible = false;

                    boolean owins = checkWinHorizontally(xo, "OOO") || checkWinVertically(xo, "OOO") || checkWinDiagonally(xo, "OOO");
                    if (owins && (x-o) != 0)
                        possible = false;

                    if (xwins && owins)
                        possible = false;
                }

                if (possible)
                    System.out.println("yes");
                else System.out.println("no");
                if (k == games) {
                    System.out.println();
                }
            }
        }

        public static boolean checkWinHorizontally(String[] xo, String p) {
            for (int i = 0; i < xo.length; i++) {
                String test = "";
                for (int j = 0; j < xo.length; j++)
                    test += xo[i].charAt(j);
                if (test.equals(p))
                    return true;
            }
            return false;
        }

        public static boolean checkWinVertically(String[] xo, String p) {
            for (int i = 0; i < xo.length; i++) {
                String test = "";
                for (int j = 0; j < xo.length; j++)
                    test += xo[j].charAt(i);
                if (test.equals(p))
                    return true;
            }
            return false;
        }

        public static boolean checkWinDiagonally(String[] xo, String p) {
            String test = String.valueOf(xo[0].charAt(0) + xo[1].charAt(1) + xo[2].charAt(2));
            String test1 = String.valueOf(xo[0].charAt(2) + xo[1].charAt(1) + xo[2].charAt(0));
            return test.equals(p) || test1.equals(p);
        }
    }
