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

vi majorityElement(vi &a)
{
    int count1 = 0, cand1 = 0, count2 = 0, cand2 = 1;
    int n = a.size();
    for (auto &x : a)
    {
        if (cand1 == x)
        {
            count1++;
        }
        else if (cand2 == x)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            cand1 = x;
            count1++;
        }
        else if (count2 == 0)
        {
            cand2 = x;
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    int count = float(n / 3);
    vi ans;
    count1 = 0;
    for (auto &x : a)
    {
        if (x == cand1)
        {
            count1++;
        }
    }

    if (count1 > count)
    {
        ans.push_back(cand1);
    }

    count1 = 0;
    for (auto &x : a)
    {
        if (x == cand2)
        {
            count1++;
        }
    }

    if (count1 > count)
    {
        ans.push_back(cand2);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    while (test--)
    {
        int x;
        vi a;
        while (cin >> x)
        {
            a.push_back(x);
        }

        vi ans = majorityElement(a);

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}