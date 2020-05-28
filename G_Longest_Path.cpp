#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pqMax priority_queue<int>
#define pqMin priority_queue<int, vector<int>, greater<int>>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie()
int n, t, i, j, k;

void dfs(int i, unordered_map<int, vi>& graph, vector<bool>& vis, vi& dp) {
    vis[i] = true;
    for (int child : graph[i]) {
        if (!vis[child]) {
            dfs(child, graph, vis, dp);
        }
        dp[i] = max(dp[child] + 1, dp[i]);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vi> graph;
    vi dp(n + 1);
    vector<bool> vis(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, graph, vis, dp);
    }
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << '\n';
}

int32_t main() {
    FAST;
    solve();
}