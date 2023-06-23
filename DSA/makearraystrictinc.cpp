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

vi dp;
vector<bool> vis;
int n;

int floor_binary_search(vector<int> &a, int key)
{
    int low = -1;
    int high = a.size() - 1;

    int mid;
    while ((high - low) > 1)
    {
        mid = (low + high + 1) / 2;
        if (a[mid] < key)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    if (a[high] > key)
    {
        return low;
    }
    return high;
}

int ceil_binary_search(vector<int> &a, int key)
{
    int low = 0;
    int high = a.size();
    int mid;

    while ((high - low) > 1)
    {
        mid = low + (high - low) / 2;

        if (a[mid] <= key)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
        // cout << mid << "\n";
    }
    if (a[low] < key)
    {
        return low + 1;
    }

    return low;
}

long solve(int ind, int low, vi &a1, vi &a2)
{
    if (ind == n - 1)
    {
        return 0;
    }
    if (a1[ind] < low)
    {
        return INT_MAX;
    }
    int m = a2.size();
    int cur = a1[ind];
    int nxt = a1[ind + 1];
    long mn = INT_MAX;
    int lo1 = ceil_binary_search(a2, low + 1);
    int lo2 = ceil_binary_search(a2, cur + 1);
    int hi1 = floor_binary_search(a2, nxt - 1);

    if (a1[ind + 1] > a1[ind])
    {
        // case 1: when next is greater dont change it and see how it goes
        mn = min(mn, solve(ind + 1, a1[ind], a1, a2));
        // case 2: even though its greater find the next greater than low to replace with current
        if (lo1 >= 0 && lo1 < m)
        {
            a1[ind] = a2[lo1];
            mn = min(mn, 1 + solve(ind + 1, a1[ind], a1, a2));
            a1[ind] = cur;
        }
        // case 3: replace ind+1 with the elem just greater than cur in a2
        // if(lo2>=0 && lo2<m){
        //     a1[ind+1]=a2[lo2];
        //     mn=min(mn,1+solve(ind+1,cur,a1,a2));
        //     a1[ind+1]=nxt;
        // }
    }
    else
    {
        // now cur is greater than nxt
        // case 1: find less than nxt and change cur to that
        if (hi1 >= 0 && hi1 < m && a2[hi1] > low)
        {
            a1[ind] = a2[hi1];
            mn = min(mn, 1 + solve(ind + 1, a1[ind], a1, a2));
            a1[ind] = cur;
        }
        // case 2: find greater than cur and change nxt to that
        if (lo2 >= 0 && lo2 < m)
        {
            a1[ind + 1] = a2[lo2];
            mn = min(mn, 1 + solve(ind + 1, cur, a1, a2));
            a1[ind + 1] = nxt;
        }

        // case 3: find just greater than low and swap cur with that
        if (lo1 >= 0 && lo1 < m)
        {
            if (a2[lo1] < nxt)
            {

                cout << lo1 << " " << nxt << "\n";

                a1[ind] = a2[lo1];
                mn = min(mn, 1 + solve(ind + 1, a1[ind], a1, a2));
                a1[ind] = cur;
            }
            else
            {
                if (lo1 + 1 < m)
                {
                    cout << "Madar";
                    a1[ind] = a2[lo1];
                    a1[ind + 1] = a2[lo1 + 1];
                    mn = min(mn, 2 + solve(ind + 1, a1[ind], a1, a2));
                    a1[ind] = cur;
                    a1[ind + 1] = nxt;
                }
            }
        }
    }
    return mn;
}

int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
{
    vi arr;
    set<int> st;
    for (int i = 0; i < arr2.size(); i++)
    {
        st.insert(arr2[i]);
    }
    for (auto &r : st)
    {
        arr.push_back(r);
    }
    n = arr1.size();
    dp.resize(n);
    vis.resize(n);
    long ans = solve(0, -1, arr1, arr);

    if (ans >= INT_MAX)
    {
        return -1;
    }
    return (int)ans;
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
        int n, m;
        cin >> n >> m;
        vi a(n), b(m);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (auto &r : b)
        {
            cin >> r;
        }

        cout << makeArrayIncreasing(a, b);
    }
    return 0;
}