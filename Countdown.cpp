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
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == k) {
            while (i + 1 < n && a[i + 1] == a[i] - 1) {
                if (a[i + 1] == 1) {
                    ans++;
                    break;
                }
                i++;
            }
        }
    }
    cout << ans << '\n';
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