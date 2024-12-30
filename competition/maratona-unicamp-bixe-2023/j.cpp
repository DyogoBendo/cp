#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll repeat = 0, initial, tam = 1;
vector<ll> b(3);

void solve1(){
    vector<ll> r(3);
    for (ll i = 1, j = b[0]; i <= 3; i++){
        if(r[b[j]] > 1) {
            repeat = i;
            initial = j;
            break;
        }
        r[b[j]]++;
    }

    ll j = initial;
    while(b[j] != j)
    {
        j = b[j]; 
        tam++;
    }
    
}

int main(){
    cin >> n;
    ll ans;
    for (ll &x : b) cin >> x;

    solve1();
    
    for (ll i = 0; i < min(n, (tam-repeat)); i++){
        ans = b[i];
    }


    
    cout << repeat << endl << ans << endl;
}