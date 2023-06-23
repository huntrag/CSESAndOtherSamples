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

int res;
vb col, row, dia, cross;

void backtrack(int y)
{
    int n = row.size() - 1;
    if (y == row.size())
    {
        res++;
        return;
    }

    for (int x = 0; x < col.size(); x++)
    {
        if (col[x] || row[y] || dia[x + y] || cross[abs(n + y - x)])
        {
            continue;
        }
        col[x] = row[y] = dia[x + y] = cross[abs(n + y - x)] = true;
        backtrack(y + 1);
        col[x] = row[y] = dia[x + y] = cross[abs(n + y - x)] = false;
    }
}

int totalNQueens(int n)
{
    col.resize(n);
    row.resize(n);
    dia.resize(2 * n);
    cross.resize(2 * n);
    res = 0;
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
        cout << totalNQueens(4);
    }
    return 0;
}