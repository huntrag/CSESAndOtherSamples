//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string lookandsay(int n)
    {
        // code here
        vector<vector<int>> a(n + 1);
        a[1].push_back(1);
        for (int i = 2; i <= n; i++)
        {
            int freq = 1;
            int prev = a[i - 1][0];
            a[i - 1].push_back(0);
            for (int j = 1; j < a[i - 1].size(); j++)
            {
                if (prev == a[i - 1][j])
                {
                    freq++;
                }
                else
                {
                    a[i].push_back(freq);
                    a[i].push_back(prev);
                    prev = a[i - 1][j];
                    freq = 1;
                }
            }
        }
        string s;
        for (int i = 0; i < a[n].size(); i++)
        {
            // cout << a[n][i];
            s.push_back(a[n][i] + '0');
        }

        return s;
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
        int n;
        cin >> n;
        Solution obj;
        cout << obj.lookandsay(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
