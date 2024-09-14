public class SudokuSolver {

    public static final int SIZE = 9;
    public static final int WHITE_POSITION = 0;
    public static final char WHITE_POSITION_CHAR = '.';

    private boolean solved;

    private class Position {
        int y, x;
        Position(int y, int x) {
            this.y = y; this.x = x;
        }
    }

    private boolean isValidInput(int[][] sudoku) {
        if (sudoku.length != SIZE)
            return false;
        for (int i = 0; i < sudoku.length; i++) {
            if (sudoku[i].length != SIZE)
                return false;
            for (int j = 0; j < sudoku[i].length; j++)
                if (sudoku[i][j] < 0 || sudoku[i][j] > 9)
                    return false;
        }
        return true;
    }

    public int[][] solve(final int[][] sudoku) throws IllegalArgumentException {
        if (sudoku == null || !isValidInput(sudoku))
            throw new IllegalArgumentException("Invalid sudoku!");

        solved = false;
        int[][] result = new int[SIZE][SIZE];
        Position[] whitePositions = new Position[SIZE * SIZE];
        int size = 0;

        for (int i = 0; i < result.length; i++)
            for (int j = 0; j < result[i].length; j++) {
                result[i][j] = sudoku[i][j];
                if (sudoku[i][j] == WHITE_POSITION)
                    whitePositions[size++] = new Position(i,j);
            }

        solve(result, whitePositions, size, 0);
        return solved ? result : null;
    }

    private boolean rowColumnCollision(int y, int x, int value, int[][] sudoku) {
        for (int i = 0; i < SIZE; i++)
            if ((i != y && sudoku[i][x] == value) ||
                (i != x && sudoku[y][i] == value))
                return true;
        return false;
    }

    private boolean squareCollision(int y, int x, int value, int[][] sudoku) {
        int startY = 3 * (y / 3);
        int startX = 3 * (x / 3);

        for (int i = startY; i < startY + 3; i++)
            for (int j = startX; j < startX + 3; j++)
                if (i != y && j != x && sudoku[i][j] == value)
                    return true;
        return false;
    }

    private void solve(int[][] sudoku, Position[] whitePositions, int size, int index) {
        if (index == size) {
            solved = true;
            return;
        }

        int y = whitePositions[index].y;
        int x = whitePositions[index].x;

        for (int value = 1; value <= 9; value++) {
            if (rowColumnCollision(y, x, value, sudoku) ||
                squareCollision(y, x, value, sudoku))
                continue;

            sudoku[y][x] = value;
            solve(sudoku, whitePositions, size, index + 1);
            if (solved)
                return;
            sudoku[y][x] = WHITE_POSITION;
        }
    }

    public void printSudoku(final int[][] sudoku) throws IllegalArgumentException {
        if (sudoku == null || !isValidInput(sudoku))
            throw new IllegalArgumentException("Invalid sudoku!");

        System.out.println("-------------------------");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (j == 0)
                    System.out.print("| ");
                if (sudoku[i][j] != WHITE_POSITION)
                    System.out.print(sudoku[i][j]);
                else System.out.print(WHITE_POSITION_CHAR);
                if (j != SIZE - 1) {
                    if ((j+1) % 3 == 0)
                        System.out.print(" | ");
                    else System.out.print(" ");
                }
                else System.out.print(" |");
            }
            System.out.println();
            if ((i+1) % 3 == 0)
                System.out.println("-------------------------");
        }
    }
}
