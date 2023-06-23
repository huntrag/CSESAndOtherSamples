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

vector<int> spiralOrder(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<int> ans(n * m);
    int cnt = 0;
    bool temp1 = false, temp2 = false;
    int start1 = 0, end1 = m - 1;
    int start2 = 0, end2 = n - 1;
    int start3 = m - 1, end3 = 0;
    int start4 = n - 1, end4 = 0;
    while (cnt < ans.size())
    {
        if (start1 <= end1 && temp1 == false && temp2 == false)
        {
            for (int i = start1; cnt < ans.size() && i <= end1; i++)
            {
                ans[cnt] = a[start2][i];
                cnt++;
            }
            temp1 = true;
            start1++;
            end1--;
        }
        else if (start2 < end2 && temp1 == true && temp2 == false)
        {
            for (int i = start2 + 1; cnt < ans.size() && i <= end2; i++)
            {
                ans[cnt] = a[i][start3];
                cnt++;
            }
            temp1 = true;
            temp2 = true;
            start2++;
            end2--;
        }
        else if (start3 > end3 && temp1 == true && temp2 == true)
        {
            for (int i = start3 - 1; cnt < ans.size() && i > end3; i--)
            {
                ans[cnt] = a[start4][i];
                cnt++;
            }
            temp1 = false;
            start3--;
            end3++;
        }
        else if (start4 > end4 && temp1 == false && temp2 == true)
        {
            for (int i = start4; cnt < ans.size() && i > end4; i--)
            {
                ans[cnt] = a[i][start1 - 1];
                cnt++;
            }
            temp1 = false;
            temp2 = false;
            start4--;
            end4++;
        }
        else
        {
            break;
        }
    }
    return ans;
}

vector<int> spiralOrder1(vector<vector<int>> &matrix)
{
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> res;
    int nr = matrix.size();
    if (nr == 0)
        return res;
    int nc = matrix[0].size();
    if (nc == 0)
        return res;

    vector<int> nSteps{nc, nr - 1};

    int iDir = 0;        // index of direction.
    int ir = 0, ic = -1; // initial position
    while (nSteps[iDir % 2])
    {
        for (int i = 0; i < nSteps[iDir % 2]; ++i)
        {
            ir += dirs[iDir][0];
            ic += dirs[iDir][1];
            res.push_back(matrix[ir][ic]);
        }
        nSteps[iDir % 2]--;
        iDir = (iDir + 1) % 4;
    }
    return res;
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
        int n, m;
        cin >> n >> m;
        vvi a(n, vi(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        vi ans = spiralOrder(a);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}