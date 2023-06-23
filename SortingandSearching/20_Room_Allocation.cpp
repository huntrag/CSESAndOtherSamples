#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)

struct comp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first > b.first)
        {
            return true;
        }
        else if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return false;
    }
};

struct room
{
    int arr;
    int dep;
    int ind;
};

bool comp1(room a, room b)
{
    if (a.arr < b.arr)
    {
        return true;
    }
    else if (a.arr == b.arr)
    {
        return a.dep < b.dep;
    }
    return false;
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
    vector<room> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].arr = x;
        a[i].dep = y;
        a[i].ind = i;
    }
    sort(a.begin(), a.end(), comp1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> p;
    int room = 0;
    vector<int> ans(n);
    for (int i = 1; i < n; i++)
    {
        if (p.empty())
        {
            room++;
            ans[a[0].ind] = room;
            p.push(mp(a[0].dep, room));
        }
        if (a[i].arr <= p.top().first)
        {
            room++;
            p.push(mp(a[i].dep, room));
            ans[a[i].ind] = room;
        }
        else
        {
            int temp = p.top().second;
            p.pop();
            p.push(mp(a[i].dep, temp));
            ans[a[i].ind] = temp;
        }
    }
    cout << room << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}