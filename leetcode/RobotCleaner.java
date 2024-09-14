import java.util.*;

class Pos {

    int x;
    int y;

    public Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class RobotCleaner {

    static int[][] moves = {{-1,0},{1,0},{0,1},{0,-1}};
    static int result;

    static int atoi(String s) {
        return Integer.parseInt(s);
    }

    static boolean bfs(int startPosition, int[][] graph, ArrayList<Pos> poss, int n, int m, String[] room) {
        Queue<Pos> que = new LinkedList<>();
        int[][] distances = new int[n][m];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                distances[i][j] = -1;

        que.add(poss.get(startPosition));
        distances[poss.get(startPosition).y][poss.get(startPosition).x] = 0;

        while (!que.isEmpty()) {
            Pos currentPosition = que.poll();

            for (int i = 0; i < 4; i++) {
                int x = currentPosition.x + moves[i][0];
                int y = currentPosition.y + moves[i][1];
                if (x < 0 || y < 0 || x >= m || y >= n || distances[y][x] != -1 || room[y].charAt(x) == 'x')
                    continue;
                distances[y][x] = distances[currentPosition.y][currentPosition.x] + 1;
                que.add(new Pos(x,y));
            }
        }
        for (int i = 0; i < poss.size(); i++) {
            int distance = distances[poss.get(i).y][poss.get(i).x];
            if (distance == -1)
                return false;
            graph[startPosition][i] = distance;
        }
        return true;
    }

    static void printAllRecursive(int n, int[] indexes, ArrayList<Pos> poss, int[][] graph) {
        if(n == 1) {
           int cost = graph[poss.size() - 1][indexes[0]];
           for (int i = 0; i < indexes.length - 1; i++)
               cost += graph[indexes[i]][indexes[i+1]];
           result = Math.min(result, cost);
        } else {
            for(int i = 0; i < n-1; i++) {
                printAllRecursive(n - 1, indexes, poss, graph);
                if(n % 2 == 0) {
                    swap(indexes, i, n-1);
                } else {
                    swap(indexes, 0, n-1);
                }
            }
            printAllRecursive(n - 1, indexes, poss, graph);
        }
    }

    static void swap(int[] input, int a, int b) {
        int tmp = input[a];
        input[a] = input[b];
        input[b] = tmp;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] room;
        String[] parts;

        parts = sc.nextLine().split(" ");
        int m = Integer.parseInt(parts[0]);
        int n = Integer.parseInt(parts[1]);

        while (m != 0 && n != 0) {
            result = Integer.MAX_VALUE;
            ArrayList<Pos> poss = new ArrayList<>();
            Pos robot = null;
            room = new String[n];

            for (int i = 0; i < n; i++) {
                room[i] = sc.nextLine();
                for (int j = 0; j < m; j++) {
                    if(room[i].charAt(j) == 'o') {
                        robot = new Pos(j,i);
                    } else if (room[i].charAt(j) == '*') {
                        poss.add( new Pos(j,i));
                    }
                }
            }
            poss.add(robot);
            int[][] graph = new int[poss.size()][poss.size()];
            boolean possible = true;
            int[] indexes = new int[poss.size() - 1];

            for (int i = 0; i < poss.size(); i++) {
                possible = bfs(i, graph, poss, n, m, room);
                if (possible == false)
                    break;
                if (i != poss.size() - 1)
                    indexes[i] = i;
            }
            if (possible) {
                printAllRecursive(poss.size() - 1, indexes, poss, graph);
                System.out.println(result);

                for(int i = 0; i<room.length; i++) {
                    System.out.println(room[i]);
                }
                for(int j = 0; j < graph.length; j++) {
                    System.out.println(Arrays.toString(graph[j]));
                }
            }
            else System.out.println(-1);

            parts = sc.nextLine().split(" ");
            m = Integer.parseInt(parts[0]);
            n = Integer.parseInt(parts[1]);
        }
    }
}
