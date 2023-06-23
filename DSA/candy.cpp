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

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> left(n), right(n);

    left[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
        else
        {
            left[i] = 1;
        }
    }

    right[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
        else
        {
            right[i] = 1;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count = count + max(left[i], right[i]);
    }

    return count;
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
    // cin >> test;
    while (test--)
    {

        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << candy(a);
    }
    return 0;
}