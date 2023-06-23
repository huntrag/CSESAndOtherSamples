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

void sortColors1(vi &a)
{
    if (a.size() <= 2)
    {
        if (a.size() == 2)
        {
            if (a[0] > a[1])
            {
                swap(a[0], a[1]);
            }
        }
        return;
    }
    int n = a.size();
    int pt0 = 0;
    int pt2 = n - 1;
    int pt1 = n - 1;
    while (pt0 < pt1)
    {
        // for (int i = 0; i < a.size(); i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << " || ";
        while (pt2 >= pt0 && a[pt2] == 2)
        {
            pt2--;
        }
        pt1 = pt2;
        while (pt0 < pt1 && a[pt0] == 0)
        {
            pt0++;
        }
        while (pt0 < pt1 && a[pt1] == 1)
        {
            pt1--;
        }
        if (pt0 < pt1 && a[pt0] != 0 && a[pt1] == 0)
        {
            swap(a[pt1], a[pt0]);
            pt1--;
            pt0++;
        }
        else if (pt1 < pt2 && a[pt1] == 2 && a[pt2] != 2)
        {
            swap(a[pt1], a[pt2]);
            pt2--;
        }
        // cout << pt0 << " " << pt1 << " " << pt2 << " | "
        //      << a[pt0] << " " << a[pt1] << " " << a[pt2] << " || ";
        // for (int i = 0; i < a.size(); i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << "\n";
    }
    int zerobound = pt0 - 1;
    pt2 = n - 1;
    while (pt2 >= 0 && a[pt2] == 2)
    {
        pt2--;
    }
    if (pt2 == -1)
    {
        return;
    }
    pt1 = n - 1;
    while (pt1 >= 0 && pt1 < pt2)
    {
        while (pt1 >= 0 && pt1 < pt2 && a[pt1] != 2)
        {
            pt1--;
        }
        if (pt1 >= 0 && pt1 < pt2)
        {
            swap(a[pt1], a[pt2]);
            pt2--;
        }
        if (a[pt1] == 0)
        {
            swap(a[pt1], a[zerobound]);
            zerobound--;
        }
    }
}

void sortColors(vector<int> &a)
{
    int pt0, pt1;
    pt0 = 0;
    int n = a.size();
    pt1 = n - 1;

    while (pt0 <= pt1)
    {
        // cout << pt0 << " " << pt1 << "\n";
        while (pt0 <= pt1 && a[pt0] == 0)
        {
            pt0++;
        }
        while (pt0 <= pt1 && a[pt1] != 0)
        {
            pt1--;
        }
        // cout << pt0 << " " << pt1 << "\n";
        if (pt0 <= pt1)
        {
            swap(a[pt0], a[pt1]);
            pt0++;
            pt1--;
        }
    }
    pt1 = pt0;
    int pt2 = n - 1;

    while (pt1 <= pt2)
    {
        while (pt1 <= pt2 && a[pt1] == 1)
        {
            pt1++;
        }
        while (pt1 <= pt2 && a[pt2] == 2)
        {
            pt2--;
        }
        if (pt1 <= pt2)
        {
            swap(a[pt1], a[pt2]);
            pt1++;
            pt2--;
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
        vi a;
        int x;
        while (cin >> x)
        {
            a.push_back(x);
        }

        sortColors(a);

        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}