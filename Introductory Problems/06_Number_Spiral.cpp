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
   int test; cin>>test;
   while(test--){
       ll row,col; cin>>row>>col;
       ll ans; 
       if(row>col){
           if(row%2==0){
               ans=(ll)row*row-col+1ll;
           }
           else{
               row--;
               ans=(ll)row*row+col;
           }
       }
       else{
           if(col%2==0){
               col--;
               ans=(ll)col*col+row; 
           }
           else{
               ans=(ll)col*col-row+1ll;
           }
       }

       cout<<ans<<"\n";
   }
   return 0;
}