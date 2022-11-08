#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.se < b.se)
    {
        return true;
    }
    else if (a.se == b.se)
    {
        return a.fi < b.fi;
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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> time(n);
    for (int i = 0; i < n; i++)
    {
        cin >> time[i].fi >> time[i].se;
    }
    sort(time.begin(), time.end(), comp);
    multimap<ll, ll> m;
    stack<ll> reserve;
    for (int i = k; i >= 1; i--)
    {
        reserve.push(i);
    }
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        if (!m.empty())
        {
            auto it = m.lower_bound(time[i].fi);
            if (it->first == time[i].fi || it != m.begin())
            {
                if (it->first != time[i].fi)
                    it--;
                if (it->first <= time[i].fi)
                {
                    reserve.push(it->second);
                    m.erase(it);
                }
            }
        }
        if (!reserve.empty())
        {
            // cout << time[i].fi << " " << time[i].se << " " << reserve.top() << "\n";
            m.insert(pair<ll, ll>(time[i].se, reserve.top()));
            reserve.pop();
            total++;
        }
    }
    cout << total;
    return 0;
}