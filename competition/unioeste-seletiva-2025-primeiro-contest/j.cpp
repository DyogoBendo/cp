#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int i = 0, j = 0, cnt = 0; 
    vector<int> app(200000 + 10, 0);
    int ans = 0;
    pair<int, int> range;

    while(j < n){        
        int x = v[j];        
        if(app[x] == 0){
            cnt ++;
        }
        app[x]++;

        if(cnt <= k){
            if(j - i + 1 > ans){
                ans = j - i + 1;
                range.first = i + 1;
                range.second = j + 1;
            }            
        } 
        else{
            while(cnt > k){                               
                if(app[v[i]] == 1) cnt--;
                app[v[i]] --;
                i++;
            }
            if(j - i + 1 > ans){
                ans = j - i + 1;
                range.first = i + 1;
                range.second = j + 1;
            }
        }
        j ++;
    }
    cout << ans << endl << range.first << " " << range.second << endl;
}

signed main(){
    flash;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}