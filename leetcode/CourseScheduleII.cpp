class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> indeg(numCourses, 0);
        std::vector<std::vector<int>> adj_list(numCourses);
        std::queue<int> q;
        std::vector<int> order;

        for(auto prereq : prerequisites) {
            indeg[prereq[0]]++;
            adj_list[prereq[1]].push_back(prereq[0]);
        }

        for(int i = 0; i < indeg.size(); i++)
            if(indeg[i] == 0) q.push(i);

        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            order.push_back(v);

            for(auto edge : adj_list[v]) {
                if(--indeg[edge] == 0)
                    q.push(edge);
            }
        }

        for(auto deg : indeg)
            if(deg > 0) return {};

        return order;
    }
};
