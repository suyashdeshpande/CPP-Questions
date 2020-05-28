#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];

    int trace = 0;
    for (int i = 0; i < n; i++)
        trace += m[i][i];
    int row = 0, col = 0;
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.clear();
        for (int j = 0; j < n; j++)
        {
            s.insert(m[i][j]);
        }
        if (s.size() != n)
            row++;
    }

    for (int j = 0; j < n; j++)
    {
        s.clear();
        for (int i = 0; i < n; i++)
        {
            s.insert(m[i][j]);
        }
        if (s.size() != n)
            col++;
    }
    cout << trace << " " << row << " " << col << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    int test = 1;
    while (t--)
    {
        cout << "Case #" << test << ": ";
        solve();
        test++;
    }
    return 0;
}