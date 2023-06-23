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
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int mx = 0;
    set<int> s;
    int i = 0, j = 0;

    while (i < n && j < n)
    {
        while ((j < n) && (!s.count(num[j])))
        {
            s.insert(num[j]);
            mx = max(mx, (int)s.size());
            j++;
        }
        while ((i < n) && (s.count(num[j])))
        {
            s.erase(num[i]);
            i++;
        }
    }
    cout << mx;
    return 0;
}