class Solution {
public:
    int moves[4][2] = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return image;
        
        int color = image[sr][sc];
        image[sr][sc] = newColor;
        
        queue<pair<int,int>> q;
        
        q.push({sr,sc});
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int x = curr.second;
            int y = curr.first;
            
            for(int i = 0; i < 4; i++) {
                int newY = y + moves[i][0];
                int newX = x + moves[i][1];
                
                if(newY < 0 || newY >= image.size() || newX < 0 || newX >= image[0].size()) {
                    continue;
                }
                if(image[newY][newX] == color) {
                    image[newY][newX] = newColor;
                    q.push({newY,newX});
                }
            }
        }
        return image;
        
    }
};
