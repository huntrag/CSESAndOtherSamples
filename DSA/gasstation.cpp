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

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int sum_diff = 0;

    vector<int> diff(n);

    for (int i = 0; i < n; i++)
    {
        diff[i] = gas[i] - cost[i];
        sum_diff += diff[i];
    }

    if (sum_diff < 0)
    {
        return -1;
    }
    int start = 0, end = 0;
    int cur = 0;

    while (start - end <= n)
    {
        if (cur < 0)
        {
            cur = cur - diff[(end % n)];
            end++;
        }
        else
        {
            cur = cur + diff[(start % n)];
            start++;
        }
    }

    return end;
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
        int n;
        cin >> n;
        vi gas(n), cost(n);

        for (int i = 0; i < n; i++)
        {
            cin >> gas[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> cost[i];
        }

        cout << canCompleteCircuit(gas, cost);
    }
    return 0;
}