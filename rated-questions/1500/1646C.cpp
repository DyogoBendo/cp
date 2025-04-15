#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

vector<int> factorials;

void init(){
    int curr = 2;
    for (int i = 3; i < 15; i++)
    {
        curr *= i;
        factorials.push_back(curr);
    }
}

void solve(){
    int x;
    cin >> x;

    int ans = 64;

    for (int i = 0; i < 1<<15; i++)
    {
        int curr = x;
        int actions = 0;
        for (int j = 0; j < 15; j++)
        {
            if(i >> j & 1){
                if(factorials[j] > curr) break;
                curr -= factorials[j]; 
                actions ++;
            }
            if(curr < 0) break;
        }
        if(curr >= 0){
            actions += __builtin_popcountll(curr);
            ans = min(ans, actions);
        }
    }
    
    cout << ans << endl;

}


signed main(){
    init();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}