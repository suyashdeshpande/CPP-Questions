#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9;
string ans;
string s, curStr;
int pos;

string helper(int& pos) {
    int num = 0;
    string word = "";
    for (; pos < s.size(); pos++) {
        char cur = s[pos];
        if (cur == '(') {
            curStr = helper(++pos);
            for (; num > 0; num--) word += curStr;
        } else if (cur >= '0' && cur <= '9') {
            num = num * 10 + cur - '0';
        } else if (cur == ')') {
            return word;
        } else {
            word += cur;
        }
    }
    return word;
}

void solve() {
    cin >> s;
    int x = 1, y = 1;
    int n = s.length();

    int pos = 0;
    ans = helper(pos);
    int right = 0, down = 0;
    for (char i : ans) {
        if (i == 'N')
            down--;
        else if (i == 'S')
            down++;
        else if (i == 'E')
            right++;
        else
            right--;
    }
    down = (down + MOD) % MOD;
    right = (right + MOD) % MOD;
    cout << right + 1 << " " << down + 1 << "\n";
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