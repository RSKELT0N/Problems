class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length() == numRows)
            return s;
        
        int x = numRows;
        int y = s.length() * 2;
        
        char table[x][y];
        memset(table, '\0', sizeof(table));
        
        int posX = 0, posY = 0;
        for(int i = 0; i < s.length(); i++) {
            if(posX == (x-1)) {
                while(posX != 0) {
                    table[posX][posY] = s[i];
                    posX--;
                    posY++;
                    i++;
                }
            }
            table[posX][posY] = s[i];
            posX++;
        }
        
        std::string word = {};
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                if(table[i][j])
                    word += table[i][j];
            }
        }
        return word;
    }
};
