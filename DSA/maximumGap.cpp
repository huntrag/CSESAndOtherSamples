#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000001
#define fi first
#define se second
#define BUCK 1000

void pigeon(vi &a)
{
    if (a.size() <= 1)
    {
        return;
    }
    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    vector<int> counts(mx - mn + 1);

    for (int i = 0; i < a.size(); i++)
    {
        counts[a[i] - mn]++;
    }
    int cnt = 0;
    for (int i = 0; i < counts.size(); i++)
    {
        while (counts[i] > 0)
        {
            a[cnt] = i + mn;
            cnt++;
            // cout << a[cnt] << " ";
            counts[i]--;
        }
    }
}

int maximumGap(vi &a)
{
    int tot = MOD / BUCK;
    int n = a.size();
    vvi buckets(tot);

    for (int i = 0; i < n; i++)
    {
        buckets[a[i] / BUCK].push_back(a[i]);
        // cout << a[i] << " ";
    }
    for (int i = 0; i < tot; i++)
    {
        pigeon(buckets[i]);
    }
    int mx, sum = 0;
    int cnt = 0;

    while (cnt < tot && buckets[cnt].size() == 0)
    {
        cnt++;
    }
    if (cnt == tot)
    {
        return sum;
    }
    // first iteration
    cout << buckets[cnt][0] << " ";
    for (int i = 0; i < buckets[cnt].size() - 1; i++)
    {
        cout << buckets[cnt][i + 1] << " ";
        sum = max(sum, buckets[cnt][i + 1] - buckets[cnt][i]);
    }
    cout << " - " << sum;
    cout << "\n";
    mx = buckets[cnt][buckets[cnt].size() - 1];
    for (int i = cnt + 1; i < tot; i++)
    {
        if (buckets[i].size() == 0)
        {
            continue;
        }
        sum = max(sum, buckets[i][0] - mx);
        mx = buckets[i][buckets[i].size() - 1];
        cout << buckets[i][0] << " ";
        for (int j = 0; j < buckets[i].size() - 1; j++)
        {
            cout << buckets[i][j + 1] << " ";
            sum = max(sum, buckets[i][j + 1] - buckets[i][j]);
        }
        cout << " - " << sum;
        cout << "\n";
    }

    return sum;
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
        int x;
        vi a;
        while (cin >> x)
        {
            a.push_back(x);
        }
        cout << maximumGap(a);
    }
    return 0;
}