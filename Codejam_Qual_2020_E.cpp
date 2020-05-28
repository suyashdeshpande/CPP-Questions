#include <bits/stdc++.h>
using namespace std;

int a[50][50];

bool check(int i, int j, int num) {
    for (int q = 0; q < i; q++) {
        if (a[q][j] == num)
            return false;
    }
    for (int q = 0; q < j; q++) {
        if (a[i][q] == num)
            return false;
    }
    return true;
}

bool solved(int n, int k, int i, int j) {
    if (i == n) {
        if (k == 0)
            return true;
        return false;
    }
    if (j == n) {
        return solved(n, k, i + 1, 0);
    }
    for (int num = 1; num <= n; num++) {
        if (!check(i, j, num))
            continue;
        a[i][j] = num;
        if (i == j && solved(n, k - num, i, j + 1) || solved(n, k, i, j + 1)) {
            return true;
        }
        return false;
    }
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (solved(n, k, 0, 0)) {
        cout << "POSSIBLE" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        cout << "Case #" << test << ": ";
        solve();
    }
}