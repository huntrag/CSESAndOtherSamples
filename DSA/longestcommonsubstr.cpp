//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string longestPalin(string s, string r)
    {
        // code here
        int n = s.length();
        int m = r.length();
        int dp[n + 1][m + 1];
        int mx = 0;
        pair<int, int> p;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (s[i - 1] == r[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (mx < dp[i][j])
                    {
                        mx = dp[i][j];
                        p = make_pair(i, j);
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        string ans;
        while (dp[p.first][p.second] > 0)
        {
            ans.push_back(r[p.second - 1]);
            p.first--;
            p.second--;
        }

        reverse(ans.begin(), ans.end());

        // Printing

        // cout << setw(2) << "*"
        //      << " ";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << setw(2) << r[i] << " ";
        // }
        // cout << "\n";
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << setw(2) << s[i - 1] << " ";
        //     for (int j = 1; j <= m; j++)
        //     {
        //         cout << setw(2) << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, r;
    getline(cin >> ws, s);
    getline(cin >> ws, r);

    Solution ob;
    cout << ob.longestPalin(s, r) << endl;
}
// Contributed By: Pranay Bansal

// } Driver Code Ends