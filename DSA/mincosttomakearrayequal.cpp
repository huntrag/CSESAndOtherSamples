#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll;
#define MOD 1000000007
#define fi first
#define se second

ll getCost(vi &a, vi &cost, int base)
{
    ll result = 0;
    for (int i = 0; i < a.size(); ++i)
        result += 1L * abs(a[i] - base) * cost[i];
    return result;
}

ll minCost1(vi &a, vi &cost)
{
    // Initialize the left and the right boundary of the binary search.
    ll ans = getCost(a, cost, a[0]);
    int left = *min_element(a.begin(), a.end());
    int right = *max_element(a.begin(), a.end());

    // As shown in the previous picture, if F(mid) > F(mid + 1), then the minimum
    // is to the right of mid, otherwise, the minimum is to the left of mid.
    while (left < right)
    {
        int mid = (left + right) / 2;
        ll cost1 = getCost(a, cost, mid);
        ll cost2 = getCost(a, cost, mid + 1);
        ans = min(cost1, cost2);
        if (cost1 > cost2)
            left = mid + 1;
        else
            right = mid;
    }
    return ans;
}

ll minCost(vi &a, vi &cost)
{
    // using prefix sums
    int n = a.size();
    vpll arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = make_pair((ll)a[i], (ll)cost[i]);
    }

    sort(arr.begin(), arr.end());
    vll prefix(n), suffix(n);
    prefix[0] = 0;
    suffix[n - 1] = 0;
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i - 1].se;
        suffix[n - 1 - i] = suffix[n - i] + arr[n - i].se;
    }

    //  for first element
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += (ll)(arr[i].fi - arr[0].fi) * arr[i].se;
    }
    ll mx = ans;
    cout << 0 << " " << ans << "\n";
    for (int i = 1; i < n; i++)
    {
        ll diff = arr[i].fi - arr[i - 1].fi;
        ans = ans - suffix[i - 1] * diff + prefix[i] * diff;
        cout << i << " " << ans << "\n";
        mx = min(mx, ans);
    }
    return mx;
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
        int n;
        cin >> n;
        vi a(n), cost(n);

        for (auto &r : a)
        {
            cin >> r;
        }
        for (auto &r : cost)
        {
            cin >> r;
        }

        cout << minCost(a, cost);
    }
    return 0;
}