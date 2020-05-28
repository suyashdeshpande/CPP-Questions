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
    int a, b;
    cin >> a >> b;
    if (max(a, b) < 2 * min(a, b))
        cout << 4 * min(a, b) * min(a, b) << endl;
    else
        cout << max(a, b) * max(a, b) << endl;
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        solve();
    }
}