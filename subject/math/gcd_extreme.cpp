#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const int MAXN = 1e6 + 10;

vector<ll> phi(MAXN);

void init(){        
    vector<int> marked(MAXN);
    for (int i = 1; i < MAXN; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i < MAXN; i++)
    {
        if(!marked[i]){            
            for (int j = i; j < MAXN; j+=i)
            {
                marked[j] = 1;                
                phi[j] -= phi[j] / i;
            }            
        }
    }            
}

void solve(){
    vector<ll> ans(MAXN);

    for (int i = 1; i < MAXN; i++)
    {
        for (int j = 2*i; j < MAXN; j+=i)
        {
            ans[j] += phi[j/i] * i;
        }        
    }
    
    for (int i = 1; i < MAXN; i++)
    {
        ans[i] += ans[i-1];
    }    

    int n;
    cin >> n;
    

    while(n){                
        cout << ans[n] << endl;
        cin >> n;
    }
}


signed main(){
    //darvem;
    init();
    int t = 1;
    t = 1;

    while(t--) solve();
}