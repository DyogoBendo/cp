#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)((a).size()))
#define int long long

const int MAXN = 1e6 + 10;

void solve(){
    int a, b;
    char lixo;
    cin >> a >> lixo >> b;

    int n;
    ll x, mn, mx;
    bool found = false;
    for (n = b; n < MAXN; n+= b)
    {
        x = 1LL * a*n / b;

        mn = (n-1), mx = (1LL * (n) * (n-1)) / 2;

        if(mn <= x && x <= mx){
            found = true;
            break;
        }
    }

    if(!found){
        cout << "impossible" << endl;
        return;
    }


    ll curr = mx;
    vector<int> depth(n);
    vector<int> parent(n);    
    for (int i = n-1; i > 0; i--)
    {
        if(curr > x){
            int diff = min(curr - x, i - 1);

            curr -= diff;
            depth[i] = i - diff;
            parent[i-diff] == i;
        } else{
            depth[i] = i;
            parent[i]= i;
        }
    }

    cout << n << " " << n-1 << endl;
    for (int i = 1; i < n; i++)
    {        
        cout << i+1 << " " << parent[depth[i] - 1]+1 << endl;
    }
    
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
    return 0;
}