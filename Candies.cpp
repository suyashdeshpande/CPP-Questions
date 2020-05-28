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
    int q;
    cin >> n >> q;
    vi a(n);
    for (int &i : a) cin >> i;
    int ans = 0;
    while (q--) {
        char type;
        cin >> type;
        if (type == 'Q') {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int tempAns = 0;
            for (i = l; i <= r; i++) {
                int x = pow(-1, i - l) * (i - l + 1) * a[i];
                tempAns += x;
            }
            ans += tempAns;
        } else {
            int x, v;
            cin >> x >> v;
            x--;
            a[x] = v;
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