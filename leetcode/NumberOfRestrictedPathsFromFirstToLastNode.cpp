class Solution {
public:
    void print_adjlist(const std::vector<std::vector<std::pair<int, int>>> & adj)
    {
        for(int i = 1; i < adj.size(); i++)
        {
            std::cout << i << ": ";
            for(auto e : adj[i])
                std::cout << e.first << "(" << e.second << ") ";

            std::cout << "\n";
        }
        std::cout << "\n";
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);

        std::vector<std::vector<std::pair<int, int>>> adjlist(n + 1);

        for(std::vector<int> & edge : edges)
        {
            adjlist[edge[0]].push_back({edge[1], edge[2]});
            adjlist[edge[1]].push_back({edge[0], edge[2]});
        }

        print_adjlist(adjlist);

        // Dijkstra from node n
        std::vector<int> dist(n + 1, INT_MAX);
        dist[n] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, n});

        while (!pq.empty()) {
            auto [curr_dist, src] = pq.top();
            pq.pop();

            if (curr_dist > dist[src]) continue;

            for (auto [dst, w] : adjlist[src]) {
                if (dist[dst] > dist[src] + w) {
                    dist[dst] = dist[src] + w;
                    pq.push({dist[dst], dst});
                }
            }
        }

        // DFS-like traversal to count restricted paths from node 1 to node n
        const int MOD = 1e9 + 7;
        vector<int> memo(n + 1, -1);

        std::function<int(int)> dfs = [&](int src) -> int {
            if (src == n) return 1;
            if (memo[src] != -1) return memo[src];

            int res = 0;
            for (auto &e : adjlist[src]) {
                int dst = e.first;
                if (dist[src] > dist[dst]) {
                    res = (res + dfs(dst)) % MOD;
                }
            }
            return memo[src] = res;
        };

        return dfs(1);
    }
};
