#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

void inserting(vector<set<int>> &s)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            s[i].insert(j);
        }
    }
}

vvi converttoint(vvc &b)
{
    vvi a(9, vi(9, 0));
    int dp[9][9][10]{0};
    vector<set<int>> col(9);
    vector<set<int>> row(9);
    vector<set<int>> grid(9);

    inserting(col);
    inserting(row);
    inserting(grid);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (b[i][j] != '.')
            {
                a[i][j] = b[i][j] - '0';
                dp[i][j][a[i][j]] = 1;
                col[j].erase(a[i][j]);
                row[i].erase(a[i][j]);
                grid[grid1(i, j)].erase(a[i][j]);
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
        }
    }

    return a;
}

int grid1(int i, int j)
{
    return i / 3 + (j % 3);
}

void solveSudoku(vvc &b)
{
    vvi a = converttoint(b);
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
    cin >> test;
    while (test--)
    {
        vvc a(9, vc(9));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> a[i][j];
            }
        }
    }
    return 0;
}