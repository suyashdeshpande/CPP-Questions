#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int q;
    cin >> q;
    int minBarAmount = INT_MIN;
    unordered_map<int, bool> m = {};
    int ans = 0;
    while (q--) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int idx, amount;
            cin >> idx >> amount;
            a[idx] = amount;
            m[idx] = true;
        } else if (queryType == 2) {
            int x;
            cin >> x;
            minBarAmount = max(x, minBarAmount);
            for (auto i : m) {
                if (a[i.first] < x) {
                    m.erase(i.first);
                }
            }
        } else {
            int l, r, amt;
            cin >> l >> r >> amt;
            for (int i = min(l, r); i <= max(l, r); i++) {
                if (m.find(i) != m.end()) {
                    if (a[i] < amt) {
                        ans++;
                    }
                } else if (max(a[i], minBarAmount) < amt) {
                    ans++;
                }
            }
            cout << ans;
        }
    }
    return 0;
}
