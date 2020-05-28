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
    int m = n - 1;
    int c = k / m;
    int num = c * n;
    num += k % m - 1;
    while (num - num / n < k)
        num++;

    cout << num << endl;
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        solve();
    }
}