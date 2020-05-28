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
    int p = 1;
    vi ans;
    while (n) {
        int temp = n % 10;
        n /= 10;
        if (temp) ans.push_back(temp * p);
        p *= 10;
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << '\n';
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        solve();
    }
}