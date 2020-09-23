class Solution {
public:
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<vector<int>> points;
        
        if(A.size() == 0 || B.size() == 0)
            return {};
        if(A[0][0] == B[0][0] && A[0][1] == B[0][1])
            return {{A[0][0],A[0][1]}};
        
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                if(A[i][1] >= B[j][0] && B[j][0] >= A[i][0])
                    if(A[i][1] <= B[j][1]) {
                        points.push_back({B[j][0],A[i][1]});
                    } else points.push_back({B[j][0],B[j][1]}); 
                if(B[j][1] == A[i][0])
                    points.push_back({B[j][1],A[i][0]});
                if(B[j][0] <= A[i][0] && A[i][1] <= B[j][1])
                    points.push_back({A[i][0],A[i][1]});
                }
            }
        
        return points;
    }
};
