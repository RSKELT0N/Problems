/*
139. Word Break
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

// Using Top Down Memoization
class Solution {
public:
    int _max;
    std::unordered_map<int, bool> memo;
    bool solve(const std::unordered_set<std::string> & dict, const std::string & s, int i, int size)
    {
        if(memo.find(i) != memo.end())
            return memo[i];

        if(i == size)
            return true;

        // m: 0 -> min(max_prefix, abs(s.size()-i)) ~ Ensuring no overflow.
        for(int m = 1; m <= std::min((size_t)_max, (s.size()-i)); m++)
        {
            std::string str = s.substr(i, m);
            
            if(dict.contains(str))
            {
                if(solve(dict, s, i + m, size))
                    return true;
            }
        }

        memo[i] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict)
    {
        _max = 0; 
        std::unordered_set<std::string> dict;

        for(int i = 0; i < wordDict.size(); i++)
        {
            if(_max < wordDict[i].size())
                _max = wordDict[i].size();
            dict.insert(wordDict[i]);
        }

        return solve(dict, s, 0, s.length());
    }
};
