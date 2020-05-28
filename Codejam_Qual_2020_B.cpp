#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    string ans = "";
    int currOpenings = 0;
    for (int i = 0; i < n; i++)
    {

        while (currOpenings < (s[i] - '0'))
        {
            ans += "(";
            currOpenings++;
        }
        while (currOpenings > (s[i] - '0'))
        {
            ans += ")";
            currOpenings--;
        }
        if (currOpenings == (s[i] - '0'))
        {
            ans += s[i];
            continue;
        }
    }

    while(currOpenings) {
        ans += ")";
        currOpenings--;
    }
    
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        cout << "Case #" << test << ": ";
        solve();
    }
}