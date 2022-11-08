#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9+7
#define fi first
#define se second
 
int main(){
   #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt","w", stdout);
   #endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n; cin>>n;
   vi a(n);

   for(int i=0;i<n;i++){
       cin>>a[i];
   }

   ll mn=a[0],cnt=0;
   for(int i=0;i<n;i++){
       cnt+=(ll)mn-min(mn,a[i]);
       mn=(ll)max(mn,a[i]);
   }

   cout<<cnt;
   return 0;
}