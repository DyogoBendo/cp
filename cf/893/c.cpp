#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<bool> marked(n + 1, false);
    vector<int> ans;

    int current = 1;
    int started = 1;

    while(started <= n){
        if(marked[started]) {
            started ++;
            continue;
        }
        current = started;
        while(current <= n){
            ans.push_back(current);
            marked[current] = true;
            current *= 2;            
        }        
        started ++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();

    }
}