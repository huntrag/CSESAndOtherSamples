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
    int n, x;
    cin >> n >> x;
    int weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    sort(weight, weight + n);
    int st = 0, end = n - 1, count = 0;
    while (st <= end)
    {
        if (st == end)
        {
            count++;
            break;
        }
        while (st < end && weight[st] + weight[end] > x)
        {
            end--;
            count++;
        }
        if (st < end)
        {
            st++;
            end--;
            count++;
        }
    }
    cout << count;
    return 0;
}