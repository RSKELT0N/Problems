import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        HashMap<Character, Integer> roman = new HashMap<>();
        roman.put('I', 1);
        roman.put('V', 5);
        roman.put('X', 10);
        roman.put('L', 50);
        roman.put('C', 100);
        roman.put('D', 500);
        roman.put('M', 1000);


        while (true) {
            System.out.println(result(sc.nextLine(), roman));
        }
    }

    public static int result(String result, HashMap roman) throws StringIndexOutOfBoundsException, NullPointerException {
        int res = 0;
        int amountOfCharsOfI = 0;
        int amountOfCharsOfV = 0;
        int amountOfCharsOfX = 0;
        try {
            for (int i = 0; i < result.length(); i++) {
                if (result.charAt(i) == 'I')
                    amountOfCharsOfI++;
                else if (result.charAt(i) == 'V')
                    amountOfCharsOfV++;
                else if (result.charAt(i) == 'X')
                    amountOfCharsOfX++;
                if (amountOfCharsOfI > 3
                        || amountOfCharsOfV > 3
                        || amountOfCharsOfX > 3) {
                    return 0;
                }
                res += (int) roman.get(result.charAt(i));
                if (result.charAt(i) == 'I') {
                    if (result.charAt(i + 1) == 'V' || result.charAt(i + 1) == 'X') {
                        res -= (int) roman.get('I') * 2;
                    }
                    } else if (result.charAt(i) == 'X') {
                        if (result.charAt(i + 1) == 'L' || result.charAt(i + 1) == 'C') {
                            res -= (int) roman.get('X') * 2;
                        }
                    } else if (result.charAt(i) == 'C') {
                        if (result.charAt(i + 1) == 'D' || result.charAt(i + 1) == 'M') {
                            res -= (int) roman.get('C') * 2;
                        }
                    } else
                        continue;
                }
        } catch (StringIndexOutOfBoundsException | NullPointerException e) {
        }
        return res;
    }

}
