#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    int curr = 0, used = 0, mn = 0;
    for(int i = 0; i < n; i++){
        curr += v[i];
        mn = min(mn, v[i]);
        if(curr < 0){
            used ++;
            curr -= mn;
            mn = 0;
        }
    }

    if(used == 0){
        cout << "morete chapou: errou conta!" << endl;
    } else if(used > 1){
        cout << "morete chapou: ficou com saldo negativo!" << endl;
    } else{
        vector<int> ans;
        vector<int> calc(n+1);
        for(int i = n-1; i >= 0; i--){
            calc[i] = min(v[i], calc[i+1] + v[i]);
        }
        int curr = 0;
        for(int i = 0; i < n; i++){
            if(curr < 0) break;
            if(curr + calc[i+1] >= 0){
                ans.push_back(i+1);
            } 
            curr += v[i];
        }
        cout << ans.size() << endl;
        for(auto a : ans) cout << a << " ";
        cout << endl;
    }

}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}