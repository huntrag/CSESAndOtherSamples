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

int upperbound(vector<int> &a, int key)
{
    int x = (upper_bound(a.begin(), a.end(), key) - a.begin());
    return x;
}

int lowerbound(vector<int> &a, int key)
{
    int x = (lower_bound(a.begin(), a.end(), key) - a.begin());
    return x;
}

int median(vector<int> &a1, vector<int> &a2, int ind1, int n)
{
    // cout << a1[0] << "\n";
    int low, high, mid;
    low = 0;
    high = n - 1;
    int cur, prev = -1;
    int ans = -1;
    while (high - low >= 0)
    {
        if (high - low <= 1)
        {
            cur = low;
            cur = cur + upperbound(a2, a1[low]);
            // cout << low << " " << a1[low] << " " << cur << "\n";
            if (ind1 == cur)
            {
                ans = low;
                break;
            }

            cur = high;
            cur = cur + lowerbound(a2, a1[high]);

            if (ind1 == cur)
            {
                ans = high;
                break;
            }
            break;
        }

        mid = (low + high) / 2;
        cur = mid;
        if (prev > cur)
            cur = cur + upperbound(a2, a1[mid]);
        else
            cur = cur + lowerbound(a2, a1[mid]);
        if (ind1 == cur)
        {
            ans = mid;
            break;
        }

        if (prev != -1 && (ind1 > cur) && (ind1 < prev))
        {
            break;
        }

        if (prev != -1 && (ind1 < cur) && (ind1 > prev))
        {
            break;
        }

        if ((ind1 < cur))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }

        prev = cur;
    }

    return ans;
}

double findMedianSortedArrays(vector<int> &a1, vector<int> &a2)
{
    int n = a1.size();
    int m = a2.size();

    int ind1 = (n + m - 1) / 2;
    int ind2 = (n + m) / 2;
    // cout << ind1 << " " << ind2 << "\n";
    // find ind1 in first array
    int ans1 = median(a1, a2, ind1, n);
    int ans2 = ans1;
    double num1, num2;
    if (ans1 == -1)
    {
        ans1 = median(a2, a1, ind1, m);
        ans2 = ans1;
        if (ans1 != -1)
        {
            num1 = (double)a2[ans1];
            num2 = (double)a2[ans2];
        }
        // cout << ind1 << " " << ans1 << " " << ans2 << "\n";
    }
    else
    {
        num1 = (double)a1[ans1];
        num2 = (double)a1[ans2];
    }

    double ans = 0;
    if ((n + m) % 2 == 0)
    {
        ans2 = median(a1, a2, ind2, n);
        if (ans2 == -1)
        {
            ans2 = median(a2, a1, ind2, m);
            if (ans2 == -1)
            {
                num2 = (double)a2[ans2];
            }
        }
        else
        {
            num2 = (double)a1[ans2];
        }
        ans = (double)(num1 + num2) / 2.0;
    }
    else
    {
        if (ans1 < 0)
        {
            ans = num2;
        }
        else
        {
            ans = num1;
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    cout << num1 << " " << num2 << "\n";

    return ans;
}

double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2)
{
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2)
        return findMedianSortedArrays(nums2, nums1);

    int lo = 0, hi = N2 * 2;
    while (lo <= hi)
    {
        int mid2 = (lo + hi) / 2;
        int mid1 = N1 + N2 - mid2;

        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1) / 2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2) / 2];

        if (L1 > R2)
            lo = mid2 + 1;
        else if (L2 > R1)
            hi = mid2 - 1;
        else
            return (max(L1, L2) + min(R1, R2)) / 2;
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
    // cin >> test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a1(n), a2(m);
        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a2[i];
        }

        cout << findMedianSortedArrays1(a1, a2);
    }
    return 0;
}