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

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int, int>, int, hash_pair> dp;

// return r, c to exit , min persons hate
int hate(int r, int c, vvi &grid) {
    if (r < 1 || r >= grid.size() || c < 1 || c >= grid.size()) {
        return 0;
    }
    if (dp[{r, c}]) {
        return dp[{r, c}];
    }
    int ans = INT_MAX;
    if (c + 1 < grid.size()) {
        ans = hate(r, c + 1, grid);
        if (grid[r][c + 1] != -1) {
            ans = 1 + ans;
        }
    }
    if (c - 1 >= 1) {
        int tempAns = hate(r, c - 1, grid);
        if (grid[r][c - 1] != -1) {
            tempAns = 1 + ans;
        }
        ans = min(ans, tempAns);
    }
    if (r - 1 >= 1) {
        int tempAns = hate(r - 1, c, grid);
        if (grid[r - 1][c] != -1) {
            tempAns = 1 + ans;
        }
        ans = min(ans, tempAns);
    }
    if (r + 1 < grid.size()) {
        int tempAns = hate(r + 1, c, grid);
        if (grid[r + 1][c] != -1) {
            tempAns = 1 + ans;
        }
        ans = min(ans, tempAns);
    }
    return dp[{r, c}] = ans;
}

void solve() {
    cin >> n;
    vi p(n);
    for (int &i : p) cin >> i;
    vvi grid(n + 1, vi(n + 1, 0));
    int ans = 0;
    for (int curr : p) {
        dp.clear();
        int r = (curr / n) + 1;
        int c = curr - (n * r);
        ans += hate(r, c, grid);
    }
    cout << ans << '\n';
}

int32_t main() {
    FAST;
    solve();
}