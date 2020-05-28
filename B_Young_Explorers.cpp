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
    for (int& e : a) cin >> e;
    sort(begin(a), end(a));
    int res = 0;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= i + 1 - l) {
            ++res;
            l = i + 1;
        }
    }
    cout << res << '\n';
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        solve();
    }
}