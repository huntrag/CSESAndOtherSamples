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

int findPeakElement(vi &a)
{
    int n = a.size();
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return (a[0] < a[1] ? 1 : 0);
    }
    else
    {
        int low = 0;
        int high = n - 1;

        while (high - low >= 1)
        {
            if (high - low == 1)
            {
                if (high == n - 1 && a[high] > a[high - 1])
                {
                    return high;
                }
                else if (low == 0 && a[low] > a[low + 1])
                {
                    return low;
                }
                else if (a[low] > a[low - 1] && a[low] > a[low + 1])
                {
                    return low;
                }
                else
                {
                    return high;
                }
            }
            int mid = (low + high) / 2;
            if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
            {
                return mid;
            }
            else if (a[mid] > a[mid - 1] && a[mid] < a[mid + 1])
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
            // cout << mid + 1 << "\n";
        }

        return -1;
    }
    return -1;
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
        cout << findPeakElement(a);
    }
    return 0;
}