class Solution {
public:
    int secondHighest(string s) {
        int l1 = -1, l2 = -1;
        for(auto c : s)
        {
            if('0' <= c && c <= '9')
            {
                int val = c - '0';
                if(val > l1) {
                    l2 = l1;
                    l1 = val;
                } else if(val > l2 && val < l1)
                    l2 = val;
            }
        }

        return l2;
    }
};
