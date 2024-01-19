// IMP | Floyd tortoise and hare
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
    }
    return 0;
}
// int findDuplicate(vector<int>& arr) {
//     int i = 0;
//     int n=arr.size();
//     while (i < n) {
//         int correct = arr[i] - 1;
//         if (arr[correct] != arr[i]) {
//             if(arr[correct]==correct+1){
//                 return arr[i];
//             }
//             swap(arr[i], arr[correct]);
//         }
//         else if(i==correct){
//             i++;
//         }
//         else{
//             return arr[i];
//         }
//     }
//     return 0;
// }

// Efficient approach is hare and tortoise
int findDuplicate(vector<int> &a)
{
    int tor = a[0];
    int hare = a[0];

    do
    {
        tor = a[tor];
        hare = a[a[hare]];
    } while (tor != hare);

    tor = a[0];
    while (tor != hare)
    {
        tor = a[tor];
        hare = a[hare];
    }

    return hare;
}