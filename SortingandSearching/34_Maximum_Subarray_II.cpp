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
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    vector<ll> prefix(n);
    prefix[0] = num[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = (ll)prefix[i - 1] + num[i];
    }
    multiset<ll> s;
    for (int i = a - 1; i < b; i++)
    {
        s.insert(prefix[i]);
    }
    ll mx = *s.rbegin();
    for (int i = b; i < n; i++)
    {
        s.erase(s.find(prefix[i - b + a - 1]));
        s.insert(prefix[i]);
        mx = (ll)max(mx, (ll) * (s.rbegin()) - prefix[i - b]);
    }
    for (int i = n - b; i < n - a; i++)
    {
        s.erase(s.find(prefix[i + a - 1]));
        mx = (ll)max(mx, (ll) * (s.rbegin()) - prefix[i]);
    }
    cout << mx;
    return 0;
}