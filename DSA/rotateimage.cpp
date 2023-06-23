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

void fourwayswap(int &a1, int &a2, int &a3, int &a4)
{
    swap(a1, a2);
    swap(a3, a4);
    swap(a1, a3);
}
void rotate(vector<vector<int>> &a)
{
    int n = a.size();

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            fourwayswap(a[i][j], a[j][n - 1 - i], a[n - 1 - i][n - 1 - j], a[n - 1 - j][i]);
        }
    }
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