#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, count = 0;
    cin >> n;
    vector<ll> crianca(n);

    for (ll &x : crianca) cin >> x;

    for(ll i = 0; i < n-1; i++)
    {
        if(crianca[i] == i+1) continue;
        for (ll j = i+1; j < n; j++)
        {
            if(crianca[j] == i+1){
                ll oldValue = crianca[i];
                crianca[i] = crianca[j];
                crianca[j] = oldValue;
                count++;
            }
        }
    }

    cout << count << endl;
    
}