#include <bits/stdc++.h>
using namespace std;

#define int long long

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

struct Me {
    int x, y, time;
};

bool validRange(int a, int b, int c) {
    return b <= a && a <= c;
}

int solve() {
    int x, y;
    cin >> x >> y;
    unordered_map<pair<int, int>, int, hash_pair> a;
    string s;
    cin >> s;
    int tx = y, ty = x;
    int time = 0;
    int minX = y - s.length(), maxX = y + s.length();
    int minY = x - s.length(), maxY = x + s.length();
    for (char i : s) {
        time++;
        if (i == 'N') {
            tx++;
        } else if (i == 'S') {
            tx--;
        } else if (i == 'E') {
            ty++;
        } else {
            ty--;
        }
        a[{tx, ty}] = time;
    }

    queue<Me> q;
    unordered_map<pair<int, int>, bool, hash_pair> vis;
    q.push({0, 0, 0});
    vis[{0, 0}] = true;
    int ans = INT_MAX;
    while (!q.empty()) {
        Me node = q.front();
        q.pop();
      
        // if I reach before or with Pepper, this is answer
        if (node.time <= a[{node.x, node.y}] && a[{node.x, node.y}] != 0) {
            ans = min(a[{node.x, node.y}], ans);
        }

        // north
        if (!vis[{node.x + 1, node.y}] && validRange(node.x, minX, maxX) && validRange(node.y, minY, maxY)) {
            q.push({node.x + 1, node.y, node.time + 1});
            vis[{node.x + 1, node.y}] = true;
        }
        // south
        if (!vis[{node.x - 1, node.y}] && validRange(node.x, minX, maxX) && validRange(node.y, minY, maxY)) {
            q.push({node.x - 1, node.y, node.time + 1});
            vis[{node.x - 1, node.y}] = true;
        }
        //east
        if (!vis[{node.x, node.y + 1}] && validRange(node.x, minX, maxX) && validRange(node.y, minY, maxY)) {
            q.push({node.x, node.y + 1, node.time + 1});
            vis[{node.x, node.y + 1}] = true;
        }
        //west
        if (!vis[{node.x, node.y - 1}] && validRange(node.x, minX, maxX) && validRange(node.y, minY, maxY)) {
            q.push({node.x, node.y - 1, node.time + 1});
            vis[{node.x, node.y - 1}] = true;
        }
    }
    if (ans == INT_MAX) return -1;
    return ans;
}

int32_t main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int ans = solve();
        if (ans != -1) {
            cout << ans << '\n';
        } else
            cout << "IMPOSSIBLE\n";
    }
}