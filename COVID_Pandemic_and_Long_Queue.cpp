#include <bits/stdc++.h>
using namespace std;

#define ll long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> temp;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                temp.push_back(i);
        }
        bool good = true;
        for (int i = 1; i < temp.size(); i++)
        {
            if (temp[i] - temp[i - 1] < 6)
            {
                good = false;
                break;
            }
        }
        if (good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}