// 2642. Design Graph With Shortest Path Calculator

/*
There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1.
The edges of the graph are initially represented by the given array edges where edges[i] = [fromi, toi, edgeCosti]
meaning that there is an edge from fromi to toi with the cost edgeCosti.

Implement the Graph class:

    Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
    addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost].
    It is guaranteed that there is no edge between the two nodes before adding this one.
    

    int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2.
    If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.
*/

struct Edge
{
    int t;
    int c;

    Edge(int to, int cost) : t(to), c(cost) {}
};
class Graph
{
private:
    int nodes;
    std::vector<std::vector<Edge>> adj;
public:
    Graph(int n, vector<vector<int>>& edges)
    {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        nodes = n;
        adj = std::vector<std::vector<Edge>>(n);

        for(const auto e_ : edges)
            adj[e_[0]].emplace_back(e_[1], e_[2]);
    }
    
    void addEdge(vector<int> edge)
    {
        adj[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2)
    {
        std::vector<std::pair<int, long long>> visited(nodes, {-1, INT_MAX});
        visited[node1] = {-1, 0LL};
        std::queue<int> q;
        q.push(node1);

        while(!q.empty())
        {
            int src = q.front();
            q.pop();

            if(src == node2)
                continue;

            long long cost_f = visited[src].second;

            for(const Edge x : adj[src])
            {
                long long cost_x = cost_f + x.c; 

                if(cost_x >= visited[x.t].second) continue;

                visited[x.t] = {src, cost_x};
                q.push(x.t);
            }
        }

        int n = node2;
        while(n != -1)
        {
            std::cout << n;
            if(visited[n].first != -1)
                std::cout << " <- ";
            
            n = visited[n].first;
        }
        std::cout << "\n";

        return visited[node2].second == INT_MAX ? -1 : visited[node2].second;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
