#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

vector<int> nextPermutation(int N, vector<int> arr)
{
    vector<int> res;
    vector<int> ans(N);
    res.push_back(arr[N - 1]);
    int pivot = -1;
    for (int i = N - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[i + 1])
        {
            res.push_back(arr[i]);
        }
        else
        {
            pivot = i;
            break;
        }
    }
    if (pivot == -1)
    {

        for (int i = 0; i < N; i++)
        {
            ans[i] = arr[N - 1 - i];
        }
        return ans;
    }
    else
    {
        for (int i = 0; i < pivot; i++)
        {
            ans[i] = arr[i];
        }
        sort(res.begin(), res.end());
        int val = *upper_bound(res.begin(), res.end(), arr[pivot]);
        int replaced = arr[pivot];
        ans[pivot] = val;
        for (int i = pivot + 1; i < N; i++)
        {
            if (res[i - pivot - 1] == val)
            {
                res[i - pivot - 1] = replaced;
            }
            ans[i] = res[i - pivot - 1];
        }

        return ans;
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

    vector<int> res = nextPermutation(6, {6, 5, 1, 1, 3, 1});

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}