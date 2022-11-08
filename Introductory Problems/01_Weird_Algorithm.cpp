#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin>>n;
    cout<<n<<" ";
    while(n!=1){
        n=n&1?(ll)n*3+1:(ll)n/2;
        cout<<n<<" ";
    }
    return 0;
}

