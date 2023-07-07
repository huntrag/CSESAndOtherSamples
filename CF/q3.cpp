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

bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first > b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        if (a.second < b.second)
        {
            return true;
        }
    }
    return false;
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
    cin >> test;
    while (test--)
    {
        ll n, m, h;
        cin >> n >> m >> h;
        vector<pair<ll, ll>> score(n);

        vvll a(n, vll(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            sort(a[i].begin(), a[i].end());
        }

        for (int i = 0; i < n; i++)
        {
            ll tm = 0;
            ll pen = 0;
            int j;
            for (j = 0; j < m; j++)
            {
                if (tm + a[i][j] > h)
                {
                    break;
                }
                tm = (ll)tm + a[i][j];
                pen = (ll)pen + tm;
            }
            score[i] = make_pair(j, pen);
        }

        pair<ll, ll> her = score[0];

        sort(score.begin(), score.end(), comp);
        int i;
        for (i = 0; i < n; i++)
        {
            if (score[i].first == her.first && score[i].second == her.second)
            {
                break;
            }
        }
        cout << i + 1 << "\n";
    }
    return 0;
}