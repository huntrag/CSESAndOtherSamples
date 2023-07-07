//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string longestPalin(string s)
    {
        // code here
        string rev;
        rev.append(s);
        reverse(rev.begin(), rev.end());
        int n = s.length();
        int dp[n + 1][n + 1];
        pair<int, int> p;
        int mx = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (s[i - 1] == rev[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i + j - dp[i][j] == n)
                {
                    if (mx < dp[i][j])
                    {
                        mx = dp[i][j];
                        p = make_pair(i, j);
                    }
                }
            }
        }

        string ans;
        while (p.first >= 0 && p.second > 0 && dp[p.first][p.second] > 0)
        {
            ans.push_back(s[p.first - 1]);
            p.first--;
            p.second--;
        }
        // Printing

        // cout << setw(2) << "*"
        //      << " ";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << setw(2) << rev[i] << " ";
        // }
        // cout << "\n";
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << setw(2) << s[i - 1] << " ";
        //     for (int j = 1; j <= n; j++)
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
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalin(S) << endl;
    }
}
