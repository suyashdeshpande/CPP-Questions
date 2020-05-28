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

// origin source, node 0
int tsp(int mask, int i, const int& VISITED_ALL, vvi& graph, vvi& dp) {
    if (mask == VISITED_ALL) {
        return graph[i][0];
    }

    if (dp[mask][i] != -1)
        return dp[mask][i];

    int ans = INT_MAX;
    for (int c = 0; c < n; c++) {
        // univisted node
        if ((mask & (1 << c)) == 0) {
            int tempAns = graph[i][c] + tsp((mask | (1 << c)), c, VISITED_ALL, graph, dp);
            ans = min(ans, tempAns);
        }
    }
    return dp[mask][i] = ans;
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        cin >> n;
        const int VISITED_ALL = (1 << n) - 1;
        vvi graph(n, vi(n, INT_MAX));
        vvi dp(VISITED_ALL + 1, vi(n, -1));
        // for (int i = 0; i < n; i++) {
        //     graph[i][i] = 0;
        //     int x, y, d;
        //     cin >> x >> y;
        //     graph[x][y] = d;
        //     graph[y][x] = d;
        // }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];
        cout << tsp(1, 0, VISITED_ALL, graph, dp) << '\n';
    }
}