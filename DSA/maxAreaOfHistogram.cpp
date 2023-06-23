#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

void printArray(vector<int> &a);
int maxAreaOfHistogram(vector<int> &a, vector<int> &left, vector<int> &right);

int maxAreaOfHistogram(vector<int> &a, vector<int> &left, vector<int> &right)
{
    stack<int> s;
    // for right
    int n = a.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            right[i] = n - 1;
        }
        else
        {
            right[i] = s.top() - 1;
        }
        s.push(i);
    }
    while (!s.empty())
    {
        s.pop();
    }
    // for left
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            left[i] = 0;
        }
        else
        {
            left[i] = s.top() + 1;
        }
        s.push(i);
    }

    printArray(a);
    printArray(left);
    printArray(right);

    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        mx = max(mx, ((i - left[i] + 1) + (right[i] - i + 1) - 1) * a[i]);
    }

    return mx;
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
    // cin >> test;
    while (test--)
    {
        vector<int> hist;
        vector<int> left;
        vector<int> right;
        int x;
        int i = 0;
        while (cin >> x)
        {
            hist.push_back(x);
            i++;
        }
        left.resize(i);
        right.resize(i);

        cout << maxAreaOfHistogram(hist, left, right);
    }
    return 0;
}