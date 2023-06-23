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
    int a[n], ind[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ind[a[i]] = i + 1;
    }
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (ind[i] > ind[i + 1])
        {
            count++;
        }
    }
    cout << count;
    return 0;
}