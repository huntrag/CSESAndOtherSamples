#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second
#define mp(x, y) make_pair((int)x, (int)y)

struct arr
{
    int fi;
    int se;
    int ind;
};

bool comp1(arr a, arr b)
{
    if (a.fi < b.fi)
    {
        return true;
    }
    else if (a.fi == b.fi)
    {
        return a.se > b.se;
    }
    return false;
}

bool comp2(arr a, arr b)
{
    if (a.se < b.se)
    {
        return true;
    }
    else if (a.se == b.se)
    {
        return a.fi > b.fi;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<arr> a(n);
    vector<vector<int>> ans(2, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].fi = x;
        a[i].se = y;
        a[i].ind = i;
    }
    sort(a.begin(), a.end(), comp1);
    int mx = a[0].se;

    for (int i = 1; i < n; i++)
    {
        if (a[i].se > mx)
        {
            mx = a[i].se;
        }
        else
        {
            ans[1][a[i].ind] = 1;
        }
    }

    sort(a.begin(), a.end(), comp2);
    mx = a[0].fi;

    for (int i = 1; i < n; i++)
    {
        if (a[i].fi > mx)
        {
            mx = a[i].fi;
        }
        else
        {
            ans[0][a[i].ind] = 1;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}