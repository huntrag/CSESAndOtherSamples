#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n - 1);
    ll sum = 0;
    for (auto &c : a)
    {
        cin >> c;
        sum += (ll)c;
    }
    cout << (ll)n * (n + 1) / 2 - sum;
    return 0;
}