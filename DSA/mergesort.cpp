#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

void merge(vector<int> &a, int low, int mid, int high);
void mergesort(vector<int> &a);
void mergesort_util(vector<int> &a, int low, int high);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    int n = 9;
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << ' ';
    }
    cout << "\n";
    mergesort(a);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

void mergesort(vector<int> &a)
{
    mergesort_util(a, 0, a.size() - 1);
}

void mergesort_util(vector<int> &a, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergesort_util(a, low, mid);
    mergesort_util(a, mid + 1, high);
    merge(a, low, mid, high);
}

void merge(vector<int> &a, int low, int mid, int high)
{
    vector<int> temp;
    temp.resize(high - low + 1);
    int temp_cnt = 0;
    int l = low, m = mid + 1;

    while (l <= mid && m <= high)
    {
        if (a[l] < a[m])
        {
            temp[temp_cnt] = a[l];
            l++;
        }
        else
        {
            temp[temp_cnt] = a[m];
            m++;
        }
        temp_cnt++;
    }
    while (l <= mid)
    {
        temp[temp_cnt] = a[l];
        temp_cnt++;
        l++;
    }
    while (m <= high)
    {
        temp[temp_cnt] = a[m];
        temp_cnt++;
        m++;
    }
    // cout << low << " " << mid << " " << high << " - ";
    for (int i = 0; i < high - low + 1; i++)
    {
        a[low + i] = temp[i];
        // cout << temp[i] << " ";
    }
    // cout << "\n";
}