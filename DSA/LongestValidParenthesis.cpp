// DP + Stack
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

int longestValidParentheses(string s)
{
    string r = " ";
    r = r.append(s);
    vector<int> dp(r.length());
    int n = r.length();
    stack<int> stk;
    int x;
    int mx = 0;
    for (int i = 1; i < n; i++)
    {
        if (r[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            if (!stk.empty())
            {
                x = stk.top();
                dp[i] = dp[x - 1] + (i - x + 1);
                stk.pop();
            }
        }
        mx = max(mx, dp[i]);
    }

    return mx;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        string s;
        getline(cin >> ws, s);
        cout << longestValidParentheses(s);
    }
    return 0;
}