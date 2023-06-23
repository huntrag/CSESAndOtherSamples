#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    getline(cin>>ws,s);
    char prev;
    prev=s[0];

    int counter=0,mx=1;

    for(auto ch:s){
        if(ch==prev){
            counter++;
        }
        else{
            mx=max(counter,mx);
            counter=1;
        }
        prev=ch;
    }
    mx=max(counter,mx);
    cout<<mx;
    return 0;
}