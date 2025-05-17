#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

int div2(int x){
    int ans=  0;
    while(x > 1){
        ans++;
        x-= x/2;
    }
    return ans;
}

int calc(int x, int y){
    //cout << "x: " << x << " y: " << y << endl;
    return div2(x) + div2(y);
}

void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;    
        
    int ans = min({calc(n, min(b, m-b+1)), calc(min(a, n-a+1), m) })+1;
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}