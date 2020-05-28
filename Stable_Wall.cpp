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

void topologicalSort(unordered_map<char, vi> &graph, unordered_map<char, int> &indegree,
                     unordered_set<char> &indegZero, string &ans) {
    while (!indegZero.empty()) {
        char node = *indegZero.begin();
        indegZero.erase(node);
        ans += node;
        for (char i : graph[node]) {
            indegree[i]--;
            if (indegree[i] == 0) {
                indegZero.insert(i);
                indegree.erase(i);
            }
        }
    }
    if (indegZero.empty() && !indegree.empty()) {
        cout << -1 << '\n';
        return;
    }
    cout << ans << '\n';
}

void solve() {
    int r, c;
    cin >> r >> c;
    string m[r];
    for (int i = 0; i < r; i++) {
        cin >> m[i];
    }
    unordered_map<char, vi> graph;
    unordered_map<char, int> indegree;
    unordered_set<char> indegZero;
    string ans = "";
    for (i = 0; i <= r - 2; i++) {
        for (j = 0; j < c; j++) {
            indegZero.insert(m[i][j]);
            if (m[i + 1][j] != m[i][j]) {
                graph[m[i + 1][j]].push_back(m[i][j]);
                indegree[m[i][j]]++;
            }
        }
    }
    for (auto i : graph) {
        for (char j : i.second) {
            if (indegZero.find(j) != indegZero.end()) {
                indegZero.erase(j);
            }
        }
    }
    topologicalSort(graph, indegree, indegZero, ans);
}

int32_t main() {
    FAST;
    cin >> t;
    int tt = 1;
    while (t--) {
        cout << "Case #" << tt << ": ";
        tt++;
        solve();
    }
}