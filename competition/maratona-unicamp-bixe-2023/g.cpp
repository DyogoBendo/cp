#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, c;
    cin >> n >> c;
    vector<ll> ovos(n);

    for (ll &x : ovos) cin >> x;
    
    sort(ovos.begin(), ovos.end());

    ll count = 0;
    for (ll i = 0; i < n; i++){
        if(c >= ovos[i]){
            c -= ovos[i];
            count++;
            continue;
        }
        break;
    }

    cout << count << endl;
}