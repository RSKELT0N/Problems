class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int amount = 0;
        int i = 0, j = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        while(i < g.size() && j < s.size())
        {
            if(g[i] > s[j]) {
                j++;
            } else {
                amount++;
                j++;
                i++;
            }
        }
        return amount;
    }
};
