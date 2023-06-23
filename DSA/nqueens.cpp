#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<string>> vvs;
#define MOD 1000000007
#define fi first
#define se second

vvs res;
vb col, row, dia, cross;
vector<pair<int, int>> pos;

void backtrack(int y)
{
    int n = row.size() - 1;
    if (y == row.size())
    {
        vector<string> temp(y);
        for (int i = 0; i < y; i++)
        {
            string s;
            for (int j = 0; j < y; j++)
            {
                if (pos[i].first == i && pos[i].second == j)
                {
                    s.push_back('Q');
                }
                else
                {
                    s.push_back('.');
                }
            }
            temp[i] = s;
        }
        res.push_back(temp);
        return;
    }

    for (int x = 0; x < col.size(); x++)
    {
        if (col[x] || row[y] || dia[x + y] || cross[abs(n + y - x)])
        {
            continue;
        }
        pos.push_back(make_pair(y, x));
        col[x] = row[y] = dia[x + y] = cross[abs(n + y - x)] = true;
        backtrack(y + 1);
        pos.pop_back();
        col[x] = row[y] = dia[x + y] = cross[abs(n + y - x)] = false;
    }
}

vvs solveNQueens(int n)
{
    col.resize(n);
    row.resize(n);
    dia.resize(2 * n);
    cross.resize(2 * n);
    backtrack(0);
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
        vvs ans = solveNQueens(4);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << "\n";
            }
            cout << "------------------------\n";
        }
    }
    return 0;
}