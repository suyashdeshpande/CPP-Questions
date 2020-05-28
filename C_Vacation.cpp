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

void solve() {
    cin >> n;
    vvi p(n, vi(3));
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++)
            cin >> p[i][j];
    }
    vi ans(3);
    ans[0] = p[0][0], ans[1] = p[0][1], ans[2] = p[0][2];
    for (i = 1; i < n; i++) {
        int x = p[i][0] + max(ans[1], ans[2]);
        int y = p[i][1] + max(ans[0], ans[2]);
        int z = p[i][2] + max(ans[0], ans[1]);
        ans[0] = x, ans[1] = y, ans[2] = z;
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
}

int32_t main() {
    FAST;
    solve();
}