#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second

void Hanoi(int n, int start, int inter, int end)
{
    if (n == 0)
    {
        return;
    }
    Hanoi(n - 1, start, end, inter);
    cout << start << " " << end << "\n";
    Hanoi(n - 1, inter, start, end);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << "\n";
    Hanoi(n, 1, 2, 3);
    return 0;
}