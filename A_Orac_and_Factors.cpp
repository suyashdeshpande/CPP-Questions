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

int mi(int x) {
    for (int i = 2; i <= x; i++)
        if (x % i == 0) return i;
    return -1;
}

void solve() {
    cin >> n >> k;
    cout << n + mi(n) + k * 2 - 2 << endl;
}

int32_t main() {
    FAST;
    cin >> t;
    while (t--) {
        solve();
    }
}