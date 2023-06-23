#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

vector<vector<int>> dp;

map<int, vector<vector<string>>> m;

vector<vector<string>> solve(string s, int ind)
{
    vector<vector<string>> ans;
    if (ind >= s.size())
    {
        return ans;
    }
    if (m.find(ind) != m.end())
    {
        return m[ind];
    }
    for (int i = 0; i < dp[ind].size(); i++)
    {
        string r = s.substr(ind, dp[ind][i]);
        if (dp[ind][i] + ind == s.length())
        {
            vector<string> temp;
            temp.push_back(r);
            ans.push_back(temp);
            continue;
        }
        vector<vector<string>> add = solve(s, ind + dp[ind][i]);

        for (int j = 0; j < add.size(); j++)
        {
            add[j].push_back(r);
            ans.push_back(add[j]);
        }
    }

    m[ind] = ans;
    return ans;
}

vector<vector<string>> partition(string s)
{
    int n = s.length();
    dp.resize(n);
    // odd palindromes
    for (int i = 0; i < n; i++)
    {
        // i is the middle eleme

        for (int dis = 0; (i - dis) >= 0 && (i + dis) < n; dis++)
        {
            if (s[i - dis] == s[i + dis])
            {
                dp[i - dis].push_back(2 * dis + 1);
            }
            else
            {
                break;
            }
        }
    }
    // for even palin
    for (int i = 0; i < n - 1; i++)
    {
        // i and i+1 middle elem
        for (int diff = 0; (i - diff) >= 0 && (i + diff + 1) < n; diff++)
        {
            if (s[i - diff] == s[i + diff + 1])
            {
                dp[i - diff].push_back(2 * diff + 2);
            }
            else
            {
                break;
            }
        }
    }

    vector<vector<string>> ans = solve(s, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        reverse(ans[i].begin(), ans[i].end());
    }

    return ans;
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
    // cin>>test;
    while (test--)
    {
        string s;
        getline(cin >> ws, s);

        vector<vector<string>> ans = partition(s);

        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << ", ";
            }
            cout << "\n";
        }
    }
    return 0;
}