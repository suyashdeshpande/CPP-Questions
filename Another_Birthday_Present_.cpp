#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a) cin >> i;
        vector<int> temp(a.begin(), a.end());
        sort(temp.begin(), temp.end());
        // n-k to k-1

        unordered_map<int, int> s;
        bool flag = true;
        for (int i = 0; i < k; i++) {
            s.clear();
            for (int j = i; j < n; j = j + k) {
                s[temp[i]]++;
            }
            for (int j = i; j < n; j = j + k) {
                if (s.find(a[i]) == s.end()) {
                    flag = false;
                    cout << "no\n";
                    break;
                } else {
                    s[temp[i]]--;
                    if (s[temp[i]] == 0) s.erase(temp[i]);
                }
            }
        }

        if (flag && k > n / 2) {
            // n-k to k-1
            bool qwe = true;
            for (int i = n - k; i <= k - 1; i++) {
                if (a[i] != temp[i]) {
                    qwe = false;
                    break;
                }
            }
            if (qwe) {
                cout << "yes\n";
            } else
                cout << "no\n";
        }

        if (k <= n / 2 && flag) cout << "yes\n";
    }
}