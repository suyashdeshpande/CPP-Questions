#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int s;
    int e;
    int ind;
};

bool compare(Interval &a, Interval &b) {
    return a.s < b.s;
}

void solve() {
    int n;
    cin >> n;
    vector<Interval> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].s >> v[i].e;
        v[i].ind = i;
    }

    string ans = "";
    for (int i = 0; i < n; i++)
        ans += "C";

    sort(v.begin(), v.end(), compare);

    int cEnd = 0, jEnd = 0;
    cEnd = v[0].e;
    ans[0] = 'C';

    for (int i = 1; i < n; i++) {
        if (v[i].s >= cEnd) {
            ans[v[i].ind] = 'C';
            cEnd = max(v[i].e, cEnd);
            continue;
        }
        if (v[i].s >= jEnd) {
            ans[v[i].ind] = 'J';
            jEnd = max(v[i].e, jEnd);
            continue;
        } else {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        cout << "Case #" << test << ": ";
        solve();
    }
}