#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isOdd(int x) {
    return abs(x) & 1;
}

void solve() {
    int x, y;
    cin >> x >> y;
    if ((isOdd(x) && isOdd(y)) || (!isOdd(x) && !isOdd(y))) {
        cout << "IMPOSSIBLE";
        return;
    }
}

int32_t main() {
    int t;
    cin >> t;
    int test = 1;
    while (t--) {
        cout << "Case #" << test << ": ";
        solve();
        cout << '\n';
        test++;
    }
}