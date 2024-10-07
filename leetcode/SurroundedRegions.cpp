/*
130. Surrounded Regions

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

    Connect: A cell is connected to adjacent cells horizontally or vertically.
    Region: To form a region connect every 'O' cell.
    Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.
*/

class Solution {
public:
    void draw(std::vector<vector<char>>& board, int m, int n)
    {
        std::cout << "\n\n";
        for(int y = 0; y < m; y++)
        {
            for(int x = 0; x < n; x++)
            {
                std::cout << board[y][x] << " ";
            }
            std::cout << "\n";
        } 
    }

    int coords[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void solve(vector<vector<char>>& board)
    {
        std::set<std::pair<int, int>> valid_o;
        std::stack<std::pair<int, int>> s;
        
        int m = board.size();
        int n = board[0].size();

        for(int y = 0; y < m; y++)
        {
            for(int x = 0; x < n; x++)
            {
                if(y==0 || y==m-1 || x==0 || x == n-1)
                {
                    if(board[y][x] == 'O')
                        s.push({y, x});
                }
            }
        }

        std::stack<std::pair<int, int>> inner_s;

        while(!s.empty())
        {
            auto & coord = s.top();
            int y = coord.first;
            int x = coord.second;
            s.pop();

            valid_o.insert({y, x});

            for(int i = 0; i < 4; i++)
            {
                int new_y = y + coords[i][0];
                int new_x = x + coords[i][1];

                if(new_y < 0 || new_y == m || new_x < 0 || new_x == n)
                    continue;

                if(board[new_y][new_x] == 'X')
                    continue;

                if(valid_o.find({new_y, new_x}) == valid_o.end())
                    s.push({new_y, new_x});
            }
        }

        for(int y = 0; y < m; y++)
        {
            for(int x = 0; x < n; x++)
            {
                if(board[y][x] == 'O')
                {
                    if(valid_o.find({y, x}) == valid_o.end())
                        board[y][x] = 'X';
                }
            }
        }
    }
};
