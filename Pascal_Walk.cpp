#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> pascal;
vector<vector<bool>> visited;
vector<pair<int, int>> path;

void createPascal() {
    pascal.assign(500, vector<int>(500));
    for (int line = 1; line < 500; line++) {
        int C = 1;
        for (int i = 1; i <= line; i++) {
            pascal[line][i] = C;
            C = C * (line - i) / i;
        }
    }
}

bool solved(int i, int j, int target) {
    if (i < 1 || j < 1 || i > 500 || j > i || visited[i][j]) return false;
    if (target < 0) return false;
    visited[i][j] = true;
    target -= pascal[i][j];
    path.push_back({i, j});
    if (target == 0) {
        return true;
    }
    if (solved(i + 1, j, target)) {
        return true;
    }
    if (solved(i + 1, j + 1, target)) {
        return true;
    }
    if (solved(i, j + 1, target)) {
        return true;
    }
    if (solved(i, j - 1, target)) {
        return true;
    }
    if (solved(i - 1, j - 1, target)) {
        return true;
    }
    if (solved(i - 1, j, target)) {
        return true;
    }
    if (solved(i - 1, j + 1, target)) {
        return true;
    }
    path.pop_back();
    visited[i][j] = false;
    return false;
}

void solve() {
    int n;
    cin >> n;
    if (solved(1, 1, n)) {
        // print answer
        for (auto i : path) {
            cout << i.first << " " << i.second << '\n';
        }
    } else {
        cout << "-1\n";
    }
}

int32_t main() {
    int t;
    cin >> t;
    createPascal();
    for (int test = 1; test <= t; test++) {
        visited.assign(500, vector<bool>(500, false));
        cout << "Case #" << test << ": \n";
        solve();
    }
}