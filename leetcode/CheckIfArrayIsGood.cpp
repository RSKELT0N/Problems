// 2784. Check if Array is Good

/*
You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].

base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, 
plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].

Return true if the given array is good, otherwise return false.

Note: A permutation of integers represents an arrangement of these numbers.
*/

class Solution {
public:
    bool isGood(vector<int>& nums)
    {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);
        
        int visited[nums.size()], c = 0;
        memset(visited, 0, sizeof(visited));

        for(const auto x : nums)
        {
            if(x >= nums.size()) return false;

            if(x == nums.size() - 1)
            {
                if(visited[x] < 2)
                { 
                    visited[x]++;
                    c++;
                }
                continue;
            }

            if(visited[x] == 0)
            {
                visited[x]++;
                c++;
            }
        }

        return c == nums.size() && visited[nums.size() - 1] == 2;
    }
};
