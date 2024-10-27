// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// To store the resulting
// sum of the cost
int canTake;
 
// To store largest
// cost leaf vertex
int best;
 
vector<int> dp;
vector<bool> vis;
 
// DFS Traversal to find the update
// the maximum cost of from any
// node to leaf
int dfs(vector<vector<int> >& g,
        int* cost, int u, int pre)
{
 
    // Mark vertex as visited
    vis[u] = true;
 
    // Store vertex initial cost
    dp[u] = cost[u];
 
    // Initially assuming edge
    // not to be traversed
    bool check = 1;
 
    int cur = cost[u];
    for (auto& x : g[u]) {
 
        // Back edge found so,
        // edge can be part of
        // traversal
        if (vis[x] && x != pre) {
            check = 0;
        }
 
        // New vertex is found
        else if (!vis[x]) {
 
            // Bitwise AND the current
            // check with the returned
            // check by the previous
            // DFS Call
            check &= dfs(g, cost, x, u);
 
            // Adds parent and its
            // children cost
            cur = max(cur,
                      cost[u] + dp[x]);
        }
    }
 
    // Updates total cost of parent
    // including child nodes
    dp[u] = cur;
 
    // Edge is part of the cycle
    if (!check) {
 
        // Add cost of vertex
        // to the answer
        canTake += cost[u];
    }
    else {
 
        // Updates the largest
        // cost leaf vertex
        best = max(best, dp[u]);
    }
 
    return check;
}
 
// Function to find the maximum cost
// from source vertex such that no
// two edges is traversed twice
int FindMaxCost(vector<vector<int> >& g,
                int* cost, int source)
{
    // DFS Call
    dfs(g, cost, source, -1);
 
    // Print the maximum cost
    cout << canTake + best;
}
 
// Driver Code
int main()
{
    int n = 5, m = 5;
    dp.resize(n+1);
      vis.resize(n+1);
    // Cost Array
    int cost[] = { 2, 2, 8, 6, 9 };
 
    vector<vector<int> > g(n);
 
    // Given Graph
    g[0].push_back(1);
    g[1].push_back(0);
    g[0].push_back(2);
    g[2].push_back(0);
    g[0].push_back(3);
    g[3].push_back(0);
    g[1].push_back(2);
    g[2].push_back(1);
    g[1].push_back(4);
    g[4].push_back(1);
 
    // Given Source Node
    int source = 1;
 
    // Function Call
    FindMaxCost(g, cost, source);
    return 0;
}