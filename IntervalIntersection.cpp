class Solution {
public:
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> points;
        int p1 = 0,p2 = 0;

        if(A.size() == 0 || B.size() == 0)
            return {};
        // if(A[0][0] == B[0][0] && A[0][1] == B[0][1])
        //     return {{A[0][0],A[0][1]}};
        
        while(p1!=A.size() && p2!=B.size()) {
            int start = max(A[p1][0],B[p2][0]);
            int end = min(A[p1][1],B[p2][1]);
            
            if(end-start >= 0)
                points.push_back({start,end});
            
            if(end==A[p1][1])
                p1++;
            else p2++;
        }
        
        
        
        return points;
    }
};
