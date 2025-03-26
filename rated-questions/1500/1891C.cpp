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
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    
    int l = 0, r = n-1, x = 0;
    int actions = 0;

    while(l < r){
        int can_add= min(v[r]-x, v[l]);
        actions += can_add;        

        if(can_add == v[l]){
            // quer dizer que eu vou remover todos e colocar no x
            x += v[l];            
            l++;
        } else if(can_add == v[r]-x){
            v[l] -= can_add;
            r--;
            actions++;
            x = 0;
        }
    }         

    if(v[l] == 1){
        actions ++;
    } else if(v[l] > 1){
        actions ++;
        int dst = v[l] - x;
        int missing = dst/2;
        actions += missing;
        if(dst % 2) actions ++;
    }


    cout << actions << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}