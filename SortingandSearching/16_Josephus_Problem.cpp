#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second

struct llist
{
    int val;
    llist *front;
    llist *back;
};

llist *insert(llist *temp, int val)
{
    llist *cur = new llist();
    cur->val = val;
    cur->front = NULL;
    cur->back = temp;
    temp->front = cur;
    return cur;
}

llist *del(llist *cur)
{
    llist *prev = cur->back;
    llist *next = cur->front;
    prev->front = next;
    next->back = prev;
    free(cur);

    return next;
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
    llist *cur = new llist();
    cur->val = 1;
    cur->front = NULL;
    cur->back = NULL;
    llist *first = cur;

    for (int i = 2; i <= n; i++)
    {
        cur = insert(cur, i);
    }

    cur->front = first;
    first->back = cur;

    for (int i = 1; i <= n; i++)
    {
        cout << first->front->val << " ";
        first = del(first->front);
    }

    return 0;
}