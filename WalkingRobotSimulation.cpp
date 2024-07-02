struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
public:
    int curr_direction = 0;
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void update(int direction)
    {
        if(direction == -1)
            curr_direction = (curr_direction + 1) % 4;
        else
            curr_direction = (((curr_direction - 1) % 4) + 4) % 4;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        std::unordered_set<std::pair<int,int>, pair_hash> obsts;

        for(const auto & ob : obstacles)
            obsts.insert({ob[0], ob[1]});

        int x = 0;
        int y = 0;
        int max = INT_MIN;

       for(int & com : commands)
       {
            if(com < 0)
            {
                update(com);
                continue;
            }

            for(int j = 0; j < com; j++)
            {
                if(obsts.find({x + (1 * directions[curr_direction][1]), y + (1 * directions[curr_direction][0])}) != obsts.end())
                    break;

                x += 1 * directions[curr_direction][1];
                y += 1 * directions[curr_direction][0];
            }

            int euclid_dist = x * x + y * y;

            if(max < euclid_dist)
                max = euclid_dist;
       }
       return max;
    }
};
