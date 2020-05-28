#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int ans = 0;
    for (int i = 1; i <= n - 2; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans++;
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 0;
    cin >> t;
    int test = 1;
    while (t--) {
        cout << "Case #" << test << ": ";
        solve();
        test++;
    }
    return 0;
}