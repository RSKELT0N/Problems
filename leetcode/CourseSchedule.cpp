class Solution {
public:
    bool ok = true;
    void dfs(vector<list<int>>& nodes,int* visited,int index) {
        if(visited[index] == 1)
            return;
        visited[index] = 1;
        for(auto i : nodes[index]) {
            if(visited[i] == 0)
                dfs(nodes,visited,i);
            else if(visited[i] == 1) {
                ok = false;
                return;
            }
        }
        visited[index] = 2;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> nodes(numCourses);
        int visited[numCourses];
        memset(visited,0,sizeof(visited));
        
        for(auto a : prerequisites)
            nodes[a[1]].push_back(a[0]);
        
        // for(auto i : nodes) {
        //     for(auto j : i)
        //         cout << j <<  " ";
        //     cout << "\n";
        // }
        
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0)
                dfs(nodes,visited,i);
            if(!ok)
                return false;
        }
        
        // for(auto i : visited)
        //     cout << i << " ";
        
        return true;
    }
};
