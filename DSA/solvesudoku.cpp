#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<unordered_set<int>> vus;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
#define MOD 1000000007
#define fi first
#define se second

bool check(vector<vector<char>> &board, int i, int j, char val)
{
    int row = i - i % 3, column = j - j % 3;
    for (int x = 0; x < 9; x++)
        if (board[x][j] == val)
            return false;
    for (int y = 0; y < 9; y++)
        if (board[i][y] == val)
            return false;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            if (board[row + x][column + y] == val)
                return false;
    return true;
}
bool solveSudoku(vector<vector<char>> &board, int i, int j)
{
    if (i == 9)
        return true;
    if (j == 9)
        return solveSudoku(board, i + 1, 0);
    if (board[i][j] != '.')
        return solveSudoku(board, i, j + 1);

    for (char c = '1'; c <= '9'; c++)
    {
        if (check(board, i, j, c))
        {
            board[i][j] = c;
            if (solveSudoku(board, i, j + 1))
                return true;
            board[i][j] = '.';
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    solveSudoku(board, 0, 0);
}

// ------------------- my sol but slow
vus cols;
vus rows;
vus grids;

int no(int &i, int &j)
{
    return (i / 3) * 3 + j / 3;
}

bool check(vector<vector<char>> &board, int i, int j, char val)
{
    int k = val - '0';

    bool b1 = (cols[j].find(k) == cols[j].end());
    bool b2 = (rows[i].find(k) == rows[i].end());
    bool b3 = (grids[no(i, j)].find(k) == grids[no(i, j)].end());

    return (b1 & b2 & b3);
}
bool solveSudoku(vector<vector<char>> &board, int i, int j)
{
    if (i == 9)
        return true;
    if (j == 9)
        return solveSudoku(board, i + 1, 0);
    if (board[i][j] != '.')
        return solveSudoku(board, i, j + 1);

    for (char c = '1'; c <= '9'; c++)
    {
        if (check(board, i, j, c))
        {
            board[i][j] = c;
            int k = c - '0';
            cols[j].insert(k);
            rows[i].insert(k);
            grids[no(i, j)].insert(k);
            if (solveSudoku(board, i, j + 1))
                return true;
            board[i][j] = '.';
            cols[j].erase(k);
            rows[i].erase(k);
            grids[no(i, j)].erase(k);
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>> &a)
{
    cols.resize(9);
    rows.resize(9);
    grids.resize(9);
    int x;
    int n = 9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] != '.')
            {
                x = a[i][j] - '0';
                cols[j].insert(x);
                rows[i].insert(x);
                grids[no(i, j)].insert(x);
            }
        }
    }
    solveSudoku(a, 0, 0);
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
    }
    return 0;
}