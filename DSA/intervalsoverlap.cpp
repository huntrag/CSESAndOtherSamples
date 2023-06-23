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

vector<vector<int>> insert(vector<vector<int>> &in, vector<int> &newInterval)
{
    vector<vector<int>> temp(in.size() + 1, vector<int>(2));
    int st = newInterval[0];
    int en = newInterval[1];
    int i = 0;
    int cnt = 0;
    bool flag = true;
    while (i < in.size())
    {
        if (flag && st <= in[i][0])
        {
            flag = false;
            temp[cnt][0] = st;
            temp[cnt][1] = en;
            cnt++;
        }
        temp[cnt][0] = in[i][0];
        temp[cnt][1] = in[i][1];
        cnt++;
        i++;
    }
    if (flag)
    {
        temp[cnt][0] = st;
        temp[cnt][1] = en;
    }

    vector<vector<int>> res;
    st = temp[0][0];
    en = temp[0][1];
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i][0] > en)
        {
            res.push_back(vector<int>({st, en}));
            st = temp[i][0];
            en = temp[i][1];
        }
        else
        {
            en = max(en, temp[i][1]);
        }
    }
    res.push_back(vector<int>({st, en}));
    return res;
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
        int n;
        cin >> n;
        vvi a(n, vi(2));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> a[i][j];
            }
        }
        vi r(2);
        cin >> r[0] >> r[1];
        vvi ans = insert(a, r);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << ans[i][j] << " ";
                ;
            }
            cout << "\n";
        }
    }
    return 0;
}