#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
   public:
    static int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size();
        vector<vector<int>> pre(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    pre[i][j] = 0;
                    sum = 0;
                    continue;
                }
                sum += 1;
                pre[i][j] = sum;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int maxSide = 0;
                if (pre[i][j] >= 1) maxSide = 1;
                int minEl = INT_MAX;
                for (int side = 1; side <= pre[i][j]; side++) {
                    if (i - side < 0) break;
                    if (pre[i - side][j] < side + 1) {
                        break;
                    }
                    if (i - side + 1 >= 0 && pre[i - side][j] > pre[i - side + 1][j])
                        break;

                    if (minEl < side)
                        break;

                    maxSide = side + 1;
                    minEl = min(minEl, maxSide);
                }
                ans = max(ans, maxSide * maxSide);
            }
        }
        return ans;
    }
};

int main() {
    int n = 5;
    int m = 4;
    vector<vector<char>> mat(n, vector<char>(m));
    m = {
        {"!"}
    }
    cout << Solution::maximalSquare(mat) << endl;
}
