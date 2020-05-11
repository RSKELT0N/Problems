class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int[][] values = new int[triangle.size()][triangle.size()];
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < values.length; i++) {
            for (int j = 0; j < values[i].length; j++) {
                values[i][j] = Integer.MAX_VALUE;
            }
        }
        values[0][0] = triangle.get(0).get(0);

//        for (int i = 0; i < values.length; i++) {
//            for(int j = 0; j < values[i].length; j++) {
//                System.out.print(values[i][j]+" ");
//            }
//            System.out.println();
//        }

        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle.get(i).size(); j++) {
                if (j == 0)
                    values[i][j] = values[i - 1][j] + triangle.get(i).get(j);
                else
                    values[i][j] = Math.min(values[i - 1][j - 1], values[i - 1][j]) + triangle.get(i).get(j);
            }
        }

//        for (int i = 0; i < values.length; i++) {
//            for(int j = 0; j < values[i].length; j++) {
//                System.out.print(values[i][j]+" ");
//            }
//            System.out.println();
//        }

        for (int i = 0; i < values[values.length - 1].length; i++)
            if (min > values[values.length - 1][i])
                min = values[values.length - 1][i];

        return min;
    }
}
