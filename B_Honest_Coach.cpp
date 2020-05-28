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
    vi a(n);
    for (int &i : a) cin >> i;
    int ans = INT_MAX;
    sort(a.begin(), a.end());
    for (i = 1; i < n; i++) {
        ans = min(ans, abs(a[i] - a[i - 1]));
    }
    cout << ans << '\n';
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        solve();
    }
}