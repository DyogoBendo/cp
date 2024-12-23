#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll MAX = 1e16 + 10;

void solve(){
    ll n, x;
    cin >> n >> x;

    ll soma = 0;
    ll maior = -1;
    ll a;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        soma += a;
        maior = max(a, maior);
    }    
    ll media = (soma / x) + (soma % x != 0);        
    cout << max(media, maior) << endl;
}

int main(){
    fastio
    
    int t;
    cin >> t;
    while(t--) solve();
}