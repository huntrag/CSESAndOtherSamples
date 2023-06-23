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
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> moves({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});
    int counter = 1;
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> steps({n, n - 1});
    int x = -1, y = 0;
    int dir = 0;
    while (steps[dir % 2] > 0)
    {
        int orient = dir % 2;
        for (int i = 1; i <= steps[orient]; i++)
        {
            y = y + moves[dir][0];
            x = x + moves[dir][1];
            a[y][x] = counter;
            counter++;
        }
        steps[orient]--;
        dir = (dir + 1) % 4;
    }
    return a;
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
        vvi a = generateMatrix(n);
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[0].size(); j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}