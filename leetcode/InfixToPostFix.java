import java.util.HashSet;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int expressions = sc.nextInt();
        String line = "";
        for(int i = 0; i <= expressions; i++) {
            System.out.println(infixToPostfix(sc.nextLine()));
        }

    }

    public static String infixToPostfix(String expression) {
        // initializing empty String for result
        String result = new String("");
        boolean isNumber = false;

        //Creating the stack, to help us solve the operators being tested
        Stack<Character> stack = new Stack<>();

        //For loop for each value character within the expression
        for (int i = 0; i < expression.length(); ++i) {
            //Storing the character in variable (c)
            char c = expression.charAt(i);

            // If the character at the position of i, is a letter (operand) add it towards the result String.
            if (Character.isLetterOrDigit(c)) {
                result += c;
                continue;
            } else {
                //if false, add a " ".
                result += "";
            }

            // If the character at this position is equal to a "(", add to stack, highest precedence
            if (c == '(')
                stack.push(c);

                //  If the scanned character is an ')', pop and output from the stack
                // until an '(' is encountered.
            else if (c == ')') {
                while (!stack.isEmpty() && stack.peek() != '(')
                    result += "" + stack.pop() + "";

                if (!stack.isEmpty() && stack.peek() != '(')
                    return "Invalid Expression";
                else
                    stack.pop();
            } else // an operator is encountered
            {
                //Tests the operator precedence, with the use of the method (operatorPrecedence)
                while (!stack.isEmpty() && operatorPrecedence(c) <= operatorPrecedence(stack.peek())) {
                    //if "(" is valid, expression is invalid, throw an error
                    if (stack.peek() == '(')
                        return "Invalid Expression";
                    result += "" + stack.pop() + "";
                }
                //if operator is valid, push operator of stack
                stack.push(c);
            }

        }

        // if any operator are still in stack at end of expression, pop them out.
        //At the end of the postfix expression
        while (!stack.isEmpty()) {
            if (stack.peek() == '(')
                return "Invalid Expression";
            result += "" + stack.pop() + "";
        }
        //Return result, (postfix expression)
        return result;
    }

    static int operatorPrecedence(char ch) {
        switch (ch) {
            case '+':
            case '-':
                //equal precedence
                return 1;
            case '*':
            case '/':
                //equal precedence
                return 2;
            case '^':
                return 3;
        }
        return -1;
    }
}
