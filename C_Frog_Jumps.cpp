#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> temp;
        temp.push_back(0);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R')
                temp.push_back(i + 1);
        }
        temp.push_back(s.length() + 1);
        int ans = 0;
        for (int i = 1; i < temp.size(); i++) {
            ans = max(ans, temp[i] - temp[i - 1]);
        }
        cout << ans << endl;
    }
}
