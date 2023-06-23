#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

void rearrange(long long *arr, int n)
{
    int mx = arr[n - 1] + 1;
    int max_ind = n - 1, min_ind = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            // max
            arr[i] = (arr[i] + (arr[max_ind] % mx) * mx);
            max_ind--;
        }
        else
        {
            arr[i] = (arr[i] + (arr[min_ind] % mx) * mx);
            min_ind++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] / mx;
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

    int n;
    cin >> n;
    ll arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    rearrange(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}