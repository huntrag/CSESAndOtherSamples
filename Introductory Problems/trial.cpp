#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> sol;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int x1 = 0, x2 = 1, x3 = n - 1;
    while (x3 - x1 > 1)
    {
        while (x3 > x2)
        {
            int sum = nums[x1] + nums[x2] + nums[x3];
            // cout << sum << "\n";
            if (sum == 0)
            {
                vector<int> a{nums[x1], nums[x2], nums[x3]};
                sort(a.begin(), a.end());
                sol.insert(a);
                x3--;
                x2++;
            }
            else if (sum > 0)
            {
                x3--;
            }
            else
            {
                x2++;
            }
        }
        x1++;
        x2 = x1 + 1;
    }
    vector<vector<int>> ans;
    for (auto &r : sol)
    {
        ans.push_back(r);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<bool> vis(4, 0);
    for (auto r : vis)
    {
        cout << r << "\n";
    }
    return 0;
}