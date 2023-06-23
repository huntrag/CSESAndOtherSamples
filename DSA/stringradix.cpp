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

vi convert(int x)
{
    vi ans;
    while (x > 0)
    {
        ans.push_back(x % 10);
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void radix(vvi &a, int ind)
{
    vi count(10, 0);

    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        count[a[i][min(ind, (int)a[i].size() - 1)]]++;
    }

    vvi output(n);

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[a[i][min(ind, (int)a[i].size() - 1)]] - 1] = a[i];
        count[a[i][min(ind, (int)a[i].size() - 1)]]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

string largestNumber(vi &a)
{
    int n = a.size();
    vvi b;
    string s = "";

    for (auto &num : a)
    {
        b.push_back(convert(num));
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, (int)b[i].size());
        // for (int j = 0; j < b[i].size(); j++)
        // {
        //     cout << b[i][j] << " ";
        // }
        // cout << "\n";
    }

    for (int i = mx; i >= 0; i--)
    {
        radix(b, i);
    }

    reverse(b.begin(), b.end());

    // cout << "-------\n";

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < b[i].size(); j++)
    //     {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            s.push_back(b[i][j] + '0');
        }
    }

    return s;
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
        cout << largestNumber(a);
    }
    return 0;
}