
class Solution 
{
public:
    bool ok = true;
    
    void solve(vector<list<int>>& adj, int *colours, int startColour, int index) {
        if(!ok)
            return;
        colours[index] = startColour;
        for(int i : adj[index]) {
            if(colours[i] == startColour) {
                ok = false;
                return;
            } else if(colours[i] == -1) {
                solve(adj,colours,!startColour,i);
            }
        }
    }
    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        vector<list<int>> adj(N);
        
        for(auto& i : dislikes) {
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        // for(auto i : adj) {
        //     for(auto j : i)
        //         cout << j << " ";
        //     cout << endl;
        // }
        int colours[N];
        memset(colours,-1,sizeof(colours));
        for(int i = 0; i < N; i++) {
            if(colours[i] == -1) {
                solve(adj,colours,1,i);
            }
            if(!ok)
                return false;
        }
        return true;
    }
};
