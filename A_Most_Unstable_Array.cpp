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
    int n, m;
    cin >> n >> m;
    cout << min((int)2, n - 1) * m << '\n';
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        solve();
    }
}