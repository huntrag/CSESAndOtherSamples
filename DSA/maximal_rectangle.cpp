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

    // printArray(a);
    // printArray(left);
    // printArray(right);

    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        mx = max(mx, ((i - left[i] + 1) + (right[i] - i + 1) - 1) * a[i]);
    }

    return mx;
}

void printArray(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << setw(2) << a[i];
    }
    cout << "\n";
}

int maximalRectangle(vector<vector<char>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = a[i][0] - '0';
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] == '1')
            {
                dp[i][j] = dp[i][j - 1] + 1;
            }
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    int mx = 0;
    vector<int> hist(n);
    vector<int> left(n);
    vector<int> right(n);
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            hist[i] = dp[i][j];
        }
        mx = max(mx, maxAreaOfHistogram(hist, left, right));
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
    //    cin>>test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }

        cout << maximalRectangle(mat);

        // vector<int> hist;
        // vector<int> left;
        // vector<int> right;
        // int x;
        // int i = 0;
        // while (cin >> x)
        // {
        //     hist.push_back(x);
        //     i++;
        // }
        // left.resize(i);
        // right.resize(i);

        // cout << maxAreaOfHistogram(hist, left, right);
    }
    return 0;
}