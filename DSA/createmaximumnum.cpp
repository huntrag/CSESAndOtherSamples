#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> pii;
#define MOD 1000000007
#define fi first
#define se second

#define i2c(c) ((char)c + '0')

int indi(vi &a, int l, int r)
{
    return max_element(a.begin() + l, a.begin() + r + 1) - (a.begin());
}

void pigeonhole(vector<int> &a)
{
    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    vector<int> counts(mx - mn + 1);

    for (int i = 0; i < a.size(); i++)
    {
        counts[a[i] - mn]++;
    }
    int cnt = 0;
    for (int i = 0; i < counts.size(); i++)
    {
        while (counts[i] > 0)
        {
            a[cnt] = i + mn;
            cnt++;
            counts[i]--;
        }
    }
}

void get(vector<vi> &ans, vi &a, int l, int r, vi &cur)
{
    if (l > r)
    {
        return;
    }
    // if (cur.length() == a.size())
    // {
    //     return;
    // }
    int mx = indi(a, l, r);
    cur.push_back(mx);
    pigeonhole(cur);
    ans.push_back(cur);
    get(ans, a, mx + 1, r, cur);
    get(ans, a, l, mx - 1, cur);
}

bool great(vi &a1, vi &a2, vi &ind1, vi &ind2, int i1, int i2)
{
    while (i1 < ind1.size() && i2 < ind2.size() && a1[ind1[i1]] == a2[ind2[i2]])
    {
        i1++;
        i2++;
    }

    return (i2 == ind2.size() || (i1 < ind1.size() && a1[ind1[i1]] > a2[ind2[i2]]));
}

void create(vi &ans, vi &a1, vi &a2, vi &ind1, vi &ind2)
{
    int k = ans.size();
    for (int i1 = 0, i2 = 0, r = 0; r < k; r++)
    {
        ans[r] = great(a1, a2, ind1, ind2, i1, i2) ? a1[ind1[i1++]] : a2[ind2[i2++]];
    }
}

bool compare(vi &a1, vi &a2)
{
    for (int i = 0; i < a1.size(); i++)
    {
        if (a1[i] > a2[i])
        {
            return true;
        }
        else if (a1[i] == a2[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return false;
}

vi maxNumber(vi &a1, vi &a2, int k)
{
    vector<vi> ans1, ans2;
    vi s;
    ans1.push_back(s);
    get(ans1, a1, 0, a1.size() - 1, s);
    vi t;
    ans2.push_back(t);
    get(ans2, a2, 0, a2.size() - 1, t);

    vi ans(k);
    vi maxi(k);

    // cout << ans1.size() << " " << ans2.size() << "\n";

    for (int i = 0; i < ans1.size(); i++)
    {
        if (!((k - i) >= 0 && (k - i) <= ans2.size() - 1))
        {
            continue;
        }
        // cout << i << " " << k - i << "\n";
        create(ans, a1, a2, ans1[i], ans2[k - i]);
        // for (int j = 0; j < ans.size(); j++)
        // {
        //     cout << ans[j] << " ";
        // }
        // cout << "\n";
        if (compare(ans, maxi))
        {
            for (int j = 0; j < k; j++)
            {
                maxi[j] = ans[j];
            }
        }
    }

    return maxi;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    while (test--)
    {
        int n1, n2, k;
        cin >> n1 >> n2 >> k;
        vi a1(n1), a2(n2);

        for (auto &r : a1)
        {
            cin >> r;
        }

        for (auto &r : a2)
        {
            cin >> r;
        }

        vi ans = maxNumber(a1, a2, k);

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}

// vi maxNumber(vi &a1, vi &a2, int k)
// {
//     vi ans;
//     priority_queue<string, vector<string>> pq;

//     priority_queue<pii, vpii, greater<pair<int, int>>> pq1, pq2;
//     vector<bool> vb1(a1.size()), vb2(a2.size());

//     for (int i = 0; i < a1.size(); i++)
//     {
//         if (pq1.size() < k)
//         {
//             pq1.push(make_pair(a1[i], i));
//             vb1[i] = true;
//         }
//         else
//         {
//             if (pq1.empty())
//             {
//                 continue;
//             }
//             if (pq1.top().first < a1[i])
//             {
//                 vb1[i] = true;
//                 vb1[pq1.top().second] = false;
//                 pq1.pop();
//                 pq1.push(make_pair(a1[i], i));
//             }
//         }
//     }

//     for (int i = 0; i < a2.size(); i++)
//     {
//         if (pq2.size() < k - pq1.size())
//         {
//             pq2.push(make_pair(a2[i], i));
//             vb2[i] = true;
//         }
//         else
//         {
//             if (pq2.empty())
//             {
//                 continue;
//             }
//             if (pq2.top().first < a2[i])
//             {
//                 vb2[i] = true;
//                 vb2[pq2.top().second] = false;
//                 pq2.pop();
//                 pq2.push(make_pair(a2[i], i));
//             }
//         }
//     }

//     priority_queue<pair<int, int>, vector<pair<int, int>>> rese;

//     for (int i = 0; i < a2.size(); i++)
//     {
//         if (vb2[i])
//         {
//             continue;
//         }
//         rese.push(make_pair(a2[i], i));
//     }

//     do
//     {
//         int i1 = 0, i2 = 0;
//         while (i1 < a1.size() && vb1[i1] == false)
//             i1++;

//         while (i2 < a2.size() && vb2[i2] == false)
//             i2++;

//         string res = "";

//         while (i1 < a1.size() && i2 < a2.size())
//         {
//             if (a1[i1] > a2[i2])
//             {
//                 res.push_back(i2c(a1[i1]));
//                 i1++;
//                 while (i1 < a1.size() && vb1[i1] == false)
//                     i1++;
//             }
//             else
//             {
//                 res.push_back(i2c(a2[i2]));
//                 i2++;
//                 while (i2 < a2.size() && vb2[i2] == false)
//                     i2++;
//             }
//         }

//         while (i1 < a1.size())
//         {
//             res.push_back(i2c(a1[i1]));
//             i1++;
//             while (i1 < a1.size() && vb1[i1] == false)
//                 i1++;
//         }

//         while (i2 < a2.size())
//         {
//             res.push_back(i2c(a2[i2]));
//             i2++;
//             while (i2 < a2.size() && vb2[i2] == false)
//                 i2++;
//         }
//         pq.push(res);

//         vb1[pq1.top().second] = false;
//         pq1.pop();

//         vb2[rese.top().second] = true;
//         pq2.push(rese.top());
//         rese.pop();

//         cout << res << " " << pq1.size() + 1 << " " << pq2.size() - 1 << "\n";
//     } while (pq1.size() > 0);

//     cout << pq.top() << "\n";

//     for (int i = 0; i < pq.top().length(); i++)
//     {
//         ans.push_back(pq.top()[i] - '0');
//     }

//     return ans;
// }