class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> adj;
    vector<int> in, out, subtreeXor;
    int totalXor = 0;
    int timer = 0;

    struct Edge {
        int parent;
        int child;
    };

    vector<Edge> edgeList;

    void dfs(int u, int parent) {
        in[u] = timer++;
        subtreeXor[u] = nums[u];
        for (int v : adj[u]) {
            if (v != parent) {
                dfs(v, u);
                subtreeXor[u] ^= subtreeXor[v];
            }
        }
        out[u] = timer++;
    }

    bool isSubtree(int u, int v) {
        return in[u] < in[v] && out[v] < out[u];
    }

    int minimumScore(vector<int>& _nums, vector<vector<int>>& edges) {
        nums = _nums;
        n = nums.size();
        adj.resize(n);
        in.resize(n);
        out.resize(n);
        subtreeXor.resize(n);
        totalXor = 0;
        timer = 0;
        edgeList.clear();

        for (int val : nums)
            totalXor ^= val;

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);

        // בנה רשימת קשתות בכיוון parent -> child לפי dfs
        for (int u = 0; u < n; ++u) {
            for (int v : adj[u]) {
                if (in[u] < in[v]) {
                    edgeList.push_back({u, v});
                }
            }
        }

        int res = INT_MAX;
        int m = edgeList.size();

        for (int i = 0; i < m; ++i) {
            int c1 = edgeList[i].child;
            for (int j = i + 1; j < m; ++j) {
                int c2 = edgeList[j].child;
                int x1, x2, x3;

                if (isSubtree(c1, c2)) {
                    x1 = subtreeXor[c2];
                    x2 = subtreeXor[c1] ^ x1;
                    x3 = totalXor ^ subtreeXor[c1];
                } else if (isSubtree(c2, c1)) {
                    x1 = subtreeXor[c1];
                    x2 = subtreeXor[c2] ^ x1;
                    x3 = totalXor ^ subtreeXor[c2];
                } else {
                    x1 = subtreeXor[c1];
                    x2 = subtreeXor[c2];
                    x3 = totalXor ^ x1 ^ x2;
                }

                int mx = max({x1, x2, x3});
                int mn = min({x1, x2, x3});
                res = min(res, mx - mn);
            }
        }

        return res;
    }
};
