/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/

class Solution {
public:
    void solve(std::vector<std::string> & p, int n, int x, std::string s)
    {
        if(x == 0 && n==0)
        {
            p.push_back(s);
            return;
        }
        
        if(n > 0) solve(p, n - 1, x + 1, s + "(");
        if(x > 0) solve(p, n, x - 1, s + ")");
    }

    vector<string> generateParenthesis(int n)
    {
        std::vector<std::string> p;
        solve(p, n, 0, "");

        return p;
    }
};
