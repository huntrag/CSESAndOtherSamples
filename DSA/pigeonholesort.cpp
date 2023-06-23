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

void pigeonhole(vector<int> &a)
{
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
            counts[i]--;
        }
    }
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
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        pigeonhole(a);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}