// Prob link:  https://www.spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

int cellToNum(char a, char b)
{
    int num = 0;
    num = (int)num + (a - 'a');
    num = (int)num + (b - '1') * 8;

    return num;
}

string numToCell(int &a)
{
    string s = "qw";
    s[0] = (a / 8) + '1';
    s[1] = (a % 8) + 'a';

    return s;
}

int up(int code)
{
    return code / 1000;
}

int down(int code)
{
    return (code % 1000) / 100;
}

int right(int code)
{
    return (code % 100) / 10;
}

int left(int code)
{
    return (code % 10);
}

bool isValid(int cell, int code)
{
    int row = cell / 8;
    int col = (cell % 8);
    // cout << row << " " << col << " " << up(code) << " " << down(code) << " " << right(code) << " " << left(code) << "\n ";
    // cout << code << " " << right(code) << "\n";
    if (row + up(code) <= 7 && row - down(code) >= 0 && col - left(code) >= 0 && col + right(code) <= 7)
    {
        return true;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    vector<pair<int, int>> moves{{+17, 2010}, {+10, 1020}, {-6, 120}, {-15, 210}, {-17, 201}, {-10, 102}, {+6, 1002}, {+15, 2001}};
    vector<int> steps(64, 1000);
    vector<int> parent(64, -1);
    while (test--)
    {
        string s;
        getline(cin >> ws, s);
        int src = cellToNum(s[0], s[1]);
        int des = cellToNum(s[3], s[4]);

        for (int i = 0; i < 64; i++)
        {
            steps[i] = 1000;
            parent[i] = -1;
        }
        steps[src] = 0;

        queue<int> q;
        q.push(src);
        bool flag = true;
        while (flag && !q.empty())
        {
            int cur_cell = q.front();
            // cout << cur_cell << " ";
            q.pop();
            int new_cell;
            for (auto &move : moves)
            {
                if (!isValid(cur_cell, move.se))
                {
                    continue;
                }
                new_cell = cur_cell + move.fi;
                if (new_cell < 0 || new_cell > 63)
                {
                    continue;
                }
                if (steps[new_cell] < steps[cur_cell] + 1)
                {
                    continue;
                }
                steps[new_cell] = steps[cur_cell] + 1;
                parent[new_cell] = cur_cell;
                if (new_cell == des)
                {
                    flag = false;
                    break;
                }
                q.push(new_cell);
            }
        }
        // stack<int> stk;
        // for (int i = des; i != -1; i = parent[i])
        // {
        //     stk.push(i);
        // }
        // while (!stk.empty())
        // {
        //     cout << stk.top() << " " << numToCell(stk.top()) << "\n";
        //     stk.pop();
        // }
        // cout << "Moves: ";
        cout << steps[des] << "\n";
    }
    return 0;
}

// Submitted Correctly