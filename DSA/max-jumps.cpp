#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

int minJump(int arr[], int n)
{
    queue<int> q;
    q.push(0);
    vector<bool> vis(n, false);
    vector<int> parent(n, -1);
    vis[0] = true;
    bool flag = false;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = arr[cur]; i >= 1; i--)
        {
            if (cur + i >= n - 1)
            {
                flag = true;
                parent[n - 1] = cur;
                break;
            }
            else if (vis[cur + i] == false)
            {
                q.push(cur + i);
                parent[cur + i] = cur;
                vis[cur + i] = true;
            }
        }

        if (flag)
        {
            break;
        }
    }
    int cnt = 0;
    for (int i = n - 1; i != 0; i = parent[i])
    {
        cnt++;
    }
    return cnt;
}

int minJumps(int arr[], int n)
{
    int max_reach = 0, steps = 0, last_jump = 0;

    for (int i = 0; i < n; i++)
    {
        max_reach = max(i + arr[i], max_reach);
        if (last_jump == i)
        {
            steps++;
            last_jump = max_reach;
        }
        if (last_jump >= n - 1)
        {
            break;
        }
    }
    if (last_jump < n - 1)
    {
        return -1;
    }
    return steps;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minJumps(arr, n);

    return 0;
}