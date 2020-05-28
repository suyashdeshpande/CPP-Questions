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
    if (n % 2 == 1 && k % 2 == 0) {
        cout << "NO" << endl;
        return;
    }

    if (n % 2 == 1 && k % 2 == 1) {
        if (k > n) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++) {
            cout << "1 ";
        }
        cout << n - k + 1 << endl;
        return;
    }

    if (n % 2 == 0) {
        if (k % 2 == 0) {
            if (k > n) {
                cout << "NO" << endl;
                return;
            }
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; i++) {
                cout << "1 ";
            }
            cout << n - k + 1 << endl;
        } else {
            if (k * 2 > n) {
                cout << "NO" << endl;
                return;
            }
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; i++) {
                cout << "2 ";
            }
            cout << n - 2 * (k - 1) << endl;
        }
    }
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        solve();
    }
}