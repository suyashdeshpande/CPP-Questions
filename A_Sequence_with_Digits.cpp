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

pair<int, int> digit(int x) {
    int maxDigit = 0, minDigit = 9;
    while (x) {
        maxDigit = max(maxDigit, x % 10);
        minDigit = min(minDigit, x % 10);
        x /= 10;
    }
    return {maxDigit, minDigit};
}

int32_t main() {
    FAST;
    cin >> t;
    unordered_map<int, pair<int, int>> m;
    while (t--) {
        int a, k;
        cin >> a >> k;
        int tempAns = a;
        for (int i = 1; i < k; i++) {
            pair<int, int> q;
            if (m.find(tempAns) == m.end()) {
                m[tempAns] = digit(tempAns);
            }
            q = m[tempAns];
            int tt = tempAns + q.first * q.second;
            if (tempAns == tt) break;
            tempAns = tt;
        }
        cout << tempAns << '\n';
    }
}