#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 20;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int rnd = rand() % 100;
        if (rnd < 50)
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = -1;
        }
        cout << arr[i] << " ";
    }
    cout << "\n";

    int low = 0, high = n - 1;

    while (low < high)
    {
        while (arr[low] > 0 && low < high)
        {
            low++;
        }
        while (arr[high] < 0 && low < high)
        {
            high--;
        }
        if (low < high)
        {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}