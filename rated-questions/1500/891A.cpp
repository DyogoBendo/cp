#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int one_cost= n+1;
    int qtd = 0;
    bool possible = false;

    for (int i = 0; i < n; i++)
    {
        int j = i;
        int curr =  v[i];
        if(curr == 1) qtd ++;
        while(j < n){
            curr = gcd(curr, v[j]);
            if(curr == 1) break;
            j++;
        }
        
        if(curr == 1){
            possible=true;
            one_cost = min(j - i, one_cost);
        }
    }
    
    int fix = n - qtd;
    if(qtd == 0) fix --;

    cout << ( possible ? one_cost + fix : -1) << endl;
}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}