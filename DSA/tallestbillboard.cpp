// meet in the middle
// and fantastic dp

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
int mask = 3;

void nextmask(vi &a)
{
    vi prev(a);

    int nd = prev[0];

    a[0] = (prev[0] + 1) % mask;

    for (int i = 1; i < a.size(); i++)
    {
        a[i] = (prev[i] + (nd & 2) / 2) % mask;
        nd = (nd & prev[i]);
    }
}
int tallestBillboard(vector<int> &rods)
{
    int n = rods.size();
    vi a1(5001, -1), a2(5001, -1);
    int mid = n / 2;
    ll tot = pow(3, mid);
    vi bits(mid, 0);
    int mx = 0;
    for (int i = 0; i < tot; i++)
    {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < mid; j++)
        {
            if (bits[j] == 1)
            {
                sum1 += rods[j];
            }
            else if (bits[j] == 2)
            {
                sum2 += rods[j];
            }
        }
        a1[abs(sum1 - sum2)] = max(a1[abs(sum1 - sum2)], min(sum1, sum2));
        nextmask(bits);
    }

    int nxt = n - mid;
    vi bits1(nxt, 0);
    tot = pow(3, nxt);

    for (int i = 0; i < tot; i++)
    {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < nxt; j++)
        {
            if (bits1[j] == 1)
            {
                sum1 += rods[mid + j];
            }
            else if (bits1[j] == 2)
            {
                sum2 += rods[mid + j];
            }
        }
        a2[abs(sum1 - sum2)] = max(a2[abs(sum1 - sum2)], max(sum1, sum2));
        nextmask(bits1);
    }
    mx = 0;

    for (int i = 0; i < a1.size(); i++)
    {
        // cout << i << " " << a1[i] << " " << a2[i] << "\n";
        if (a1[i] != -1 && a2[i] != -1)
        {
            mx = max(mx, a1[i] + a2[i]);
        }
    }

    return mx;
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
        int x;
        vi a;
        while (cin >> x)
        {
            a.push_back(x);
        }

        cout << tallestBillboard(a);
    }
    return 0;
}