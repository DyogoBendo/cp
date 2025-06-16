#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    ll t1[3],t2[3];
    bool possivel = true;

    for(ll i = 0; i < 3; i++){
        cin>>t1[i];
    }

    for(ll i = 0; i < 3; i++){
        cin>>t2[i];
    }

    sort(t1,t1+3);
    sort(t2,t2+3);

    for(ll i = 0; i < 3; i++){
        if(t1[i]==t2[i]){
            possivel = true;
        }
        else{
            possivel = false;
            break;
        }
    }

    if (possivel){

        if((t1[0]*t1[0])+(t1[1]*t1[1])==(t1[2]*t1[2])){
        cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    else{
        cout<<"NO"<<endl;
    }


}