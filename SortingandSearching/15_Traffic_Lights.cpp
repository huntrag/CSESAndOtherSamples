#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    multiset<int> p;
    p.insert(n);
    set<int> s;
    s.insert(0);
    s.insert(n);
    while (m--)
    {
        int x;
        cin >> x;
        auto next = s.upper_bound(x);
        auto prev = next;
        prev--;
        s.insert(x);
        int orig_length = *(next) - *(prev);
        p.insert(*(next)-x);
        p.insert(x - *(prev));
        p.erase(p.find(orig_length));
        auto mx = p.end();
        mx--;
        cout << *mx << " ";
    }

    return 0;
}