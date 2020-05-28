#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> p(n);
        for (int &i : p) cin >> i;
        int minDefender = INT_MAX, minForward = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                minDefender = min(minDefender, p[i]);
            } else {
                minForward = min(minForward, p[i]);
            }
        }
        if (s + minDefender + minForward <= 100)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}