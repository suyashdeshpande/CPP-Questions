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
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int aSum = accumulate(a.begin(), a.end(), 0);
    int ans = aSum;
    for (int i = 0; i < k; i++) {
        aSum = aSum - a[i] + b[n - 1 - i];
        ans = max(aSum, ans);
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