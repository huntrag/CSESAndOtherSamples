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

map<int, vector<vector<int>>> dp;

vector<vector<int>> solve(vector<int> &cand, int target, int ind)
{
    if (dp.find(target) != dp.end())
    {
        return dp[target];
    }
    vector<vector<int>> ans;

    for (int i = ind; i < cand.size(); i++)
    {
        if (cand[i] == target)
        {
            vector<int> temp;
            temp.push_back(cand[i]);
            ans.push_back(temp);
        }
        else if (cand[i] > target)
        {
            continue;
        }
        else
        {
            vector<vector<int>> prev = solve(cand, target - cand[i], 0);
            for (int j = 0; j < prev.size(); j++)
            {
                if (prev[j].back() >= cand[i])
                {
                    prev[j].push_back(cand[i]);
                    ans.push_back(prev[j]);
                }
            }
        }
    }
    dp[target] = ans;
    return ans;
}

vector<vector<int>> combinationSum(vector<int> &cand, int target)
{
    sort(cand.begin(), cand.end());
    return solve(cand, target, 0);
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
        int n, target;
        cin >> n >> target;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vvi ans = combinationSum(a, target);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}