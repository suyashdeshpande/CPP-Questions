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
    vi a(n + 3, -1);
    for (i = 1; i <= n; i++) cin >> a[i];
    int flag = 0, flag2 = 0;
    if (n == 1 && a[1] == k) {
        cout << "yes\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == k) flag2 = 1;
        if (a[i] >= k) {
            if (a[i + 1] >= k || a[i + 2] >= k) {
                flag = 1;
            }
        }
    }
    if (flag && flag2)
        cout << "yes\n";
    else
        cout << "no\n";
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        solve();
    }
}