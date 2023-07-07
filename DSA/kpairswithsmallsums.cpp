#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef pair<ll, ll> pll;
#define MOD 1000000007
#define fi first
#define se second

class Compare
{
public:
    bool operator()(pll &a, pll &b)
    {
        ll sum1 = a.fi + a.se;
        ll sum2 = b.fi + b.se;

        if (sum1 > sum2)
        {
            return false;
        }
        return true;
    }
};

vvi kSmallestPairs(vi &a1, vi &a2, int k)
{
    priority_queue<pll, vpll, Compare> pq;

    int i1 = 0;
    int i2 = 0;
    while (pq.size() < k)
    {
        if (i2 == a2.size())
        {
            i1++;
            if (i1 == a1.size())
            {
                break;
            }
            i2 = 0;
        }
        pq.push(make_pair(a1[i1], a2[i2]));
        // cout << a1[i1] << " " << a2[i2] << "\n";
        i2++;
    }
    // cout << i1 << " " << i2 << "\n";
    while (i1 < a1.size())
    {
        while (i2 < a2.size())
        {
            if (a2[i2] + a1[i1] < pq.top().fi + pq.top().se)
            {
                pq.pop();
                pq.push(make_pair(a1[i1], a2[i2]));
                // cout << a1[i1] << " " << a2[i2] << "\n";
                i2++;
            }
            else
            {
                break;
            }
        }
        i1++;
        i2 = 0;
    }

    vector<vector<int>> ans;

    while (!pq.empty())
    {
        ans.push_back(vector<int>({(int)pq.top().fi, (int)pq.top().se}));
        pq.pop();
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        vi a(n), b(n);

        for (auto &x : a)
        {
            cin >> x;
        }

        for (auto &x : b)
        {
            cin >> x;
        }

        vvi ans = kSmallestPairs(a, b, k);
        for (auto &x : ans)
        {
            for (auto &r : x)
            {
                cout << r << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}