#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    vector<int> a(n-1);
    for(auto &c:a){
        cin>>c;
    }

    vector<bool> check(n+1);
    check[0]=true;

    for(auto &c:a){
        check[c]=true;
    }
    int counter=0;
    for (auto c: check){
        if(!c){
            cout<<counter;
            return 0;
        }
        counter++;
    }

    return 0;
}