class Solution {
    public int maxProfit(int[] prices) {
      int num = 0;
        int sum = 0;
        
        for (int i = 0; i < prices.length-1; i++) {
            num = prices[i + 1] - prices[i];
            if (num > 0)
                sum += num;
        }
        return sum;  
    }
}
