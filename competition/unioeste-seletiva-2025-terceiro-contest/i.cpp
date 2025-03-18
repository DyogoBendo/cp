#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long long

void solve(){
    int n;
    string s;
    cin >> n >> s;

    vector<int> blocks;    

    char lst = 'c';
    for (int i = 0; i < n; i++)
    {
        if(lst == s[i]) blocks.back()++;
        else blocks.push_back(1), lst = s[i];
    }        

    int ans = 0;    
    for(int i = 1; i < blocks.size(); i++){        
        int curr = blocks[i];
        int bef = blocks[i - 1];        
        ans = max(ans, min(curr, bef));
        if(i < blocks.size() - 1){
            int prox = blocks[i + 1];
            ans = max(ans, min(curr, prox));
            if(bef + prox >= curr) ans = max(ans, curr);                          
        }
    }
    cout << 2*ans << endl;
}

signed main(){
    fastio

    int t = 1;    
    while(t--) solve();
}