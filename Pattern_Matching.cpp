#include <bits/stdc++.h>

using namespace std;

void findString(unordered_set<string> st, string& ans) {
    if (!st.size())
        return;
    string start = "";
    string end = "";
    unordered_set<string> ns;
    for (auto it = st.begin(); it != st.end(); it++) {
        string temp = *it;
        int j = 0;
        int l = temp.find_first_of('*', 0);
        string s = temp.substr(0, l);
        for (; j < start.length() && j < s.length(); j++)
            if (start[j] != s[j])
                break;

        if (j < start.length() && j < s.length()) {
            ans = "*";
            return;
        }
        temp = temp.substr(l, temp.length() - l);
        start += s.substr(j, s.length() - j);
        l = temp.find_last_of('*');
        if (l != temp.length()) {
            s = temp.substr(l + 1, temp.length() - l - 1);
            j = s.length() - 1;
            int k = end.length() - 1;
            for (; j >= 0 && k >= 0; j--, k--)
                if (end[k] != s[j])
                    break;
            if (j >= 0 && k >= 0) {
                ans = "*";
                return;
            }
            end = s.substr(0, j + 1) + end;
            temp = temp.substr(0, l + 1);
        }
        ns.insert(temp);
    }
    string mid = "";
    for (auto it = ns.begin(); it != ns.end(); it++) {
        string temp = *it;
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] != '*')
                mid.push_back(temp[i]);
        }
    }
    ans = start + mid + end;
    return;
}

int main() {
    int t;
    cin >> t;
    for (int l = 1; l <= t; l++) {
        int n;
        cin >> n;
        // vector<string> p(n);
        unordered_set<string> st;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            st.insert(temp);
        }
        string ans = "", start = "", end = "";
        findString(st, ans);
        cout << "Case #" << l << ": " << ans << "\n";
    }
}