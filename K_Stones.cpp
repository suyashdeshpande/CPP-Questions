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
    cin >> n >> k;
    vi a(n);
    for (int &i : a) cin >> i;
    vector<bool> dp(k + 1);
    for (int stones = 0; stones <= k; stones++) {
        for (int x : a) {
            if (stones - x >= 0 && !dp[stones - x]) {
                dp[stones] = true;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second") << '\n';
}

int32_t main() {
    FAST;
    solve();
}