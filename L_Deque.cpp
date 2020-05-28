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
const int N = 3005;
int dp[N][N];

void solve() {
    cin >> n;
    vi a(n);
    for (int &i : a) cin >> i;
    for (i = n - 1; i >= 0; i--) {
        for (j = i; j < n; j++) {
            if (i == j)
                dp[i][j] = a[i];
            else
                dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    cout << dp[0][n - 1] << '\n';
}

int32_t main() {
    FAST;
    solve();
}