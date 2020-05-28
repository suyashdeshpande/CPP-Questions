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
    vi models(n + 1), ans(n + 1);
    for (int i = 1; i <= n; i++) cin >> models[i];

    for (int i = n; i >= 1; i--) {
        ans[i] = 1;
        for (int j = 2 * i; j <= n; j += i) {
            if (models[i] < models[j] && ans[i] < ans[j] + 1)
                ans[i] = 1 + ans[j];
        }
    }
    for (int i = 1; i < n; i++) ans[n] = max(ans[i], ans[n]);
    cout << ans[n] << '\n';
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        solve();
    }
}