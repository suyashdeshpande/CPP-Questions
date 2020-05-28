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
    int ans = 0;
    for (int i = 1; i <= n / 2; ++i) {
        ans += i * 1ll * i;
    }
    cout << ans * 8 << endl;
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        solve();
    }
}