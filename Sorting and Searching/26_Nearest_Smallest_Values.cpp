#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second

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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<int> s;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[i] <= a[s.top()])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = 0;
        }
        else
        {
            ans[i] = s.top() + 1;
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}