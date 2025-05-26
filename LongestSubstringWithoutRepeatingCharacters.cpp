class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> map = {};
        int max = 0;

        for(int l = 0, r = 0; l < s.size(); l++)
        {
            while(r < s.size() && map[s[r]-'a'] == 0)
            {
                map[s[r]-'a'] = 1;
                r++;
            }
            max = max > r-l ? max : r-l;
            map[s[l]-'a'] = 0;
        }
        return max;
    }
};
