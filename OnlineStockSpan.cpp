// class StockSpanner {
// public:
//     vector<int> stock;
//     int ans;
//     StockSpanner() {
//         stock = vector<int>();
//         ans = 0;
//     }
//  Same Idea but TLE
//     int next(int price) {
//         ans = 0;
//         stock.push_back(price);
//         if(stock.size() == 1)
//             return 1;
//         for(int i = stock.size()-1; i >=0; i--) {
//             if(price >= stock[i])
//                 ans++;
//             else break;
//         }
//         return ans;
//     }
// };

// As second solution uses a stack and pops whenever value in stack is less than price.
//Then from there working out the curr val pos from that last stored. Therefore only iterating through the values summaried
//as they have already been testing if it less than or equal to the price. Therefore ordered.
class StockSpanner {
public:
    stack<pair<int,int>> stock;
    int curr;
    StockSpanner() {
        stock = stack<pair<int,int>>();
        curr = 1;
        ios::sync_with_stdio(false);
        cin.tie(0);
    }

    int next(int price) {
        int ans;
        while(!stock.empty() && stock.top().first <= price)
            stock.pop();
        if(stock.empty())
            ans = curr;
        else ans = curr-stock.top().second;
        stock.push({price,curr++});
        return ans;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
