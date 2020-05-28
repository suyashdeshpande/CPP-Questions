#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

#define int long long

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    int minEl = d;
    a[n - 1] = (d / a[n - 1]) * a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        a[i] = (a[i + 1] / a[i]) * a[i];
    }
    cout << a[0] << "\n";
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