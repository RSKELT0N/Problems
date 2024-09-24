// 2591. Distribute Money to Maximum Children

/*
You are given an integer money denoting the amount of money (in dollars) 
that you have and another integer children denoting the number of children 
that you must distribute the money to.

You have to distribute the money according to the following rules:

    All money must be distributed.
    Everyone must receive at least 1 dollar.
    Nobody receives 4 dollars.

Return the maximum number of children who may receive exactly 8 dollars
if you distribute the money according to the aforementioned rules. 
If there is no way to distribute the money, return -1.

*/

class Solution {
public:
    int distMoney(int money, int children)
    {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        if(money < children) return -1;
        if(money <= 8) return 0;

        int amt = std::min(children, money / 8), r_m = money % 8; 

        // Check if rem is 4 and alst child.
        if((r_m == 4 && children-amt == 1)) amt--;
        // Check if children is divisible by 8 and there is a rem.
        if(amt == children && r_m > 0) amt--;
        // Check if children is divisible by 8 and there is money left over.
        if(children == amt && money-(amt*8) > 0) amt--;

        // Check if money left over is less than the amount of children to distribute. Repeat until there is enough.
        while(money-(amt*8) < (children-amt)) amt--;

        return amt;
    }
};
