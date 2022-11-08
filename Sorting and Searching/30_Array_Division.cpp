#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second

int partition(vector<ll> a, ll thresh)
{
    int n = a.size();
    ll sum = 0;
    int part = 0;
    for (int i = 0; i < n; i++)
    {
        if ((ll)sum + a[i] > thresh)
        {
            part++;
            sum = a[i];
        }
        else
        {
            sum += (ll)a[i];
        }
    }
    return part + 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll high = 0;
    ll low = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        high += (ll)a[i];
        low = max(low, a[i]);
    }
    ll mid = (ll)low + (high - low) / 2;
    while (low + 1 < high)
    {
        mid = (ll)low + (high - low) / 2;
        if (partition(a, mid) > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    if (partition(a, high - 1) <= k)
    {
        cout << high - 1;
        return 0;
    }
    cout << high;
    return 0;
}