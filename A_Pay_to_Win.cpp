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
unordered_map<int, int> dp;
unordered_map<bool, int> vis;
vi dis;
int MAX = 0;

void dijstras(int a, int b, int c, int d) {
    dis[0] = 0;
    // pair {dist, node val}
    set<pair<int, int>> s;
    s.insert({0, 0});
    while (!s.empty()) {
        int currDist, node;
        tie(currDist, node) = *s.begin();
        s.erase(s.begin());

        int child1 = node * 2,
            child2 = node * 3,
            child3 = node * 5,
            child4 = node + 1,
            child5 = node - 1;

        if (child1 < 2 * n && currDist + a < dis[child1]) {
            dis[child1] = currDist + a;
            s.insert({dis[child1], child1});
        }
        if (child2 < 2 * n && currDist + b < dis[child2]) {
            dis[child2] = currDist + b;
            s.insert({dis[child2], child2});
        }
        if (child3 < 2 * n && currDist + c < dis[child3]) {
            dis[child3] = currDist + c;
            s.insert({dis[child3], child3});
        }
        if (child4 < 2 * n && currDist + d < dis[child4]) {
            dis[child4] = currDist + d;
            s.insert({dis[child4], child4});
        }
        if (child5 < 2 * n && currDist + d < dis[child5]) {
            dis[child5] = currDist + d;
            s.insert({dis[child5], child5});
        }
    }
}

void solve() {
    int a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    MAX = 2 * n;
    dp[n] = 0;
    dis.assign(2 * n, INT_MAX);
    dijstras(a, b, c, d);
    cout << dis[n] << '\n';
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        solve();
    }
}